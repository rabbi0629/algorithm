#include<bits/stdc++.h>

char str[1001000];
int cnt[30];

int main()
{
	while(std::cin >> str) {
		int len = strlen(str);

		if(len < 4) {
			puts("No");
			continue;
		}

		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < len; i++) {
			cnt[str[i] - 'a']++;
		}

		int kind = 0, num = 0;
		for(int i = 0; i < 26; i++) {
			if(cnt[i] != 0) {
				kind++;
			}
			if(cnt[i] > 1) {
				num++;
			}
		}

		//std::cout << cnt[0] << " " << cnt[1] << std::endl;

		//std::cout << kind << " " << num << std::endl;

		if(kind > 4 || kind == 1) {
			std::cout << "No" << std::endl;
			continue;
		}

		if(kind == 4 || kind == 3) {
			std::cout << "Yes" << std::endl;
			continue;
		}
		
		if(kind == 2 && num < 2) {
			std::cout << "No" << std::endl;
			continue;
		}

		std::cout << "Yes" << std::endl;
	}
	return 0;
}
