#include<bits/stdc++.h>

using LL = long long;

const LL INF = 1000000000LL;
LL num[200200], det[200200], cur[200200];
int n;

LL calc() {
	memcpy(cur, num, sizeof(num));
	LL delte = cur[2] - cur[1];
	int ans = 0;
	//std::cout << "debug ";
	//for(int i = 1; i <= n; i++) {
		//std::cout << cur[i] << " ";
	//}
	//std::cout << std::endl;
	for(int i = 3; i<= n; i++) {
		if(cur[i] - cur[i-1] == delte) {
			continue;
		}

		if(cur[i] - cur[i-1] == delte-1) {
			cur[i]++;
			ans++;
		} else if(cur[i] - cur[i-1] == delte+1) {
			cur[i]--;
			ans++;
		}
		else {
			return INF;
		}
	}
	return ans;
}

int main()
{
	while(std::cin >> n) {
		memset(det, 0, sizeof(det));
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}
		if(n < 3) {
			std::cout << 0 << std::endl;
			continue;
		}

		for(int i = 2; i <= n; i++) {
			det[i] = num[i] - num[i-1];
		}

		//std::cout << "debug1 " ;
		//for(int i = 1; i <= n; i++) {
			//std::cout << det[i] << " ";
		//}
		//std::cout << std::endl;

		bool all_same = true;
		for(int i = 3; i <= n; i++) {
			if(det[i] != det[i-1]) {
				all_same = false;
			}
		}

		if(all_same) {
			std::cout << 0 << std::endl;
			continue;
		}

		LL ans = INF;

		ans = std::min(ans, calc());

		num[1]--;
		ans = std::min(ans, calc()+1);
		num[1]++;

		num[1]++;
		ans = std::min(ans, calc()+1);
		num[1]--;

		num[2]--;
		ans = std::min(ans, calc()+1);
		num[2]++;

		num[2]++;
		ans = std::min(ans, calc()+1);
		num[2]--;

		num[1]--; num[2]--;
		ans = std::min(ans, calc()+2);
		num[1]++; num[2]++;

		num[1]++; num[2]++;
		ans = std::min(ans, calc()+2);
		num[1]--; num[2]--;

		num[1]--; num[2]++;
		ans = std::min(ans, calc()+2);
		num[1]++; num[2]--;

		num[1]++; num[2]--;
		ans = std::min(ans, calc()+2);
		num[1]--; num[2]++;


		if(ans == INF) {
			ans = -1;
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
