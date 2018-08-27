#include<bits/stdc++.h>

using LL = long long;
std::map<LL,LL> mp;
LL ans[200200];

int main()
{
	int n;
	while(std::cin >> n) {
		mp.clear();
		for(int i = 1; i <= n; i++) {
			LL x, y;
			std::cin >> x >> y;
			mp[x]++;
			mp[y+1]--;
		}

		memset(ans, 0, sizeof(ans));
		LL pre = 0;
		LL k = 0;
		for(auto it:mp) {
			ans[k] += it.first-pre;
			pre = it.first;
			k += it.second;
		}

		for(int i = 1; i <= n; i++) {
			std::cout << ans[i] << " ";
		}

		std::cout << std::endl;
	}
	return 0;
}
