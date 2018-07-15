#include<bits/stdc++.h>

using LL = long long;

LL num[200200];
LL power_list[50];

int main()
{
	int n;
	power_list[0] = 1;
	for(int i = 1; i <= 40; i++) {
		power_list[i] = power_list[i-1]<<1;
	}
	while(std::cin >> n) {
		std::multiset<LL> st;
		std::map<LL,int> mp;
		for(int i = 1; i <= n; i++) {
			std::cin >> num[i];
			st.insert(num[i]);
			mp[num[i]]++;
		}

		int ans = 0;
		for(int i = 1; i <= n; i++) {
			bool ok = false;
			for(int j = 0; j <= 40; j++) {
				LL rev = power_list[j]-num[i];
				if(st.find(rev) != st.end()) {
					if (rev != num[i] || (rev == num[i] && mp[num[i]] > 1)) {
						ok = true;
						break;
					}
				}
			}
			if(!ok) {
				ans++;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
