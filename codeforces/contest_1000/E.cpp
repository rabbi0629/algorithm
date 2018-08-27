#include<bits/stdc++.h>

const int maxn = 300300;

int n, m;
std::vector<int> edge[maxn], scc_edge[maxn];
int low[maxn], dfn[maxn], stack[maxn], belong[maxn];
int top, indexx, scc;
bool instack[maxn];
int dist[maxn];

void tarjan(int u, int pre) {
	low[u] = dfn[u] = ++indexx;
	stack[top++] = u;
	instack[u] = true;
	for(auto v:edge[u]) {
		if(v == pre) {
			continue;
		}
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = std::min(low[u], low[v]);
		} else if(instack[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]) {
		scc++;
		int v;
		do {
			v = stack[--top];
			belong[v] = scc;
			instack[v] = false;
		} while(u != v);
	}
}

void dfs(int u,int pre) {
	for(auto v:scc_edge[u]) {
		if(v == pre) {
			continue;
		}
		dist[v] = dist[u]+1;
		dfs(v, u);
	}
}

void solve() {
	for(int i = 1; i <= n; i++) {
		edge[i].clear();
		scc_edge[i].clear();
	}

	for(int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	std::fill(instack, instack+n+1, false);
	memset(belong, 0, sizeof(belong));
	indexx = top = scc = 0;
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			tarjan(i, -1);
		}
	}


	for(int i = 1; i <= n; i++) {
		for(auto j:edge[i]) {
			if(i < j && belong[i] != belong[j]) {
				scc_edge[belong[i]].push_back(belong[j]);
				scc_edge[belong[j]].push_back(belong[i]);
			}
		}
	}

	memset(dist, -1, sizeof(dist));
	dist[1] = 0;
	dfs(1, -1);
	int id1 = -1, maxx = -1;
	for(int i = 1; i <= scc; i++) {
		if(dist[i] > maxx) {
			maxx = dist[i];
			id1 = i;
		}
	}

	memset(dist, -1, sizeof(dist));
	dist[id1] = 0;
	dfs(id1, -1);
	maxx = -1;
	for(int i = 1; i <= scc; i++) {
		if(dist[i] > maxx) {
			maxx = dist[i];
		}
	}

	std::cout << maxx << std::endl;
}

int main()
{
	while(std::cin >> n >> m) {
		solve();
	}
	return 0;
}
