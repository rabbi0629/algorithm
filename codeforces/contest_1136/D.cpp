#include<bits/stdc++.h>

int num[300300];
std::vector<int> edge[300300];
bool vis[300300];

int main()
{
    int n, m;
    while(std::cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
        }

        for(int i = 1; i <= n; i++) {
            edge[i].clear();
        }

        memset(vis, false, sizeof(vis));

        while(m--) {
            int u, v;
            std::cin >> u >> v;
            edge[u].push_back(v);
        }

        vis[num[n]] = true;
        int ans = 0;
        for(int i = n-1; i >= 1; i--) {
            int cnt = 0;
            for(auto v: edge[num[i]]) {
                if(vis[v]) {
                    cnt++;
                }
            }

            if(n-ans == i+cnt) {
                ans++;
            } else {
                vis[num[i]] = true;
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
