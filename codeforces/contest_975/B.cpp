#include<bits/stdc++.h>

using LL = long long;

LL a[100], b[100];

int main()
{
	for(int i = 0; i < 14; i++) {
		std::cin >> a[i];
	}

	LL ans = 0;

	for(int i = 0; i < 14; i++) {
		if(a[i] > 0) {
			for(int j = 0; j < 14; j++) {
				b[j] = a[j];
			}

			int num = b[i];
			b[i] = 0;
			int avg = num / 14;
			for(int j = 0; j < 14; j++) {
				b[j] += avg;
			}

			int mod = num % 14;
			for(int j = (i+1)%14; mod > 0; j = (j+1)%14) {
				b[j] ++;
				mod --;
			}

			LL cnt = 0;
			for(int j = 0; j < 14; j++) {
				if(b[j] % 2 == 0) {
					cnt += b[j];
				}
			}
			ans = std::max(ans, cnt);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
