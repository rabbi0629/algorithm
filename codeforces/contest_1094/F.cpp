#include<bits/stdc++.h>

std::vector<int> edge[200200];
int n;
int dep[200200], fa[200200];

void dfs(int u, int p) {
    for(auto v: edge[u]) {
        if(v == p || dep[v] != -1) {
            continue;
        }

        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs(v, u);
    }
}

int main()
{
    while(std::cin >> n) {
        for(int i = 1; i <= n; i++) {
            edge[i].clear();
        }

        for(int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        memset(dep, -1, sizeof(dep));
        memset(fa, -1, sizeof(fa));
        dep[1] = 0;
        dfs(1, 1);

        int idx1 = -1, maxDep = -1;
        for(int i = 1; i <= n; i++) {
            if(dep[i] > maxDep) {
                maxDep = dep[i];
                idx1 = i;
            }
        }

        memset(dep, -1, sizeof(dep));
        memset(fa, -1, sizeof(fa));
        dep[idx1] = 0;
        dfs(idx1, idx1);

        int idx2 = -1;
        maxDep = -1;
        for(int i = 1; i <= n; i++) {
            if(dep[i] > maxDep) {
                maxDep = dep[i];
                idx2 = i;
            }
        }

        int ans = maxDep;
        std::queue<int> q;
        memset(dep, -1, sizeof(dep));

        for(int i = idx2; i != -1; i = fa[i]) {
            q.push(i);
            dep[i] = 0;
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v:edge[u]) {
                if(dep[v] != -1) {
                    continue;
                }
                dep[v] = dep[u]+1;
                q.push(v);
            }
        }

        int idx3 = -1;
        maxDep =-1;
        for(int i = 1; i <= n; i++) {
            if(i == idx1 || i == idx2) {
                continue;
            }

            if(maxDep < dep[i]) {
                maxDep = dep[i];
                idx3 = i;
            }
        }

        ans += maxDep;
        std::cout << ans << std::endl;
        std::cout << idx1 << " " << idx2 << " " << idx3 << std::endl;

    }
    return 0;
}
