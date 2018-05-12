#include<bits/stdc++.h>

int main()
{
	int n, k;
	while(std::cin >> n >> k) {
		while(k--) {
			if(n%10 == 0) {
				n /= 10;
			}else {
				n--;
			}
		}
		std::cout << n << std::endl;
	}
	return 0;
}
