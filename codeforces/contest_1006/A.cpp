#include<bits/stdc++.h>

int num[10100];

int main()
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
		}
		for(int i = 1; i <= n; i++) {
			if(num[i]%2==0) {
				num[i]--;
			}
			std::cout << num[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
