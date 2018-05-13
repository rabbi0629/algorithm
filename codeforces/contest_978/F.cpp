#include<bits/stdc++.h>

using LL = long long;

int skill[300300], num[300300], cnt[200200], ans[200200];
std::pair<int, int> q[200200];


int main()
{
	int n, k;
	while(std::cin >> n >> k) {
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= n ; i++) {
			std::cin >> skill[i];
			num[i] = -skill[i];
		}

		std::sort(num+1, num+n+1);
		for(int i = 1; i<= k; i++) {
			std::cin >> q[i].first >> q[i].second;
			if(skill[q[i].first] > skill[q[i].second]) {
				cnt[q[i].first]++;
			}

			if(skill[q[i].first] < skill[q[i].second]) {
				cnt[q[i].second]++;
			}
		}

		//for(int i = 1; i <= n; i++) {
			//std::cout << cnt[i] << " ";
		//}
		//std::cout << std::endl;

		for(int i = 1; i <= n; i++) {
			if(skill[i] <= num[1]) {
				ans[i] = 0;
				continue;
			}

			int pos = std::upper_bound(num+1, num+n+1, -skill[i]) - num;
			ans[i] = std::max(0, n-pos+1-cnt[i]);
		}

		for(int i = 1; i <= n; i++) {
			std::cout << ans[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
