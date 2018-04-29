#include<bits/stdc++.h>

using LL = unsigned long long;

int main() 
{
	LL n, k, M, D;
	while(std::cin >> n >> k >> M >> D) {
		LL ans = 0;
		for(LL i = 1; i <= D; i++) {
			LL left = 0, right = M;
			while(left < right) {
				LL mid = (left + right + 1) / 2;
				LL num = (n / mid + k - 1) / k;
				if (num >= i) {
					left = mid;
				} else {
					right = mid - 1;
				}
			}
			if(left == 0) {
				continue;
			}
			LL v = (n / left + k - 1) / k;
			if(v > i) {
				continue;
			}
			ans = std::max(ans, v * left);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
