#include<bits/stdc++.h>

using LL = long long;

int main()
{
	LL n, m;
	while(std::cin >> n >> m) {
		double ans = 0;
		for(int i = 1; i <= m; i++) {
			int x, d;
			std::cin >> x >> d;
			if(d == 0) {
				ans += x;
				continue;
			}
			if(d > 0) {
				ans += x + double(d) * (n-1) / 2;
			} else {
				int cnt;
				int xx = n/2;
				if(n%2) {
					cnt = xx*(xx+1);
				} else {
					cnt = xx*xx;
				}
				ans += x + double(cnt) * d / n;
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
