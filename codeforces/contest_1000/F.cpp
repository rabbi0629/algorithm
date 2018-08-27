#include<bits/stdc++.h>

const int maxn = 600100;

int num[maxn], ans[maxn], block, cnt[maxn];
int in[maxn];
std::vector<int> st;

struct Query {
	int l, r,id, block;
}q[maxn];

bool cmp(Query a, Query b) {
	if(a.block!=b.block)
		return a.block<b.block;
	return a.block&1?a.r<b.r:a.r>b.r;		
}

inline void upd(int i){
	if(cnt[i]==1 && !in[i]){
		st.emplace_back(i);
		in[i]=1;
	}
}

inline void add(int i){
	++cnt[num[i]];
	upd(num[i]);
}

inline void del(int i){
	--cnt[num[i]];	
	upd(num[i]);
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	while(std::cin >> n) {
		for(int i = 0; i < n; i++) {
			std::cin >> num[i];
		}

		std::cin >> m;

		block = int(sqrt(n+0.5));
		for(int i = 0; i < m; i++) {
			std::cin >> q[i].l >> q[i].r;
			q[i].l--;
			q[i].r--;
			q[i].id = i;
			q[i].block = i/block;
		}

		std::sort(q, q+m, cmp);

		st.clear();
		memset(cnt, 0, sizeof(cnt));
		memset(in, 0, sizeof(in));

		int l=0, r=-1;
		for(int i=0; i<m; ++i){
			auto x=q[i];
			while(l<x.l)
				del(l++);
			while(l>x.l)
				add(--l);
			while(r<x.r)
				add(++r);
			while(r>x.r)
				del(r--);
			while(st.size() && cnt[st.back()]!=1){
				in[st.back()]=0;
				st.pop_back();
			}
			ans[x.id]=st.empty()?0:st.back();
		}
		for(int i = 0; i < m; i++) {
			std::cout << ans[i] << std::endl;
		}
	}
	return 0;
}
