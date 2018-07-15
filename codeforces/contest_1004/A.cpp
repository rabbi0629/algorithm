#include<bits/stdc++.h>

using LL = long long;

LL num[1000];

int main() {
	LL n, d;
	while(std::cin >> n >> d) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}
		int ans = 2;
		for(int i = 2; i <= n; i++) {
			int tmp = num[i] - num[i-1];
			if(tmp > 2*d) {
				ans += 2;
			}
			if(tmp == 2*d) {
				ans++;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
