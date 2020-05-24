#include<bits/stdc++.h>

int s[200200][201];
std::vector<int> p[210];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 200; j++) {
                s[i][j] = 0;
            }
        }

        for(int i = 1; i <= 200; i++) p[i].clear();

        int v = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            v = std::max(v, x);
            p[x].push_back(i);

            for(int j = 1; j <= v; j++) {
                s[i][j] = s[i-1][j];
            }

            s[i][x]++;
        }

        int ans = 0;

        for(int i = 1; i <= v; i++) {
            if(p[i].size() == 0) {
                continue;
            }

            int l = 0, r = int(p[i].size()-1);
            ans = std::max(ans, r+1);

            while(l < r) {
                int c = 0;
                for(int j = 1; j <= v; j++) {
                    c = std::max(c, s[p[i][r]-1][j] - s[p[i][l]][j]);
                }
                ans = std::max(ans, c+2*l+2);
                l++,r--;
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
