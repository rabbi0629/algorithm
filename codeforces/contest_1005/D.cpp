#include<bits/stdc++.h>

int dp[200200], mod[5];

int main()
{
	std::string str;
	while(std::cin >> str) {
		int len = str.length();
		memset(dp, 0, sizeof(dp));
		memset(mod, -1, sizeof(mod));
		int sum = 0;
		mod[0] = 0;
		for(int i = 1; i <= len; i++) {
			sum = (sum + str[i-1]-'0') % 3;
			dp[i] = dp[i-1];
			if(mod[sum] != -1) {
				dp[i] = std::max(dp[i], dp[mod[sum]]+1);
			}
			mod[sum] = i;
		}
		std::cout << dp[len] << std::endl;
	}
	return 0;
}
