#include<bits/stdc++.h>

using LL = long long;
LL num[300300],pre[300300];

int main()
{
    int n;
    while(std::cin >> n) {
        memset(pre, 0, sizeof(pre));
        LL minn = 0, minx = 1;
        for(int i = 2; i <= n; i++) {
            std::cin >> num[i];
            pre[i] = pre[i-1] + num[i];
            if(minn > pre[i]) {
                minn = pre[i];
                minx = i;
            }
        }

        int xx = 1 - minn;
        std::map<LL, int> mp;
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            pre[i] += xx;
            if(mp.find(pre[i]) != mp.end() || pre[i] > n || pre[i] <= 0) {
                ok = false;
                break;
            }
            mp[pre[i]] = i;
        }

        if(!ok) {
            std::cout << -1 << std::endl;
            continue;
        }

        for(int i = 1; i <= n; i++) {
            std::cout << pre[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
