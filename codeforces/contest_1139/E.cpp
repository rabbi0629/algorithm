#include<bits/stdc++.h>

int p[10000], c[10000], n, m;
std::set<std::pair<int, int> > st[5500];

struct Node {
    int l, r, maxx;
}node[30030];

void push_up(int rt) {
    node[rt].maxx = std::max(node[rt<<1].maxx, node[rt<<1|1].maxx);
}

void build_tree(int rt, int l, int r) {
    node[rt].l = l;
    node[rt].r = r;
    node[rt].maxx = 0;

    if(l == r) {
        return;
    }

    int mid = (l+r) / 2;
    build_tree(rt<<1, l, mid);
    build_tree(rt<<1|1, mid+1, r);
    push_up(rt);
}

void modify(int rt, int id, int x) {
    if(node[rt].l == id && node[rt].r == id) {
        node[rt].maxx = x;
        return;
    }
    int mid = (node[rt].l + node[rt].r) / 2;
    if(id <= mid) {
        modify(rt<<1, id, x);
    } else {
        modify(rt<<1|1, id, x);
    }
    push_up(rt);
}

int query(int rt, int l, int r) {
    if(node[rt].l <= l && node[rt].r >= r) {
        return node[rt].maxx;
    }

    int mid = (node[rt].l + node[rt].r) / 2;
    if(r <= mid) {
        return query(rt<<1, l, r);
    } else if (l > mid) {
        return query(rt<<1|1, l, r);
    }
    return std::max(query(rt<<1, l, r), query(rt<<1|1, l, r));
}

int main() 
{
    while(std::cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            std::cin >> p[i];
        }

        for(int i = 1; i <= n; i++) {
            std::cin >> c[i];
        }

        build_tree(1, 1, n);

        for(int i = 1; i <= n; i++) {
            st[i].clear();
        }

        for(int i = 1; i <= n; i++) {
            st[c[i]].insert(std::make_pair(p[i], i));
        }

        for(int i = 1; i <= n; i++) {
            if(!st[i].empty()) {
                auto it = st[i].rbegin();
                modify(1, i, it->first);
            }
        }

        int q;
        std::cin >> q;
        while(q--) {
            int id;
            std::cin >> id;
            st[c[id]].erase(std::make_pair(p[id], id));
            int maxx = 0;
            if(!st[c[id]].empty()) {
                auto it = st[c[id]].rbegin();
                maxx = it->first;
            }
            std::cout << "debug: " << c[id] << " " << st[c[id]].size() << " " << maxx << std::endl;
            for(auto s: st[c[c[id]]]) {
                std::cout << "debug1: " << s.first << " " << s.second << std::endl;
            }

            modify(1, c[id], maxx);

            std::cout << query(1, 1, n) << std::endl;
        }

    }
    return 0;
}
