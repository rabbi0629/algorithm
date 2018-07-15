#include<bits/stdc++.h>

std::map<std::string, int> mp;
int len[1000], num[1000], next[1000];

int get_id(std::string str) {
	if(mp.find(str) == mp.end()) {
		mp[str] = int(mp.size());
	}
	return mp[str];
}

void cal_next(int a[], int n) {
	next[0] = next[1] = 0;
	for(int i = 1; i < n; i++) {
		int j = next[i];
		while(j && a[j] != a[i]) {
			j = next[j];
		}
		next[i+1] = (a[i] == a[j]) ? j+1 : 0;
	}
}

// 在a里面查找b.
int match(int a[], int n, int b[], int m) {
	int ans = 0;
	for(int i = 0, j = 0; i < n; i++) {
		while(j && a[i] != b[j]) {
			j = next[j];
		}
		j += a[i] == b[j];
		if(j == m) {
			j = 0;
			ans++;
		}
	}
	return ans;
}


int main()
{
	int n;
	while(std::cin >> n) {
		memset(len, 0, sizeof(len));
		for(int i = 0; i < n; i++) {
			std::string buff;
			std::cin >> buff;
			num[i] = get_id(buff);
			len[i] = buff.length();
		}

		//for(int i = 0; i < n; i++) {
			//std::cout << i << ": " << num[i] << " " << len[i] << std::endl;
		//}

		int sum = n-1;
		for(int i = 0; i < n; i++) {
			sum += len[i];
		}

		int ans = sum;
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				cal_next(num+i, j-i+1);
				int cnt = match(num, n, num+i, j-i+1);
				if(cnt >= 2) {
					int tot = j-i;
					for(int k = i; k <= j; k++) {
						tot += len[k] - 1;
					}
					ans = std::min(ans, sum - tot*cnt);
				}
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
