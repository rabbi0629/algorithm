#include<bits/stdc++.h>

using LL = long long;

LL powers[100];

int main()
{
	LL x = 1LL;
	std::map<LL, int> mp;
	mp[1] = 0;
	for(int i = 1; i <= 40; i++) {
		x <<= 1;
		mp[x] = i;
	}

	int n, m;
	while(std::cin >> n >> m) {
		memset(powers, 0, sizeof(powers));
		for(int i = 1; i <= n; i++) {
			LL xx;
			std::cin >> xx;
			powers[mp[xx]]++;
		}

		while(m--) {
			LL xx;
			std::cin >> xx;

			LL cnt[100];
			std::memcpy(cnt, powers, sizeof(powers));
			LL ans = 0;
			for(int i = 29; i >= 0 && xx > 0; i--) {
				LL c = std::min(cnt[i], xx/(1LL<<i));
				ans += c;
				xx -= c* (1LL<<i);
			}
			if(xx == 0) {
				std::cout << ans << std::endl;
				continue;
			} 
			std::cout << -1 << std::endl;
		}
	}
	return 0;
}
