#include<bits/stdc++.h>

using LL = long long;

LL num[110], du[110];
std::vector<LL> edge[110];
std::vector<LL> ans;

void dfs(int u) {
	ans.push_back(u);
	du[u] = -1;
	for(auto v : edge[u]) {
		if(du[v] == -1) {
			continue;
		}
		dfs(v);
	}
}

int main()
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}
		std::sort(num+1, num+n+1);
		memset(du, 0, sizeof(du));

		for(int i = 1; i < n; i++) {
			for(int j = i+1; j <= n; j++) {
				if(num[j] == 3 * num[i]) {
					edge[j].push_back(i);
					du[i]++;
				}

				if(num[j] == 2 * num[i]) {
					edge[i].push_back(j);
					du[j]++;
				}
			}
		}

		int s = 1;
		for(int i = 1; i <= n; i++) {
			if(du[i] == 0) {
				s = i;
				break;
			}
		}

		ans.clear();
		dfs(s);

		for(auto s : ans) {
			std::cout << num[s]  << " " ;
		}
		std::cout << std::endl;
	}
	return 0;
}
