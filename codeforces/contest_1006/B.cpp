#include<bits/stdc++.h>

int num[100100], flag[100100];
std::pair<int, int> pp[10000];

int main()
{
	int n, d;
	while(std::cin >> n >> d) {
		memset(flag, -1, sizeof(flag)); 
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			pp[i] = std::make_pair(num[i], i);
		}

		int ans = 0;
		std::sort(pp+1, pp+n+1);
		std::reverse(pp+1, pp+n+1);
		for(int i = 1; i <= d; i++) {
			flag[pp[i].second]=1;
			ans += num[pp[i].second];
		}

		std::vector<int> sa;
		for(int i = 1; i <= n; i++) {
			int j = i;
			while(j <= n && flag[j] == -1) {
				j++;
			}

			if(j > n) {
				if(int(sa.size()) == d) {
					sa[sa.size()-1] += j-i;
				} else {
					sa.push_back(j-i);
				}
				break;
			}

			if(int(sa.size()) == d) {
				sa[sa.size()-1] += j-i+1;
			} else {
				sa.push_back(j-i+1);
			}
			i=j;
		}
		
		std::cout << ans << std::endl;
		for(auto s:sa) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
