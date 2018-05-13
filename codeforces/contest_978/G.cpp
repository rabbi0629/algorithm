#include<bits/stdc++.h>

using LL = long long;

struct Exam{
	int begin;
	int end;
	int cost;
	int deadline;
	int id;
}pp[110];

bool operator < (const Exam &a, const Exam &b) {
	return a.deadline < b.deadline;
}

int ans[200];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= m; i++) {
			std::cin >> pp[i].begin >> pp[i].end >> pp[i].cost;
			ans[pp[i].end] = m+1;
			pp[i].id = i;
		}

		for(int i = 1; i <= m; i++) {
			int cnt = 0;
			for(int j = pp[i].begin; j < pp[i].end; j++) {
				if(ans[j] == 0) {
					cnt++;
				}
			}
			pp[i].deadline = cnt;
		}
		std::sort(pp+1, pp+m+1);

		//for(int i = 1; i <= m; i++) {
			//std::cout << "debug " << pp[i].id << " " << pp[i].begin << " " << pp[i].end << " " << pp[i].deadline << " " << pp[i].cost << std::endl;
		//}
		bool ok = true;
		for(int i = 1; i <= m; i++) {
			int cnt = pp[i].cost;
			for(int j = pp[i].end-1; j >= pp[i].begin && cnt > 0; j--) {
				if(ans[j] == 0) {
					ans[j] = pp[i].id;
					cnt--;
				}
			}
			if(cnt > 0) {
				ok = false;
				break;
			}
		}

		if(!ok) {
			std::cout << -1 << std::endl;
			continue;
		}

		for(int i = 1; i <= n; i++) {
			std::cout << ans[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
