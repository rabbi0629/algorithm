#include<bits/stdc++.h>

using LL = long long;

int main()
{
	LL n, q;
	while(std::cin >> n >> q) {
		while(q--) {
			int x, y;
			std::cin >> x >> y;
			LL ans = 0;
			if((x+y)%2 == 0) {
				ans = (x-1)/2 * n/2 + (x-1 - (x-1)/2) * (n-n/2);
				if(x%2) {
					ans += y-y/2;
				} else {
					ans += y/2;
				}
			} else {
				if(n%2) {
					ans += n*n/2+1;
				} else {
					ans += n*n/2;
				}

				ans += (x-1)/2 * (n-n/2) + (x-1 - (x-1)/2) * n/2;
				if(x%2) {
					ans += y/2;
				} else {
					ans += y-y/2;
				}
			}
			std::cout << ans << std::endl;
		}
	}
	return 0;
}
