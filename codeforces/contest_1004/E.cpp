#include<bits/stdc++.h>

const int maxn = 300300;
const int INF = 1000000000;

std::vector<std::pair<int, int> > edge[maxn];
int fa[maxn], dis[maxn], dep[maxn];
bool vis[maxn];
int n, d;

void bfs(int s) {
	memset(fa, -1, sizeof(fa));
	memset(dis, 0, sizeof(dis));
	std::queue<int> Q;
	dis[s] = 0;
	Q.push(s);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(auto s : edge[u]) {
			int v = s.first;
			if(v == fa[u]) {
				continue;
			}
			dis[v] = dis[u] + s.second;
			fa[v] = u;
			Q.push(v);
		}
	}
}

void dfs(int u, int f) {
	for(auto s : edge[u]) {
		int v = s.first;
		if(vis[v] || v == f) {
			continue;
		}
		dfs(v, u);
		dep[u] = std::max(dep[u], dep[v] + s.second);
	}
}

int main()
{
	while(std::cin >> n >> d) {
		for(int i = 1; i <= n; i++) {
			edge[i].clear();
		}
		int st = -1, ed = -1;
		for(int i = 1; i < n; i++) {
			int u, v, w;
			std::cin >> u >> v >> w;
			edge[u].push_back(std::make_pair(v, w));
			edge[v].push_back(std::make_pair(u, w));
		}

		bfs(1);
		int mx = -1;
		for(int i = 1; i <= n; i++) {
			if(mx < dis[i]) {
				mx = dis[i];
				st = i;
			}
		}

		//for(int i = 1; i <= n; i++) {
			//std::cout << dis[i] << " ";
		//}
		//std::cout << std::endl;

		bfs(st);
		mx = -1;
		for(int i = 1; i <= n; i++) {
			if(mx < dis[i]) {
				mx = dis[i];
				ed = i;
			}
		}

		//std::cout << "debug1: " << st << " " << ed << std::endl;

		std::vector<int> diamlist;
		memset(vis, false, sizeof(vis));
		for(int i = ed; i != -1; i = fa[i]) {
			diamlist.push_back(i);
			vis[i] = 1;
		}

		int ans = INF;
		int max_h = 0;
		memset(dep, 0, sizeof(dep));
		for(int i = 0; i < int(diamlist.size()); i++) {
			int x1;
			if(i-d+1 < 0) {
				x1 = 0;
			} else {
				x1 = dis[ed] - dis[diamlist[i-d+1]];
			}
			x1 = std::max(x1, dis[diamlist[i]]);
			ans = std::min(ans, x1);
			dfs(diamlist[i], -1);
			max_h = std::max(max_h, dep[diamlist[i]]);
			ans = std::max(ans, max_h);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
