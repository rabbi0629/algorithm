#include<bits/stdc++.h>

int main()
{
	std::string s1, s2;
	while(std::cin >> s1 >> s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len = len1 + len2;
		std::reverse(s1.begin(), s1.end());
		std::reverse(s2.begin(), s2.end());
		int cnt = 0;
		for(int i = 0; i < len1 && i < len2; i++) {
			if(s1[i] == s2[i]) {
				cnt+= 2;
			} else {
				break;
			}
		}
		std::cout << len - cnt << std::endl;
	}
	return 0;
}
