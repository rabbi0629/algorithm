#include<bits/stdc++.h>

const int INF = 10000000;

std::string s1[110], s2[110];
int cnt[110];

int main() 
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> s1[i];
		}

		for(int i = 1; i <= n; i++) {
			std::cin >> s2[i];
		}

		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int id = -1,minx = INF;
			for(int j = 1; j <= n; j++) {
				if(cnt[j] == -1 || s1[i].length() != s2[j].length()) {
					continue;
				}

				if(s1[i] == s2[j]) {
					minx = 0;
					id = j;
					break;
				}
			}
			cnt[id] = -1;
			if(minx == INF) {
				ans++;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}

