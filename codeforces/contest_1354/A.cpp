#include<bits/stdc++.h>

using LL = long long;

int main()
{
    LL a, b, c, d;
    LL T;
    std::cin >> T;
    while(T--) {
        std::cin >> a >> b >> c >> d;
        if(b >= a) {
            std::cout << b << std::endl;
            continue;
        }

        if(c <= d) {
            std::cout << -1 << std::endl;
            continue;
        }

        LL ans = b + (a-b) /(c-d)*c;

        if((a-b)%(c-d) != 0) {
            ans += c;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
