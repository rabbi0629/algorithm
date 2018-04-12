#include<bits/stdc++.h>

using LL = long long;
const LL INF = 1000000000000000000LL;
const int maxn = 1001000;

int vis[100], mu[100], prime[100], tot;
std::vector<LL> pw[100];

LL power(LL a, LL x) {
	LL ans = 1;
	while(x) {
		if(x % 2) {
			ans = ans * a;
		}
		a = a * a;
		x >>= 1;
	}
	return ans;
}

LL calc(LL mi, LL des) {
	//std::cout << "debug calc " << mi << " " << L << " " << R << std::endl;

	if(mi == 2) {
		LL ans = (LL)sqrt(des + 0.5);
		//std::cout << "ans: " << ans << std::endl;
		return ans;
	}


	int left = -1, right = pw[mi].size() - 1;
	while(left < right) {
		LL mid = (left + right + 1) / 2;
		if(pw[mi][mid] > des) {
			right = mid - 1;
		} else {
			left = mid;
		}
	}
	return left+1;
}

void init() {

	for(int i = 0; i < 70; i++) {
		pw[i].clear();
	}

	tot = 0;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1; mu[1] = 1;
	for(int i = 2; i < 100; i++) {
		if(!vis[i]) {
			prime[tot++] = i;
			mu[i] = -1;
		}

		for(int j = 0; j < tot && i * prime[j] < 100; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}

	for(LL i = 2; i <= 1000000; i++) {
		LL now = i * i;
		for(int j = 3; j <= 60; j++) {
			if(now > INF / i) break;
			now *= i;
			pw[j].push_back(now);
		}
	}
}

int main()
{

	init();
	LL L, R;
	int Q;
	std::cin >> Q;
	while(Q--) {
		std::cin >> L >> R;
		LL ans = 0;
		if(L == 1) {
			ans++;
			L++;
		}

		if(L <= R) {
			for(int i = 2; i <= 60; i++) {
				//LL tmp1 = calc(i, R);
				//LL tmp2 = calc(i, L - 1);
				
				if(mu[i]) {
					auto tmp = -mu[i] * (calc(i, R) - calc(i, L - 1));
					ans += tmp;
					//std::cout << "i: " << i << " " << tmp << " " << calc(i, R) << " " << calc(i, L-1) << std::endl;
				}

				//std::cout << "i: " << i << " " << tmp1 << " " << tmp2 << " " << mu[i] << std::endl;
			}
		}
		std::cout << ans << std::endl;

	}
	return 0;
}
