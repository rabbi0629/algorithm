#include<bits/stdc++.h>

const int maxn = 400100;

int degree[maxn];
std::vector<std::pair<int, int> > edge;
std::set<std::pair<int, int> > st;


int main()
{
	int n, d, k;
	while(std::cin >> n >> d >> k) {
		memset(degree, 0, sizeof(degree));
		edge.clear();
		st.clear();

		if(d >= n) {
			std::cout << "NO" << std::endl;
			continue;
		}

		bool ok = true;

		for(int i = 1; i <= d; i++) {
			degree[i]++;
			degree[i+1]++;
			if(degree[i] > k || degree[i+1] > k) {
				ok = false;
				break;
			}
			edge.push_back(std::make_pair(i, i+1));
		}

		for(int i = 1; i <= d+1; i++) {
			st.insert(std::make_pair(std::max(d+1-i, i-1),i));
		}

		for(int i = d+2; i <= n && ok; i++) {
			while(!st.empty() && degree[st.begin()->second] == k) {
				st.erase(st.begin());
			}

			if(st.empty() || st.begin()->first == d) {
				ok = false;
				break;
			}
			auto it = st.begin();
			degree[i]++;
			degree[it->second]++;
			edge.push_back(std::make_pair(i, it->second));
			st.insert(std::make_pair(it->first+1, i));
		}

		if(!ok) {
			std::cout << "NO" << std::endl;
			continue;
		}
		std::cout << "YES" << std::endl;
		for(auto s:edge) {
			std::cout << s.first << " " << s.second << std::endl;
		}
	}
	return 0;
}
