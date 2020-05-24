#include<bits/stdc++.h>

const int maxn = 100100;
int head[maxn], tot, dist[maxn], cur[maxn], queue[maxn*2];
int start,end;
int n, m;

struct Edge {
    int next,to,flow;
}edge[maxn*4];

void add_edge(int u,int v, int flow) {
    edge[tot]=Edge{head[u],v,flow}; head[u] = tot++;
    edge[tot]=Edge{head[v],u,0}; head[v] = tot++;
}

bool bfs() {
    memset(dist, -1, sizeof(dist));
    int front = 0, rear = 0;
    dist[start] = 0; queue[front++] = start;
    while(front != rear) {
        int u = queue[rear++];
        if(u == end) return true;
        for(int i = head[u]; ~i; i = edge[i].next) {
            if(dist[edge[i].to] == -1 && edge[i].flow > 0) {
                dist[edge[i].to] = dist[u]+1;
                queue[front++] = edge[i].to;
            }
        }
    }
    return false;
}

bool BFS()///update dist[]
{
    memset(dist, -1, sizeof(dist));
    int fro, bac;
    fro = bac = 0;
    queue[bac++] = start, dist[start] = 0;
    while(fro < bac) {
        int first = queue[fro];
        if(first == end) return true;
        for(int i = head[first]; ~i; i = edge[i].next) {
            if(dist[ edge[i].to ] == -1 && edge[i].flow > 0)
            {
                dist[ edge[i].to ] = dist[first] + 1;
                queue[bac++] = edge[i].to;
            }
        }
        fro++;
    }
    return false;
}

int dfs(int now, int cap) {
    if(now == end) {
        return cap;
    }

    int flow, cost = 0;
    for(int &i = cur[now]; i != -1 && cost < cap; i = edge[i].next) {
        int v = edge[i].to;
        if(edge[i].flow > 0 && dist[v] == dist[now] + 1 && (flow = dfs(v, std::min(cap-cost, edge[i].flow)))) {
            edge[i].flow -= flow;
            edge[i^1].flow += flow;
            cost += flow;
        }
    }

    if(cost == 0) dist[now] = -2;
    return cost;
}

int DFS(int s, int cap) {
    if(s == end) return cap;

    int flow = 0, f;
    for(int i = cur[s]; i != -1; i = edge[i].next) {
        int to = edge[i].to;
        if(dist[to] == dist[s] + 1 && edge[i].flow>0)
        {
            f = DFS(to, std::min(cap - flow, edge[i].flow));
            edge[i].flow -= f;
            edge[i^1].flow += f;
            flow += f;
            if(flow == cap)
                break;
        }
    }
    if(flow == 0)///某层DFS里某个flow为0
        dist[s] = -2;///封锁这个flow，避免无用的重复搜索
    return flow;
}

int maxFlow() {
    int ans = 0;
    while(BFS()) {
        //std::cout << "debug " << ans << std::endl;
        for(int i = 1; i <= n; i++) cur[i] = head[i];
        ans += DFS(start, 0xfffffff);
        
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
