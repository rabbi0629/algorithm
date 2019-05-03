#include<bits/stdc++.h>

using LL = long long;
LL num[200200];

int main()
{
    int n;
    while(std::cin >> n) {
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
        }

        LL ans = num[n];
        for(int i = n-1; i >= 1; i--) {
            if(num[i] >= num[i+1]) {
                num[i] = std::max(0LL, num[i+1]-1);
            }
            ans += num[i];
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
