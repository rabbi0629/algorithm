#include<bits/stdc++.h>
using LL = long long;

LL num[100100];

int main()
{
    LL n;
    while(std::cin >> n) {
        num[0] = 0;
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
        }

        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            if(num[i] > num[i-1]) {
                ans += (num[i]-num[i-1])*(n-num[i]+1);
            }else if(num[i] < num[i-1]) {
                ans += (num[i-1] - num[i]) * num[i];
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
