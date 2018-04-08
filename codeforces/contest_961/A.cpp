#include<bits/stdc++.h>

int cnt[10000];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		memset(cnt, 0, sizeof(cnt));
		for(int i =1 ; i <= m; i++) {
			int xx;
			std::cin >> xx;
			cnt[xx]++;
		}
		int ans = cnt[1];
		for(int i = 1; i <= n; i++) {
			ans = std::min(ans, cnt[i]);
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
