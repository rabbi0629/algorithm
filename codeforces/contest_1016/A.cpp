#include<bits/stdc++.h>

using LL = long long;

int main()
{
	int n;
	LL m;
	while(std::cin >> n >> m) {
		LL sum = 0;
		std::vector<int> ans;
		for(int i = 1; i <= n; i++) {
			LL x;
			std::cin >>x;
			sum += x;
			ans.push_back(sum/m);
			sum %= m;
		}
		for(auto s:ans) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
