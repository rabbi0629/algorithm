#include<bits/stdc++.h>

std::vector<int> edge[300300], col[300300];
int vis[300300], tot;

void dfs(int u) {
	if(vis[u]) {
		return;
	}
	vis[u] = 1;
	col[tot].push_back(u);
	for(auto s : edge[u]) {
		dfs(s);
	}
}

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) {
			edge[i].clear();
			col[i].clear();
		}

		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		tot = 0;

		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				tot++;
				dfs(i);
			}
		}

		int ans = 0;
		for(int i = 1; i <= tot; i++) {
			int ok = col[i].size() > 2;
			for(auto s : col[i]) {
				ok &= (edge[s].size() == 2);
			}
			if(ok) {
				ans++;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
