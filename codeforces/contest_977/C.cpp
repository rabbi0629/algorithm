#include<bits/stdc++.h>

int num[200020];

int main()
{
	int n, k;
	while(std::cin >> n >> k) {
		for(int i = 0; i < n; i++){
			std::cin >> num[i];
		}

		std::sort(num, num+n);
		if(k == 0) {
			if (num[0] == 1) {
				std::cout << -1 << std::endl;
			} else {
				std::cout << num[0] - 1 << std::endl;
			}
			continue;
		}

		if(k == n) {
			int ans = 1000000000;
			int cnt = 0;
			for(int i = n-1; i >= 0; i--) {
				if(num[i] == ans) {
					cnt++;
				}
			}

			if(cnt > k) {
				std::cout << -1 << std::endl;
			} else {
				std::cout << ans << std::endl;
			}

			continue;
		}

		if(num[k-1] == num[k]) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << num[k-1] << std::endl;
	}
	return 0;
}
