#include<bits/stdc++.h>

using LL = long long;

LL  val[100100], flag[100100];
LL left[100100], right[100100], sum[100100];

int main() 
{
	LL N, K;
	while(std::cin >> N >> K) {
		for(int i = 1; i <= N; i++) {
			std::cin >> val[i];
		}
		for(int i = 1; i <= N; i++) {
			std::cin >> flag[i];
		}

		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		memset(sum, 0, sizeof(sum));

		for(int i = 1; i <= N; i++) {
			left[i] = left[i-1] + val[i] * flag[i];
			sum[i] = sum[i-1] + val[i];
		}

		for(int i = N; i >= 1; i--) {
			right[i] = right[i+1] + val[i] * flag[i];
		}

		LL ans = 0;
		for(int i = 1; i+K-1 <= N; i++) {
			LL ret = sum[i+K-1] - sum[i-1] + left[i-1] + right[i+K];
			ans = std::max(ans, ret);
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
