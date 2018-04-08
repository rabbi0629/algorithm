#include<bits/stdc++.h>

using LL = long long;
const int maxn = 1011000;
const LL mod = 1e9+7;

int seed = 29, n;
char str[maxn];
LL base[maxn], Hash[maxn];
int ans[maxn];


void init() {
	memset(base, 0, sizeof(base));
	base[0] = 1;
	for(int i = 1; i < maxn; i++) {
		base[i] = base[i-1]*seed;
		base[i] %= mod;
	}
}

void init_hash() {
	memset(Hash, 0, sizeof(Hash));
	for(int i = n-1; i >= 0; i--) {
		Hash[i] = Hash[i+1] * seed + str[i] - 'a' + 1;
		Hash[i] %= mod;
	}
}

LL get_hash(int i, int len) {
	auto ans = Hash[i] - Hash[i+len] * base[len];
	ans %= mod;
	if(ans < 0) ans += mod;
	return ans;
}

int main() 
{
	init();
	while(std::cin >> n) {
		std::cin >> str;
		init_hash();

		memset(ans, -1, sizeof(ans));

		int cur = -1;
		for(int i = (n-1)/2; i >= 0; i--) {
			cur += 2;
			if(2 * i == n - 1) {
				cur = -1;
			}
			while(cur != -1 && get_hash(i, cur) != get_hash(n -i - cur, cur)) cur -= 2;
			ans[i] = cur;
		}

		for(int i = 0; i <= (n-1)/2; i++) {
			std::cout << ans[i] << " ";
		}

		std::cout << std::endl;
	}
	return 0;
}


