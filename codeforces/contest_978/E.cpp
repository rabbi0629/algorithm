#include<bits/stdc++.h>

using LL = long long;

LL num[100100];

int main()
{
	int n;
	LL w;
	while(std::cin >> n >> w) {
		for(int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			num[i] = num[i-1]+x;
		}

		LL max_num = 1000000000LL;
		LL min_num = -1000000000LL;
		for(int i = 1; i <= n; i++) {
			max_num = std::min(max_num, w-num[i]);
			min_num = std::max(min_num, -num[i]);
		}

		max_num = std::max(0LL, max_num);
		min_num = std::max(0LL, min_num);
		max_num = std::min(max_num, w);

		//std::cout << "debug " << max_num << " " << min_num << std::endl;

		if(max_num < min_num) {
			std::cout << 0 << std::endl;
		} else {
			std::cout << max_num - min_num + 1 << std::endl;
		}

	}
	return 0;
}
