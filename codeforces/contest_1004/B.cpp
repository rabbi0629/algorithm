#include<bits/stdc++.h>

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		for(int i = 1; i <= m; i++) {
			int xx, yy;
			std::cin >> xx >> yy;
		}
		std::string str;
		for(int i = 1; i <= n; i++) {
			if(i%2) str += "0";
			else str += "1";
		}
		std::cout << str << std::endl;
	}
}
