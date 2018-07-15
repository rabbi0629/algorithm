#include<bits/stdc++.h>

int num[400200];
std::pair<int, int> pp[400400];

int main()
{
	int n;
	std::string str;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			pp[i] = std::make_pair(num[i], i);
		}

		std::sort(pp+1, pp+n+1);
		int L = 0;
		std::multiset<std::pair<int, int> > st;
		std::cin >> str;
		for(auto s:str) {
			if(s == '0') {
				auto tmp = pp[++L];
				std::cout << tmp.second << " ";
				st.insert(tmp);
			} else {
				auto it = --st.end();
				std::cout << it->second << " ";
				st.erase(it);
			}
		}

		std::cout << std::endl;
	}
	return 0;
}
