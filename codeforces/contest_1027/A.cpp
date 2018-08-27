#include<bits/stdc++.h>

int main()
{
	int T;
	std::cin >> T;
	while(T--) {
		int n;
		std::string str;
		std::cin >> n;
		std::cin >> str;
		bool ok = true;
		for(int i = 0, j = n-1; i < j; i++, j--) {
			int t1 = str[i]-'a';
			int t2 = str[j]-'a';
			if(t1 == t2 || t1 == t2+2 || t2 == t1+2 ) {
				continue;
			}
			ok = false;
			break;
		}
		if(ok) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
