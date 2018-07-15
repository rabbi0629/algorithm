#include<bits/stdc++.h>

int n, m, k;
std::vector<std::pair<int, int> > edge[300300];
std::vector<int> pre[300300];
int dist[300300];

int main() 
{
	while(std::cin >> n >> m >> k) {
		for(int i = 1; i <= n; i++) {
			edge[i].clear();
			pre[i].clear();
		}

		for(int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			edge[u].push_back(std::make_pair(v, i));
			edge[v].push_back(std::make_pair(u, i));
		}
		std::fill(dist, dist+300000, 10000000);
		dist[1] = 0;
		std::queue<int> Q;
		Q.push(1);
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for(auto tmp : edge[u]) {
				if(dist[tmp.first] > dist[u]+1) {
					dist[tmp.first] = dist[u]+1;
					Q.push(tmp.first);
				}
			}
		}

		for(int i = 2; i <= n; i++) {
			for(auto s : edge[i]) {
				if(dist[s.first]+1 == dist[i]) {
					pre[i].push_back(s.second);
				}
			}
		}

		std::vector<int> f(300000);
		std::vector<std::string> result;
		for(int i = 1; i <= k; i++) {
			std::string s(m, '0');
			for(int j = 2; j <= n; j++) {
				s[pre[j][f[j]]-1] = '1';
			}
			result.push_back(s);
			bool ok = false;
			for(int j = 2; j <= n; j++) {
				if(f[j]+1 < int(pre[j].size())) {
					ok = true;
					f[j]++;
					break;
				} else {
					f[j] = 0;
				}
			}
			if(!ok) {
				break;
			}
		}
		std::cout << result.size() << std::endl;
		for(auto s:result) {
			std::cout << s << std::endl;
		}
	}
	return 0;
}
