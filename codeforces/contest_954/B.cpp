#include<bits/stdc++.h>
const int INF=100000;

char str[200];
int dp[200][2];

bool check(int id) {
	if(id % 2) {
		return false;
	}
	for(int i = 1; i <= id/2; i++) {
		if(str[i] != str[i+id/2]) {
			return false;
		}
	}
	return true;
}

int main() {
	int len;
	while(std::cin >> len) {
		scanf("%s", str+1);
		dp[1][0] = 1;
		dp[1][1] = 1;
		for(int i = 2; i <= len; i++) {
			dp[i][0] = dp[i-1][0] + 1;
			dp[i][1] = dp[i-1][1] + 1;
			if(check(i)) {
				dp[i][1] = std::min(dp[i][1], dp[i/2][0] + 1);
			}
		}

		std::cout << std::min(dp[len][0], dp[len][1]) << std::endl;
	}
	return 0;
}
