#include<bits/stdc++.h>

using LL = long long;

int main()
{
    int T;
    std::cin >> T;
    while(T--) {
        LL n;
        std::cin >> n;

        bool flag = false;
        int ansA, ansB, ansC;

        for(LL i = 2; i*i <= n; i++) {
            if(n%i) {
                continue;
            }

            LL y = n/i;
            for(LL j = 2; j*j < y; j++) {
                if(y%j != 0 || j == i || y/j == i) {
                    continue;
                }

                ansA = i;
                ansB = j;
                ansC = y/j;
                flag = true;
                break;
            }
        }

        if(!flag) {
            std::cout << "NO" << std::endl;
            continue;
        }

        std::cout << "YES" << std::endl;
        std::cout << ansA << " " << ansB << " " << ansC << std::endl;
    }
    return 0;
}
