#include<bits/stdc++.h>

int num[100100];
int left[100100], right[100100];  // zuo liang, you an.

int main()
{
	int n, M;
	while(std::cin >> n >> M) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}

		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		for(int i = 1; i <= n; i++) {
			left[i] += left[i-1];
			if(i%2) {
				left[i] += num[i] - num[i-1];
			}
		}

		std::cout << std::endl;

		if(n%2) {
			right[n] = M-num[n];
		}

		for(int i = n-1; i >= 1; i--) {
			right[i] = right[i+1];
			if(i%2) {
				right[i] += num[i+1] - num[i];
			}
		}

		int ans = left[n];
		if(n%2 == 0) {
			ans += M-num[n];
		} else {
			ans += M-num[n]-1;
		}

		for(int i = 1; i <= n; i++) {
			ans = std::max(ans, left[i-1] + num[i] - num[i-1] - 1 + right[i]);
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
