#include<bits/stdc++.h>

int main()
{
	std::string str;
	while(std::cin >> str) {
		//-o-o--
		int cnt1 = 0, cnt2 = 0;
		for(auto s:str) {
			if(s == 'o') {
				cnt1++;
			} else {
				cnt2++;
			}
		}

		if(cnt2 == 0 || cnt1 == 0 || cnt2 % cnt1 == 0){
			std::cout << "YES" << std::endl;
			continue;
		}
		std::cout << "NO" << std::endl;
	}
	return 0;
}
