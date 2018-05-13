#include<bits/stdc++.h>

using LL = long long;

int main()
{
	int n, a, b;
	while(std::cin >> n >> a >> b) {
		std::map<LL, LL> mp1;
		std::map<std::pair<LL, LL>, LL> mp2;
		LL ans = 0;
		for(int i = 1; i <= n; i++) {
			LL x, vx, vy;
			std::cin >> x >> vx >> vy;
			mp1[a*vx-vy]++;
			mp2[std::make_pair(vx, vy)]++;
			ans += mp1[a*vx-vy] - mp2[std::make_pair(vx, vy)];
		}

		std::cout << ans * 2 << std::endl;
	}
	return 0;
}
