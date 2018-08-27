#include<bits/stdc++.h>

int flag[10010];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		memset(flag, 0, sizeof(flag));
		for(int i = 1; i <= n; i++) {
			int l, r;
			std::cin >> l >> r;
			for(int i = l; i <= r; i++) {
				flag[i] = 1;
			}
		}
		std::vector<int> ans;
		for(int i = 1; i <= m; i++) {
			if(flag[i] == 0) {
				ans.push_back(i);
			}
		}
		std::cout << ans.size() << std::endl;
		for(auto s:ans) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
