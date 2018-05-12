#include<bits/stdc++.h>

int a[10010];

int main()
{
	int n, A, B, C, T;
	while(std::cin >> n >> A >> B >> C >> T) {
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		if(B >= C) {
			std::cout << n * A << std::endl;
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int xx = A + (T - a[i] ) * (C - B);
			//std::cout << "xx: " << xx << std::endl;
			ans += xx;
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
