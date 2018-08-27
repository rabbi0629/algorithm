#include<bits/stdc++.h>

using LL = long long;

int main() 
{
	LL n, k, s;
	while(std::cin >> n >> k >> s) {
		if (s > k*(n-1) || k > s) {
			std::cout << "NO" << std::endl;
			continue;
		}

		std::vector<int> ans;
		int cur = 1;
		while(s) {
			auto ret = s-k;
			if(ret >= n-1) {
				if(cur == 1) {
					cur = n;
				} else if(cur == n) {
					cur = 1;
				}
				ans.push_back(cur);
				s -= n-1;
				k--;
			} else if(ret == 0) {
				s--;
				k--;
				if(cur+1 <= n) {
					cur++;
				} else {
					cur--;
				}
				ans.push_back(cur);
			} else {
				k--;
				s -= ret+1;
				if(cur+ret+1 <= n) {
					cur += ret+1;
				} else {
					cur -= ret+1;
				}
				ans.push_back(cur);
			}
		}
		std::cout << "YES" << std::endl;
		for(auto s:ans) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
