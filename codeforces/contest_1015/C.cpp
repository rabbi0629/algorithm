#include<bits/stdc++.h>

using LL = long long;

std::pair<int, int> song[100100];

int main()
{
	int n;
	LL m;
	while(std::cin >> n >> m) {
		LL sum1 = 0, sum2 = 0;
		std::set<std::pair<LL, int> > st;
		for(int i = 0; i < n; i++) {
			std::cin >> song[i].first >> song[i].second;
			sum1 += song[i].first;
			sum2 += song[i].second;
			st.insert(std::make_pair(song[i].first - song[i].second, i));
		}

		if(sum1 <= m) {
			std::cout << 0 << std::endl;
			continue;
		}

		if(sum2 > m) {
			std::cout << -1 << std::endl;
			continue;
		}

		int ans = 0;
		while(sum1 > m) {
			auto it = --st.end();
			sum1 -= it->first;
			ans++;
			st.erase(it);
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
