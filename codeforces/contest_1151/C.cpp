#include<bits/stdc++.h>

using LL = long long;
const LL mod = 1000000007LL;

LL get(LL x) {
    LL ans = 0;
    LL a[2] = {0,0};
    int k = 0;
    LL cnt = 1;
    while(x > 0) {
        LL pp = std::min(x, cnt);
        a[k] = (a[k]+pp) % mod;
        x -= pp;
        k ^= 1;
        cnt <<= 1;
    }

    ans += a[0]*a[0]%mod;
    ans = (ans + (a[1]%mod+1)*a[1]%mod) % mod;
    return ans;
}

int main()
{
    LL l, r;
    while(std::cin >> l >> r) {
        std::cout << (get(r) - get(l-1) + mod) % mod << std::endl;
    }
    return 0;
}
