#include<bits/stdc++.h>

const int maxn = 100100;
int head[maxn], tot, dep[maxn], cur[maxn], queue[maxn*2], gap[maxn];
int start,end;
int n, m;

struct Edge {
    int next,to,flow;
}edge[maxn*4];

void add_edge(int u,int v, int flow) {
    edge[tot]=Edge{head[u],v,flow}; head[u] = tot++;
    edge[tot]=Edge{head[v],u,0}; head[v] = tot++;
}

void bfs() {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    int front = 0, rear = 0;
    dep[end] = 0; queue[front++] = end;gap[0]++;
    while(front != rear) {
        int u = queue[rear++];
        for(int i = head[u]; ~i; i = edge[i].next) {
            if(dep[edge[i].to] == -1) {
                dep[edge[i].to] = dep[u]+1;
                queue[front++] = edge[i].to;
                gap[dep[edge[i].to]]++;
            }
        }
    }
}

int dfs(int now, int cap) {
    if(now == end) {
        return cap;
    }

    int flow, cost = 0;
    for(int i = head[now]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(edge[i].flow > 0 && dep[v]+1 == dep[now] && (flow = dfs(v, std::min(cap-cost, edge[i].flow)))>0) {
            edge[i].flow -= flow;
            edge[i^1].flow += flow;
            cost += flow;

            if(cost == cap) {
                return cost;
            }
        }
    }

    if (--gap[dep[now]] == 0) {
        dep[start] = n+1;
    }

    gap[++dep[now]]++;
    return cost;
}

int maxFlow() {
    int ans = 0;
    bfs();
    while(dep[start] < n) {
        ans += dfs(start, 0xfffffff);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d", &n,&m);
        int minn = 10000000,maxx=-100000000;
        start = -1, end = -1;
        for(int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(minn > x) {
                minn = x;
                start = i;
            }

            if(maxx < x) {
                maxx = x;
                end = i;
            }
        }

        memset(head, -1, sizeof(head));
        tot = 0;

        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u,&v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        std::cout << maxFlow() << std::endl;
    }
    return 0;
}
