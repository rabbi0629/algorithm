#include<bits/stdc++.h>

int main()
{
	std::string str;
	while(std::cin >> str) {
		int len = str.length();
		auto str1 = str;
		std::sort(str1.begin(), str1.end());
		if(str1 != str) {
			std::cout << "NO" << std::endl;
			continue;
		}

		int numa = 0, numb = 0, numc = 0;
		for(auto s:str) {
			if(s == 'a') {
				numa++;
			}

			if(s == 'b') {
				numb++;
			}

			if(s == 'c') {
				numc++;
			}
		}

		if(numa == 0 || numb == 0 || numc == 0) {
			std::cout << "NO" << std::endl;
			continue;
		}

		if(numc == numa || numc == numb) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
