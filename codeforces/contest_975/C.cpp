#include<bits/stdc++.h>

using LL = long long;

LL num[200200], presum[200020];

int main()
{
	int n, q;
	while(std::cin >> n >> q) {
		presum[0] = 0;
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			presum[i] = presum[i-1] + num[i];
		}

		//for(int i = 1; i <= n; i++) {
			//std::cout << presum[i] << " ";
		//}
		//std::cout << std::endl;

		LL cnt = 0;
		while(q--) {
			LL xx;
			std::cin >> xx;
			cnt += xx;
			if(cnt >= presum[n]) {
				cnt = 0;
				std::cout << n << std::endl;
				continue;
			}

			int id = std::upper_bound(presum+1, presum+n+1, cnt) -presum -1;
			//std::cout << "id: " << id << " " << cnt << std::endl;
			std::cout << n - id << std::endl;
		}
	}
	return 0;
}
