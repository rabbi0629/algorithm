#include<bits/stdc++.h>

int main()
{
	int len;
	std::string str;
	while(std::cin >> len) {
		std::cin >> str;
		int i = 0;
		int ans = 0;
		while(i < len) {
			if(str[i] != 'x') {
				i++;
				continue;
			}
			int j = i+1;
			int num = 1;
			while(j < len && str[j] == 'x') {
				j++;
				num++;
			}
			i=j;
			ans += std::max(0, num-2);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
