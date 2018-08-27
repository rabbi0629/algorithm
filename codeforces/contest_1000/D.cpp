#include<bits/stdc++.h>

using LL = long long;

const LL mod = 998244353LL;

LL fac[1010], inv[1010], C[1010][1010];
LL data[1010], dp[1010];

LL calc(LL n, LL m) {
	if(m < 0 || m > n) {
		return 0;
	}
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main()
{
	fac[0] = inv[1] = inv[0] = 1LL;
	for(LL i = 1; i <=1003; i++) {
		fac[i] = fac[i-1]*i%mod;
	}

	for(LL i = 2; i <= 1003; i++) {
		inv[i] = (mod-mod/i)*inv[mod%i]%mod;
	}

	for(int i = 1; i <= 1003; i++) {
		inv[i] = inv[i] * inv[i-1] % mod;
	}

	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> data[i];
		}

		memset(dp, 0, sizeof(dp));
		dp[n+1] = 1LL;
		for(int i = n; i >= 1; i--) {
			if(data[i] <= 0) {
				continue;
			}
			for(int j = i+1+data[i]; j <= n+1; j++) {
				dp[i] += calc(j-i-1, data[i]) * dp[j];
				dp[i] %= mod;
			}
		}

		LL sum = 0;
		for(int i = 1; i <= n; i++) {
			sum += dp[i];
			sum %= mod;
		}

		std::cout << sum << std::endl;
	}
	return 0;
}
