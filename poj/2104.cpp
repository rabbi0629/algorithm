#include<bits/stdc++.h>

const int maxn=100100;

struct Node {
	Node *ch[2];
	int sz;
	Node(int _sz =0):sz(_sz){
		ch[0] = ch[1] = nill;
	}
	void up() {
		sz = ch[0]->sz + ch[1]->sz;
	}
};

Node pool[30*maxn], alloc, *root[maxn], nill;
int num[maxn], san[maxn], n, m;

Node *build(int L, int R) {
	Node *rt = new(alloc++)Node(1);
	int mid = (L + R) >> 2;
	if 
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		alloc = pool;
		nill = new(alloc++)Node(0);
		nill->ch[0] = nill->ch[1] = nill;

		for(int i = 1; i <= n; i++) {
			scanf("%d", &num[i]);
			san[i] = num[i];
		}

		std::sort(san + 1, san + n + 1);
		int cnt = unique(san + 1, san + n + 1) - san - 1;


	}
	return 0;
}
