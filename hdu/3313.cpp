#include<bits/stdc++.h>

const int maxn = 100100;
const int maxm = 300300;

int head[maxn], tot;
int dep[maxn], vis[maxn], pre[maxn], mark[maxn];

struct Edge{
    int next;
    int from;
    int to;
}edge[2*maxm];

void add_edge(int u, int v) {
    edge[tot] = Edge{head[u], u, v}; head[u] = tot++;
    edge[tot] = Edge{head[v], v, u}; head[v] = tot++;
}


int main()
{
    int n, m;
    while(std::cin >> n >> m) {
        memset(head, -1, sizeof(head));
        tot++;

        for(int i = 1; i <= m; i++) {
            int u, v;
            std::cin >> u >> v;
            add_edge(u, v);
        }

        int S, T;
        std::cin >> S >> T;

        std::cout << "debug " << std::endl;

        std::queue<int> q;
        memset(dep, -1, sizeof(dep));
        memset(pre, -1, sizeof(pre));
        dep[S] = 0;
        q.push(S);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].to;
                if(dep[v] == -1) {
                    dep[v] = dep[u]+1;
                    pre[v] = u;
                    q.push(v);
                }
            }
        }

        if(dep[T] == -1) {
            std::cout << 0 << std::endl;
            continue;
        }

        int u = T;
        memset(mark, 0, sizeof(mark));
        while(u != -1) {
            mark[u] = 1;
            u = pre[u];
        }

        int ans = 0;
        u = S;

        memset(dep, -1, sizeof(dep));
        dep[S] = 0;

        std::cout << "debug " << std::endl;

        while(u != T) {
            q.push(u);
            std::cout << "debug " << u << std::endl;

            int id = u;
            while(!q.empty()) {
                int p = q.front();
                q.pop();
                for(int i = head[p]; i != -1;i = edge[i].next) {
                    int v = edge[i].to;
                    if(dep[v] == -1) {
                        dep[v] = dep[u]+1;

                        if(mark[v]) {
                            if(dep[v] > dep[id]) {
                                id = v;
                            }
                        }
                    }
                    q.push(v);
                }
            }
            u = id;
            ans++;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
