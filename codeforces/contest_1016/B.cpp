#include<bits/stdc++.h>

int main()
{
	int n, m, q;
	while(std::cin >> n >> m >> q) {
		std::string s1, s2;
		std::cin >> s1 >> s2;

		std::vector<std::pair<int, int> > sol;

		auto pos = 0;
		while(1) {
			auto pos1 = s1.find(s2, pos);
			//std::cout << "pos1: " << pos1 << " " << pos << std::endl;
			if(pos1 == std::string::npos) {
				break;
			}
			sol.push_back(std::make_pair(pos1, pos1+m-1));
			pos = pos1+1;
		}

		//std::cout << "debug begin" << std::endl;
		//for(auto s:sol) {
			//std::cout << s.first << " " << s.second << std::endl;
		//}
		//std::cout << "debug end" << std::endl;

		while(q--) {
			int l, r;
			std::cin >> l >> r;
			l--;
			r--;
			int cnt = 0;
			for(auto s:sol) {
				if(s.first >= l && s.second <= r) {
					cnt++;
				}
			}
			std::cout << cnt << std::endl;
		}
	}
	return 0;
}
