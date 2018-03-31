#include<bits/stdc++.h>

char str[110];

int main() {
	int len;
	while(std::cin >> len) {
		std::cin >> str;
		for(int i = 0; i+1 < len; i++) {
			if((str[i] == 'U' && str[i+1] == 'R') || (str[i] == 'R' && str[i+1] == 'U')) {
				str[i] = 'D';
				str[i+1] = '-';
			}
		}
		int ans = 0;
		for(int i = 0; i < len; i++) {
			if(str[i] != '-') {
				ans++;
			}
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
