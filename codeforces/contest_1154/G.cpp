#include<bits/stdc++.h>
const int N = 10000100;
using LL = long long;
const LL INF = 10000000000000000LL;
int num[2002000], pos[10001000];

int main() 
{
    int n;
    while(std::cin >> n) {
        memset(pos, 0, sizeof(pos));
        auto ans = std::make_pair(INF, std::make_pair(-1,-1));
        int mx = -1;
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
            mx = std::max(mx, num[i]);
            if(pos[num[i]] != 0) {
                if(ans.first > num[i]) {
                    ans = std::make_pair(num[i], std::make_pair(pos[num[i]], i));
                }
            }
            pos[num[i]] = i;
        }

        for(int i = 1; i <= mx; i++) {
            LL x = 0;
            for(int j = i; j <= mx; j += i) {
                if(pos[j] == 0) {
                    continue;
                }
                if(x > 0 && ans.first > (LL)x*(LL)j/i) {
                    ans = std::make_pair((LL)x*(LL)j/i, std::make_pair(pos[x], pos[j]));
                }
                x = j;
            }
        }

        if(ans.second.first > ans.second.second) {
            std::swap(ans.second.first, ans.second.second);
        }

        std::cout << ans.second.first << " " << ans.second.second << std::endl;
    }
    return 0;
}
