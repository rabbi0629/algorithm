#include<bits/stdc++.h>

int main()
{
	std::string s, t;
	int length;
	while(std::cin >> length) {
		std::cin >> s >> t;
		std::string s1 = s, s2 = t;
		std::sort(s1.begin(), s1.end());
		std::sort(s2.begin(), s2.end());
		//std::cout << "debug " << s1 << " " << s2 << std::endl;
		if(s1 != s2) {
			std::cout << -1 << std::endl;
			continue;
		}
		std::vector<int> ans;
		int length = s.length();
		for(int i = 0; i < length; i++) {
			if(s[i] != t[i]) {
				int id = -1;
				for(int j = i+1; j< length; j++) {
					if(s[j] == t[i]) {
						id = j;
						break;
					}
				}
				for(int j = id-1; j >=i; j--) {
					std::swap(s[j], s[j+1]);
					ans.push_back(j+1);
				}
			}
		}
		std::cout << ans.size() << std::endl;
		for(auto tt:ans) {
			std::cout << tt << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
