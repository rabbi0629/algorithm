#include<bits/stdc++.h>

const int MAXN= 200100;

struct BIT {
	int n, c[2*MAXN];
	void init(int _n) {
		this->n = _n;
		memset(c, 0, sizeof(c));
	}

	void add(int p, int x) {
		for(int i = p; i <= n; i += i&(-i)) {
			c[i] += x;
		}
	}

	int get(int p) {
		int ans = 0;
		for(int i = p; i >= 1; i -= i&(-i)) {
			ans += c[i];
		}
		return ans;
	}
}bit;

int num[MAXN];

long long solve(int n, int m) {
	bit.init(2*n+1);
	bit.add(n+1, 1);
	long long ans = 0;
	int s = n+1;
	for(int i = 1; i <= n; i++) {
		if(num[i] <= m) {
			s++;
		}else {
			s--;
		}
		bit.add(s, 1);
		ans += bit.get(s);
	}
	return ans;
}

int main() 
{
	int n, m;
	while(std::cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}

		std::cout << solve(n, m) - solve(n, m-1) << std::endl;
	}
	return 0;
}
