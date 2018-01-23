#include<bits/stdc++.h>

int prime[1000100], flag[1001000], index = 0;

void init() {
	memset(flag, 0, sizeof(flag));
	flag[1] = 1;
	for(int i = 2; i <= 1000000; i++) {
		if(!flag[i]) {
			prime[index++] = i;
		}
		for(int j = 0; j<index && i*prime[j] <= 1000000; j++){
			flag[i*prime[j]] = 1;
		}
	}

	//for(int i = 0; i < 10; i++) {
		//std::cout << "han " << prime[i] << std::endl;
	//}

	//std::cout << "index: " << index << std::endl;
}

struct Edge{
	int u;
	int v;
	int w;
};

int main() {
	init();
	int n, m;
	while(std::cin >> n >> m) {
		std::vector<Edge> edge;
		std::set<std::pair<int, int> > st;

		for(int i = 1; i < n; i++) {
			edge.push_back(Edge{i, i+1, 1});
			st.insert(std::make_pair(i, i+1));
		}

		int pos = std::lower_bound(prime, prime+index, n-1) - prime;

		//std::cout << "debug: " << n-1 << " " << pos << " " << prime[pos + 1] << std::endl;
		int delta = prime[pos+1] - n + 1;
		for(int i = 0; i < delta; i++) {
			edge[i].w++;
		}

		int sum1 =0, sum2 = 0;
		for(int i = 0; i < edge.size(); i++){
			sum1 += edge[i].w;
		}
		sum2 = sum1;

		m -= n-1;
		for(int i = 1; i <= n && m != 0; i++) {
			for(int j = i+1; j <= n && m != 0; j++) {
				if(st.find(std::make_pair(i, j)) == st.end()) {
					edge.push_back(Edge{i, j, 10000000});
					m--;
					st.insert(std::make_pair(i, j));
				}
			}
		}

		std::cout << sum1 << " " <<  sum2 << std::endl;

		for(auto s:edge) {
			std::cout << s.u << " " << s.v << " " << s.w << std::endl;
		}
	}
	return 0;
}

