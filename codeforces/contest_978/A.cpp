#include<bits/stdc++.h>

int num[1000];

int main()
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}

		std::set<int> st;
		std::vector<int> vec;
		for(int i = n; i >= 1; i--) {
			if(st.find(num[i]) != st.end()) {
				continue;
			}
			st.insert(num[i]);
			vec.push_back(num[i]);
		}

		std::reverse(vec.begin(), vec.end());
		std::cout << vec.size() << std::endl;
		for(auto s:vec) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
