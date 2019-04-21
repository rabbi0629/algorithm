#include<bits/stdc++.h>

std::vector<std::pair<int, int> > edge[200200];
int deg[200200];
int n, k, cnt;
std::vector<int> ans;

void dfs(int u, int fa, int c) {
    for(auto s:edge[u]) {
        if(s.first == fa) {
            continue;
        }
        c = c%cnt+1;
        ans[s.second] = c;
        dfs(s.first, u, c);
    }
}

int main()
{
    while(std::cin >> n >> k) {
        memset(deg, 0, sizeof(deg));
        for(int i = 1; i <= n; i++) {
            edge[i].clear();
        }

        for(int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            edge[u].push_back(std::make_pair(v,i-1));
            edge[v].push_back(std::make_pair(u,i-1));
            deg[u]++;
            deg[v]++;
        }

        std::sort(deg+1, deg+n+1, std::greater<int>());
        cnt = deg[k+1];
        std::cout << cnt << std::endl;
        ans = std::vector<int>(n-1);
        dfs(1,-1,0);
        for(auto s: ans) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
