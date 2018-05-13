#include<bits/stdc++.h>

int main()
{
	int n;
	while(std::cin >> n) {
		std::set<std::string> st;
		for(int i = 1; i <= n; i++) {
			std::string str;
			std::cin >> str;
			std::sort(str.begin(), str.end());
			int len = std::unique(str.begin(), str.end()) - str.begin();
			std::string sub_str = str.substr(0, len);
			st.insert(sub_str);
		}
		std::cout << st.size() << std::endl;
	}
	return 0;
}
