#include<bits/stdc++.h>

int road[1010][1010];
int dis[2][1010], n, m, s, t;
std::vector<int> edge[1010];

void bfs(int src, int id) {

	std::fill(dis[id], dis[id] + 1010, -1);
	dis[id][src] = 0;
	std::queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for(auto u:edge[tmp]) {
			if(dis[id][u] == -1 || dis[id][u] > dis[id][tmp] + 1) {
				dis[id][u] = dis[id][tmp] + 1;
				q.push(u);
			}
		}
	}
}

int main()
{
	while(std::cin >> n >> m >> s >> t) {
		memset(road, 0, sizeof(road));
		for(int i = 1; i <= n; i++) {
			edge[i].clear();
		}
		for(int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			road[u][v] = road[v][u] = 1;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		bfs(s, 0);
		bfs(t, 1);

		int dist  = dis[0][t], ans = 0;

		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int new_dis = std::min(dis[0][i] + dis[1][j] + 1, dis[0][j] + dis[1][i] + 1);
				if(dist <= new_dis) {
					ans++;
				}
			}
		}

		std::cout << ans - m << std::endl;
	}
	return 0;
}
