#include<bits/stdc++.h>

const int maxn = 100000;

int n, m;
int low[maxn], dfn[maxn],Stack[maxn], Index, Top;
int head[maxn], tot;
bool Instack[maxn];
int brigde;

struct Edge{
    int next;
    int from;
    int to;
    bool cut;
    int val;
}edge[3000200];

void addedge(int u, int v, int val) {
    edge[tot] = Edge{head[u], u, v, false, val}; head[u] = tot++;
    edge[tot] = Edge{head[v], v, u, false, val}; head[v] = tot++;
}

void Tarjan(int u, int pre) {
    Stack[Top++] = u;
    Instack[u] = true;
    low[u] = dfn[u] = ++Index;
    int pre_cnt = 0;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(v == pre && pre_cnt == 0) {
            pre_cnt++;
            continue;
        }

        if(!dfn[v]) {

            Tarjan(v, u);
            low[u] = std::min(low[u], low[v]);

            if(low[v] > dfn[u]) {
                brigde++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }

        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    Instack[u] = false;
    Top--;
}

int main()
{
    while(std::cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        }

        memset(head, -1, sizeof(head)); tot = 0;
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            addedge(u, v, w);
        }

        memset(low, 0 , sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        Index = 0;
        Top = 0;
        memset(Instack, false, sizeof(Instack));
        brigde = 0;

        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(dfn[i] == 0) {
                count++;
                Tarjan(i, i);
            }
        }

        if(count > 1) {
            std::cout << 0 << std::endl;
            continue;
        }

        if(brigde == 0) {
            std::cout << -1 << std::endl;
            continue;
        }

        int ans = 0xfffffff;
        for(int i = 0; i < tot; i+= 2) {
            if(edge[i].cut) {
                ans = std::min(ans, edge[i].val);
            }
        }

        if(ans == 0) {
            ans++;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}


