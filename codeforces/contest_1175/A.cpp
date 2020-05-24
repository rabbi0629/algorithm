#include<bits/stdc++.h>

using LL = long long int;

int main()
{
    int T;
    std::cin >> T;
    while(T--) {
        LL n, k;
        std::cin >> n >> k;
        LL ans = 0;
        while(n > 0) {
            LL mod = n%k;
            if(mod > 0) {
                ans += mod;
                n -= mod;
            }

            if(n > 0) {
                n /= k;
                ans++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
