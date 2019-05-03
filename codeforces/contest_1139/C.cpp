#include<bits/stdc++.h>

using LL = long long;
const LL mod = 1000000007LL;

int fa[200200], size[200200];
int find(int x) {return fa[x] !=x ? find(fa[x]) : fa[x];}

LL pow_mod(LL a, LL b) {
    LL ans = 1LL;
    while(b > 0) {
        if(b%2 == 1) {
            ans = (ans*a) % mod;
        }
        a = (a*a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n, k;
    while(std::cin >> n >> k) {
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
        }

        for(int i = 1; i < n; i++) {
            int x, y, z;
            std::cin >> x >> y >> z;
            if(z == 0) {
                int tx = find(x);
                int ty = find(y);
                if (tx != ty) {
                    fa[tx] = ty;
                    size[ty] += size[tx];
                }
            }
        }

        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            if(find(i) == i) {
                ans = (ans + pow_mod(size[i], k)) % mod;
            }
        }

        ans = (pow_mod(n, k) - ans + mod) % mod;
        std::cout << ans << std::endl;
    }
    return 0;
}

