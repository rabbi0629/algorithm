#include<bits/stdc++.h>

int a[100100], sum[100100];

int main()
{
	int n, d;
	while(std::cin >> n >> d) {
		sum[0] = 0;
		for(int i = 1; i < n; i++) {
			std::cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}
		int ans = 1000000000;
		for(int i = d; i < n; i++) {
			ans = std::min(ans, sum[i] - sum[i-d]);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
