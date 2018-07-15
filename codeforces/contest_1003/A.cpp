#include<bits/stdc++.h>

int main() 
{
	int n;
	while(std::cin >> n) {
		std::map<int, int> mp;
		int mx = 1;
		for(int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			mp[x]++;
			if(mx < mp[x]) {
				mx = mp[x];
			}
		}
		std::cout << mx << std::endl;
	}
	return 0;
}
