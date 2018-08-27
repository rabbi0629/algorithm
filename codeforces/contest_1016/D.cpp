#include<bits/stdc++.h>

using LL = long long;

LL a[1000], b[1000];
LL c[200][200];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		LL sum1 = 0, sum2 = 0;
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			sum1 ^= a[i];
		}

		for(int i = 1; i <= m; i++) {
			std::cin >> b[i];
			sum2 ^= b[i];
		}

		if(sum1 != sum2) {
			std::cout << "NO" << std::endl;
			continue;
		}

		std::cout << "YES" << std::endl;
		for(int i = 1; i <= n; i++) {
			c[i][m] = a[i];
		}
		for(int i = 1; i <= m; i++) {
			c[n][i] = b[i];
		}
		c[n][m] = a[n]^b[m]^sum1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				std::cout << c[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
