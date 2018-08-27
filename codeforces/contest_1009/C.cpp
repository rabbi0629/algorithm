#include<bits/stdc++.h>

using LL = long long;
using LD = long double;

int main()
{
	LL n, m;
	while(std::cin >> n >> m) {
		LL ans = 0;
		LL sum1 = 0, sum2 = 0;
		for(int i =0; i < n; i++) {
			sum1 += i;
			sum2 += std::abs(i-n/2);
		}


		for(int i = 1; i <= m; i++) {
			LL x, d;
			std::cin >> x >> d;
			ans += x*n + std::max(d*sum1, d*sum2);
		}
		printf("%.10Lf\n", ans /((LD)n));
	}
	return 0;
}
