#include<bits/stdc++.h>

char str[1010][1010];
int left[1010][1010], right[1010][1010],up[1010][1010], down[1010][1010];
int col[1010][1010],row[1010][1010];

struct Item {
	int row;
	int col;
	int len;
	Item(int _row, int _col, int _len): row(_row), col(_col), len(_len) {}
};


int main()
{
	int n, m;
	while(std::cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			scanf("%s", str[i]+1);
		}
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));

		std::vector<Item> ans;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(str[i][j] == '*') {
					left[i][j] = left[i][j-1] + 1;
					up[i][j] = up[i-1][j] + 1;
				}
			}
		}

		for(int i = n; i >= 1; i--) {
			for(int j = m; j >= 1; j--) {
				if(str[i][j] == '*') {
					right[i][j] = right[i][j+1] + 1;
					down[i][j] = down[i+1][j] + 1;
				}
			}
		}

		for(int i = 2; i < n; i++) {
			for(int j = 2; j < m; j++) {
				if(str[i][j] != '*') {
					continue;
				}
				int mi = std::min(std::min(left[i][j], right[i][j]), std::min(up[i][j], down[i][j]))-1;
				if(mi > 0) {
					Item item = Item(i, j, mi);
					ans.push_back(item);
					row[i][j-mi]++;
					row[i][j+mi+1]--;
					col[i-mi][j]++;
					col[i+mi+1][j]--;
				}
			}
		}


		//std::cout << "debug begin" << std::endl;
		//std::cout << ans.size() << std::endl;
		//for(auto s:ans) {
			//std::cout << s.row << " " << s.col << " " << s.len << std::endl;
		//}

		//std::cout << left[3][5] << " " << right[3][5] << " " << up[3][5] << " " << down[3][5] << std::endl;
		//std::cout << "debug end" << std::endl;

		bool ok = true;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				row[i][j] += row[i][j-1];
				col[i][j] += col[i-1][j];
				if(str[i][j] != '*') {
					continue;
				}

				//std::cout << "debug " << i << " " << j << " " << str[i][j] << " " << row[i][j] << " " << col[i][j] << std::endl;
				if(row[i][j] + col[i][j] == 0) {
					ok = false;
					break;
				}
			}
		}

		//std::cout << "ok: " << ok << std::endl;

		if(!ok) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << ans.size() << std::endl;
		for(auto s:ans) {
			std::cout << s.row << " " << s.col << " " << s.len << std::endl;
		}
	}
	return 0;
}
