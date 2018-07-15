#include<bits/stdc++.h>

int main()
{
	std::string str;
	int n;
	while(std::cin >> n) {
		std::cin >> str;
		bool ok = true;
		for(int i = 0; i < n; i++) {
			if(str[i] == '0') {
				if((i > 0 && str[i-1] == '0') && (i < n-1 && str[i+1] == '0')) {
					ok = false;
					break;
				}

				if(n >= 2) {
					if(str[0] == '0' && str[1] == '0') {
						ok = false;
						break;
					}
					if(str[n-2] == '0' && str[n-1] == '0') {
						ok = false;
						break;
					}
				}
				if(n == 1){
					if(str[0] == '0') {
						ok = false;
						break;
					}
				}
			} else {   //当前位置被占了.
				if((i > 0 && str[i-1] == '1') || (i+1 < n && str[i+1] == '1')) {
					ok = false;
					break;
				}
			}
		}

		if(ok) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
