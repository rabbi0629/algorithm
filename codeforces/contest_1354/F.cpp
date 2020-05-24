#include<bits/stdc++.h>

struct PP {
    int a;
    int b;
    int id;
};

bool cmp(const PP &a, const PP &b) {
    return a.b < b.b;
}

PP p[100];
int dp[100][100], path[100][100];
bool chosed[100];


int main()
{
    int T, n, m;
    std::cin >> T;
    while(T--) {
        std::cin >> n >> m;

        for(int i = 1; i <= n; i++) {
            std::cin >> p[i].a >> p[i].b;
            p[i].id = i;
        }

        std::sort(p+1, p+n+1, cmp);

        memset(dp, -1, sizeof(dp));
        memset(chosed, false, sizeof(chosed));
        memset(path, -1, sizeof(path));

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n && j <= m; j++) {
                if(dp[i-1][j] != -1) {
                    dp[i][j] = dp[i-1][j] + p[i].b *(m-1);
                }

                if(j > 0 && dp[i-1][j-1] != -1) {
                    if(dp[i][j] < dp[i-1][j-1] + p[i].a + p[i].b * (j-1)) {
                        dp[i][j] = dp[i-1][j-1] + p[i].a + p[i].b *(j-1);
                        path[i][j] = 1;
                    }
                }
            }
        }

        std::cout << m + (n-m) *2 << std::endl;

        for(int i= n, j = m; i > 0; i--) {
            if(path[i][j] != -1) {
                chosed[p[i].id] = true;
                j--;
            }
        }

        std::vector<int> ans;

        int num = 0;
        for(int i = 1; i <= n; i++) {
            if(chosed[p[i].id]) {
                num++;
                if(num == m) {
                    num = p[i].id;
                    break;
                }
                ans.push_back(p[i].id);
            }
        }

        for(int i = 1; i <= n; i++) {
            if(!chosed[p[i].id]) {
                ans.push_back(p[i].id);
                ans.push_back(-p[i].id);
            }
        }

        ans.push_back(num);

        for(auto s : ans) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
