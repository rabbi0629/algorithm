#include<bits/stdc++.h>

using LL = long long;
const LL mod = 1000000009LL;

LL  pow_mod(LL a, LL b) {
    LL ret = 1;
    a = a%mod;
    while(b) {
        if(b&1) ret = (ret*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ret;
}


LL inv(LL x) {
	return pow_mod(x, mod - 2);
}

char str[100100];

int main()
{
	LL n, a, b, k;
	while(std::cin >> n >> a >> b >> k) {
		std::cin >> str;
		LL result = 0;
		for(int i = 0; i < k; i++) {
			LL sign = (str[i] == '-') ? - 1 : 1;
			result += sign * pow_mod(a, n-i) * pow_mod(b, i) % mod;
			result = (result % mod + mod) % mod;
		}

		LL N = (n+1) / k;
		LL ans = 0;
		LL MUL = pow_mod(b * inv(a) % mod, k);

		if(MUL == 1) {
			ans += N * result;
		} else {
			ans += result * (pow_mod(MUL, N) - 1) % mod * inv(MUL - 1) %mod;
		}
		ans = (ans % mod + mod) % mod;
		std::cout << ans << std::endl;
	}
	return 0;
}


