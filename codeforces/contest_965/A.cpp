#include<bits/stdc++.h>

using LL = long long;

int main() {
	LL k, n, s, p;
	while(std::cin >> k >> n >> s >> p) {
		LL s1 = n / s;
		if(n%s) {
			s1++;
		}
		s1 *= k;
		LL ans = s1 / p;
		if(s1%p) {
			ans++;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
