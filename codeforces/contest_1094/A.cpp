#include<bits/stdc++.h>

using LL = long long;

int main()
{
    LL n, a, b, c;
    int T;
    std::cin >> T;
    while(T--) {
        std::cin >>  a >> b >> c >> n;
        LL sum = n + a + b + c;
        if(sum%3 != 0) {
            std::cout << "NO" << std::endl;
            continue;
        }

        LL avr = sum / 3;
        if(avr < a || avr < b || avr < c) {
            std::cout << "NO" << std::endl;
            continue;
        }
        
        std::cout << "YES" << std::endl;
    }
    return 0;
}
