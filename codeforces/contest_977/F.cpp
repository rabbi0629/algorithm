#include<bits/stdc++.h>

int num[300300], next[300300], dp[300300];

int main()
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >>num[i];
			dp[i] = 1;
		}

		memset(next, -1, sizeof(next));
		std::map<int, int> mp;
		for(int i = n ; i >= 1; i--) {
			int x = num[i] + 1;
			if(mp.find(x) != mp.end()) {
				next[i] = mp[x];
				dp[i] = dp[mp[x]] + 1;
			}
			mp[num[i]] =i;
		}

		int max_len = 1, id = 1;
		for(int i = 1; i <= n; i++) {
			if(dp[i] > max_len) {
				max_len = dp[i];
				id = i;
			}
		}

		std::cout << max_len << std::endl;
		for(int i = id; i != -1; i = next[i]) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
