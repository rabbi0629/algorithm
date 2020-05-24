#include<bits/stdc++.h>

int main()
{
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        std::map<int, int> mp;
        for(int i = 1; i <= n; i++) {
            int t;
            std::cin >> t;
            mp[t]++;
        }

        if(n == 1) {
            std::cout << 0 << std::endl;
            continue;
        }

        if(n == 2) {
            std::cout << 1 << std::endl;
            continue;
        }

        int disNum = 0;
        int maxCnt = 0;
        
        for(auto it: mp) {
            disNum++;
            maxCnt = std::max(maxCnt, it.second);
        }

        int ans = std::min(maxCnt, disNum-1);
        if(maxCnt > 1) {
            ans = std::max(ans, std::min(maxCnt-1, disNum));
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
