#include<bits/stdc++.h>

using LL = long long;

int main()
{
    LL n, m;
    while(std::cin >> n >> m) {
        if(m%n != 0) {
            std::cout << -1 << std::endl;
        } else if(m == n)  {
            std::cout << 0 << std::endl;
        }else {
            auto d = m/n;
            int ans = 0;
            while(d%3 == 0) {
                ans++;
                d /= 3;
            }

            while(d%2 == 0) {
                ans++;
                d /= 2;
            }
            if(d != 1) {
                ans = -1;
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
