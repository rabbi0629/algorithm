#include<bits/stdc++.h>

double value[10010];

int main()
{
	int n, k;
	while(std::cin >> n >> k) {
		for(int i = 1; i <= n; i++) {
			double xx;
			std::cin >> xx;
			value[i] = value[i-1] + xx;
		}

		double ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i+k-1; j <= n; j++) {
				double xx = (value[j] - value[i-1]) / (j-i+1);
				ans = std::max(ans, xx);
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
