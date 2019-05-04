#include<bits/stdc++.h>

int mat[550][550], bit_mat[550][550];
int zero_cnt[550], val[550], pos[550];

int main()
{
    int n, m;
    while(std::cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                std::cin >> mat[i][j];
            }
        }

        std::vector<int> ans;

        for(int i = 0; i < 10; i++) {
            memset(bit_mat, 0, sizeof(bit_mat));
            memset(zero_cnt, 0, sizeof(zero_cnt));
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= m; k++) {
                    bit_mat[j][k] = (mat[j][k]>>i)&1;
                    if(bit_mat[j][k] == 0) {
                        zero_cnt[j]++;
                    }
                }
            }

            memset(val, -1, sizeof(val));
            memset(pos, -1, sizeof(pos));
            int cnt0 = 0, cnt1 = 0;
            for(int j = 1; j <= n; j++) {
                if(zero_cnt[j] == 0) {
                    val[j] = 1;
                    pos[j] = 1;
                    cnt1++;
                } else if(zero_cnt[j] == m) {
                    val[j] = 0;
                    pos[j] = 1;
                    cnt0++;
                }
            }

            if(cnt0 +cnt1 == n) {
                if(cnt1%2 == 1) {
                    for(int j = 1; j <= n; j++) {
                        ans.push_back(pos[j]);
                    }
                    break;
                }
                continue;
            }

            if(cnt1%2 == 0) {
                auto firstOne = 0;
                for(int j = 1; j <= n; j++) {
                    if(val[j] == -1) {
                        firstOne = j;
                        break;
                    }
                }

                for(int j = 1;j <= m; j++) {
                    if(bit_mat[firstOne][j] == 1) {
                        val[firstOne] =1;
                        pos[firstOne] = j;
                        break;
                    }
                }
            }

            for(int j = 1; j <= n; j++) {
                if(val[j] != -1) {
                    continue;
                }

                for(int k = 1; k <= m; k++) {
                    if(bit_mat[j][k] == 0) {
                        val[j] = 0;
                        pos[j] = k;
                        break;
                    }
                }
            }

            for(int j = 1; j <= n; j++) {
                ans.push_back(pos[j]);
            }
            break;
        }

        if(ans.size() == 0) {
            std::cout << "NIE" << std::endl;
            continue;
        }

        std::cout << "TAK" << std::endl;
        for(auto s:ans) std::cout << s << " ";std::cout << std::endl;
    }
    return 0;
}
