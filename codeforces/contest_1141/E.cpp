#include<bits/stdc++.h>

using LL = long long;
LL H[200200], sum[200200];

int main()
{
    LL n,HP;
    while(std::cin >> HP >> n) {
        memset(sum, 0, sizeof(sum));
        LL  minn = 1000000;
        for(int i = 1; i <= n; i++) {
            std::cin >> H[i];
            sum[i] = sum[i-1] + H[i];
            minn = std::min(minn, sum[i]);
        }

        if(HP+minn <= 0) {
            LL ans = 0;
            for(int i = 1; i <= n; i++) {
                if(HP+sum[i] <= 0) {
                    ans = i;
                    break;
                }
            }
            std::cout << ans << std::endl;
            continue;
        }

        if(sum[n] >= 0) {
            std::cout << -1 << std::endl;
            continue;
        }


        LL lun =(HP+minn) / std::llabs(sum[n]);
        if((HP+minn) % std::llabs(sum[n]) != 0) {
            lun++;
        }

        LL ans = n*lun;
        HP += lun*sum[n];
        if(HP > 0) {
            LL ret = 0;
            for(int i = 1; i <= n; i++) {
                if(HP + sum[i] <= 0) {
                    ret = i;
                    break;
                }
            }
            ans += ret;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
