#include<bits/stdc++.h>

using LL = long long;

int num[300300];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		std::map<int, int> mp;
		int sum = 0;
		LL ans = 0;
		mp[0] = 1;
		bool has = false;
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			if(num[i] < m) {
				sum--;
			} else if(num[i] > m) {
				sum++;
			}
			if(num[i] == m) {
				has = true;
			}

			if(has) {
				ans += mp[sum] + mp[sum-1];
			} else {
				mp[sum]++;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
