#include<bits/stdc++.h>
using LL = long long;
const int maxn = 200100;

/*
 *题目要求: a[i] >= j && a[j] >= i 的对数。
 * 假设i < j, 则j的区间为[i+1, a[i]]区间内，并且a[j] >= i;
 * 用树状数组维护.
 */

std::vector<LL> bit[maxn];
int num[maxn], n;

void add(int index, LL x) {
	for(int i = index; i <= n; i += i&(-i)) {
		bit[i].push_back(x);
	}
}

LL query(int index, int x) {
	LL ans = 0;
	for(int i = index; i > 0; i -= i&(-i)) {
		int pos = std::lower_bound(bit[i].begin(), bit[i].end(), x) - bit[i].begin();
		ans += bit[i].size() - pos;
	}
	return ans;
}

int main()
{
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			bit[i].clear();
		}

		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			add(i, std::min(n, num[i]));
		}

		for(int i = 1; i <= n; i++) {
			std::sort(bit[i].begin(), bit[i].end());
		}

		LL ans = 0;

		for(int i = 1; i <= n; i++) {
			if(num[i] <= i) {
				continue;
			}
			ans += query(std::min(num[i], n), i) - query(i, i);
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
