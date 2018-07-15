#include<bits/stdc++.h>

using LL = long long;

int main()
{
	LL n;
	while(std::cin >> n) {
		n++;
		if(n == 1) {
			std::cout << 0 << std::endl;
			continue;
		}
		if(n%2 ==0){
			n /= 2;
		}
		std::cout << n << std::endl;
	}
	return 0;
}
