#include<bits/stdc++.h>

char str[110][110];

int left[110][110], right[110][110], up[110][110], down[110][110];

int main() 
{
	int n, k;
	while(std::cin >> n >> k) {
		for(int i = 0; i < n; i++) {
			scanf("%s", str[i]);
		}
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(str[i][j] == '#') {
					left[i][j] = up[i][j] = 0;
				} else {
					up[i][j] = (i == 0) ? 1 : up[i-1][j] + 1;
					left[i][j] =(j == 0) ? 1 : left[i][j-1] + 1;
				}
			}
		}

		for(int i = n-1; i >= 0; i--) {
			for(int j = n-1; j >= 0; j--) {
				if(str[i][j] == '#') {
					right[i][j] = down[i][j] = 0;
				} else {
					right[i][j] = (j == n-1) ? 1 : right[i][j+1] + 1;
					down[i][j] = (i == n-1) ? 1 : down[i+1][j] + 1;
				}
			}
		}

		int max_num = 0;
		int ans_x = 0, ans_y = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(str[i][j] == '#') {
					continue;
				}
				
				int lenx = left[i][j] + right[i][j] - 1;
				int cnt = 1;
				if(lenx >= k) {
					int R = std::min(j + right[i][j] - 1, j + k -1);
					int L = std::max(j - left[i][j] + 1, j - k + 1) + k - 1;
					cnt += std::max(R - L + 1, 0);
					//std::cout << "cnt: " << cnt << std::endl;
				}

				int leny = up[i][j] + down[i][j] - 1;
				if(leny >= k) {
					int U = std::max(i - up[i][j] + 1, i - k + 1);
					int D = std::min(i + down[i][j] - 1, i + k - 1) - k + 1;
					cnt += std::max(1, D - U + 1);
				}
				//std::cout << "## " << i << " " << j << " " << cnt << " " << left[i][j] << " " << right[i][j] << " " << up[i][j] << " " << down[i][j] << std::endl;

				if(max_num < cnt) {
					max_num = cnt;
					ans_x = i;
					ans_y = j;
				}
			}
		}

		std::cout << ans_x + 1 << " " << ans_y + 1 << std::endl;
	}
	return 0;
}
