#include<bits/stdc++.h>

int main()
{
	int hh, mm;
	int H, D, C, N;
	while(std::cin >> hh >> mm) {
		std::cin >> H >> D >> C >> N;
		if(hh >= 20) {
			int cnt = H / N;
			if(H % N) {
				cnt++;
			}

			double ans = 0.8 * C * cnt;
			std::cout << ans << std::endl;
			continue;
		}

		int cnt = H / N;
		if(H % N) {
			cnt++;
		}

		double ans1 = (double)C * cnt;

		H += ((20 - hh - 1) * 60 + (60 - mm)) * D;
		int cnt1 = H / N;
		if(H % N) {
			cnt1++;
		}

		double ans2 = 0.8 * C * cnt1;

		std::cout << std::min(ans1, ans2) << std::endl;
	}
	return 0;
}
