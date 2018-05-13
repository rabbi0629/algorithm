#include<bits/stdc++.h>

using LL = long long;

LL num[300300], pre[300300], q[300300];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			pre[i] = pre[i-1] + num[i];
		}

		for(int i = 1; i <= m; i++) {
			std::cin >> q[i];
		}

		for(int i = 1; i <= m; i++) {
			int pos = std::lower_bound(pre+1, pre+n+1, q[i]) - pre;
			std::cout << pos << " " << q[i] - pre[pos-1] << std::endl;
		}
	}
	return 0;
}
