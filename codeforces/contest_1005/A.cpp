#include<bits/stdc++.h>

int num[100100];

int main()
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}
		std::vector<int> ans;
		int cnt = 1;
		int i = 1; 
		while(i <= n) {
			int j = i+1;
			while(j <= n && num[j] != 1) j++,cnt++;
			ans.push_back(cnt);
			i=j;
			cnt=1;
		}
		std::cout << ans.size() << std::endl;
		for(auto s:ans) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
