#include<bits/stdc++.h>

using LL = long long;

int main()
{
	int n;
	while(std::cin >> n) {
		std::string a, b;
		std::cin >> a >> b;


		LL sum0 = 0, sum1 = 0;

		LL sum2 = 0, sum3 = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] == '0') {
				sum0++;
			} else {
				sum1++;
			}

			if(b[i] == '0') {
				if(a[i] == '0') {
					sum2++;
				} else {
					sum3++;
				}
			}
		}

		if(sum0 == 0 || sum1 == 0) {
			std::cout << 0 << std::endl;
			continue;
		}

		LL ans = 0;
		for(int i = 0; i < n; i++) {
			if(b[i] == '0') {
				if(a[i] == '0') {
					ans += sum1;
				} else {
					ans += sum0;
				}
			}
		}
		std::cout << ans - sum2*sum3 << std::endl;
	}
	return 0;
}
