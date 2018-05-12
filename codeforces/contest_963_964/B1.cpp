#include<bits/stdc++.h>

int d[200200], head[200200], tot;

struct Edge{
	int from, to;
	bool ok;
}edge[500100];

void addedge(int u, int v) {
	edge[tot].from = u;
	edge[tot].to = v;
	edge[tot].ok = true;
	tot++;
}

struct Node {
	int u;
	int du;
};

struct NodeCamp {
	bool operator ()  (const Node &a, const Node &b) const {
		if(a.du % 2 == 1) return true;
		if(b.du % 2 == 1) return true;
		return a.du > b.du;
	}
};

int main()
{
	int n;
	while(std::cin >> n) {
		memset(d, 0, sizeof(d));
		memset(head, -1, sizeof(head));
		tot = 0;
		for(int i = 1; i <= n; i++) {
			int p;
			std::cin >> p;
			if(p) {
				addedge(i, p);
				addedge(p, i);
				d[i]++;
				d[p]++;
			}
		}

		if(n % 2 == 0) {
			std::cout << "NO" << std::endl;
			continue;
		}

		std::priority_queue<
	}
	return 0;
}
