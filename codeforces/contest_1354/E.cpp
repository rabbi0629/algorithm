#include<bits/stdc++.h>

const int maxn = 5500;

int n, m;
std::vector<int> edge[maxn];
int n1, n2, n3;
int color[maxn];
bool dp[maxn][maxn];
bool ok = true;
int block = 0;
std::vector<int> cnt[maxn][3];
int ans[maxn];

bool dfs(int u, int col) {
    color[u] = col;
    cnt[block][col].push_back(u);
    for(auto v : edge[u]) {
        if(color[v] == 0) {
            if(!dfs(v, 3-col)) {
                return false;
            }
        } else if(color[v] == col) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cin >> n >> m;
    std::cin >> n1 >> n2 >> n3;
    for(int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            block ++;
            if(!dfs(i, 1)) {
                ok = false;
                break;
            }
        }
    }

    if(!ok) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    dp[0][0] = true;

    for(int i = 1; i <= block; i++) {
        int sz1 = cnt[i][1].size(), sz2 = cnt[i][2].size();
        for(int j = 0; j <= n2; j++) {
            if(j >= sz1) {
                dp[i][j] |= dp[i-1][j-sz1];
            }

            if(j >= sz2) {
                dp[i][j] |= dp[i-1][j-sz2];
            }
        }
    }

    if(!dp[block][n2]) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;
    for(int i = block; i>= 1; i--) {
        int sz1 = cnt[i][1].size(), sz2 = cnt[i][2].size();
             
        if(n2 >= sz1 && dp[i-1][n2-sz1]) {
            n2 -= sz1;
            for(int j = 0; j < sz1; j++) {
                ans[cnt[i][1][j]] = 2;
            }
        } else {
            n2 -= sz2;
            for(int j = 0; j < sz2; j++) {
                ans[cnt[i][2][j]] = 2;
            }
        }
    }

    std::string str = "";
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 2) {
            str += '2';
        } else if(n1 > 0) {
            n1--;
            str += '1';
        } else {
            str += '3';
        }
    }

    std::cout << str << std::endl;

    return 0;
}
