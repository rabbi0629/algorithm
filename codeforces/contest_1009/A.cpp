#include<bits/stdc++.h>

int A[2000], B[2000];

int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			std::cin >> A[i];
		}

		for(int i = 1; i <= m; i++) {
			std::cin >> B[i];
		}

		int ans = 0;
		for(int i = 1, j = 1; i <= n && j <= m; i++) {
			if(B[j] >= A[i]) {
				ans++;
				j++;
			}
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
