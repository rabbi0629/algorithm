#include<bits/stdc++.h>

int main()
{
	int n;
	std::string str;
	while(std::cin >> n) {
		std::cin >> str;
		std::map<std::string, int> mp;
		for(int i = 0; i+1 < n; i++) {
			std::string sub_str = str.substr(i, 2);
			mp[sub_str]++;
		}

		std::string ans = "";
		int max_time = 0;
		for(auto it = mp.begin(); it != mp.end(); it++) {
			//std::cout << "debug " << it->first << " " << it->second << std::endl;
			if(max_time < it->second) {
				max_time = it->second;
				ans = it->first;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
