#include<bits/stdc++.h>

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		if(m < n-1) {
			std::cout << "Impossible" << std::endl;
			continue;
		}

		std::vector<std::pair<int, int> > edge;
		for(int i = 1; i <= n && m; i++) {
			for(int j = i+1; j <= n && m; j++) {
				if(gcd(i, j) == 1) {
					edge.push_back(std::make_pair(i, j));
					m--;
				}
			}
		}
		if(m == 0) {
			std::cout << "Possible" << std::endl;
			for(auto s:edge) {
				std::cout << s.first << " " << s.second << std::endl;
			}
		} else {
			std::cout << "Impossible" << std::endl;
		}
	}
	return 0;
}
