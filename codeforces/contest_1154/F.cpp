#include<bits/stdc++.h>

std::vector<int> num;
int pre[200200], dp[100100], offer[200200];
const int INF = 2147483647;

int main()
{
    int n, m, k;
    while(std::cin >> n >> m >> k) {
        num.clear();
        for(int i = 1; i <= n; i++) {
            int x;
            std::cin >> x;
            num.push_back(x);
        }

        std::sort(num.begin(), num.end());
        num.resize(k);
        std::reverse(num.begin(), num.end());
        memset(pre, 0, sizeof(pre));
        memset(offer, 0, sizeof(offer));

        for(int i = 1; i <= m; i++) {
            int x, y;
            std::cin >> x >> y;
            if(x <= k) {
                offer[x] = std::max(offer[x], y);
            }
        }

        for(int i = 0; i < k; i++) {
            pre[i+1] = pre[i] + num[i];
        }

        std::fill(dp+1, dp+k+1, INF);
        dp[0] = 0;
        for(int i = 0; i < k; i++) {
            dp[i+1] = std::min(dp[i+1], dp[i] + num[i]);
            for(int j = 1; j <= k && i + j <= k; j++) {
                if(offer[j] == 0 ) {
                    continue;
                }
                dp[i+j] = std::min(dp[i+j], dp[i] + pre[i+j-offer[j]] - pre[i]);
            }
        }

        std::cout << dp[k] << std::endl;
    }
    return 0;
}
