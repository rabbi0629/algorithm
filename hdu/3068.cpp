#include<bits/stdc++.h>

// manacher算法参考: https://www.cnblogs.com/tenosdoit/p/3675788.html

const int maxn = 120000;
char str[maxn], ma[2*maxn];
int mp[2*maxn];

int main()
{
    while(~scanf("%s", str)) {
        int len = strlen(str);
        int L = 0;
        ma[L++] = '$';
        ma[L++] = '#';
        for(int i = 0; i < len; i++) {
            ma[L++] = str[i];
            ma[L++] = '#';
        }

        ma[L] = 0;

        int mx = 0,id = 0;
        for(int i = 0; i < L; i++) {
            mp[i] = mx>i ? std::min(mx -i, mp[2*id-i]):1;
            while(ma[i-mp[i]] == ma[i+mp[i]]) {
                mp[i]++;
            }

            if(i+mp[i] > mx) {
                mx = i + mp[i];
                id = i;
            }
        }

        int maxx = -1;
        for(int i = 0; i < L; i++) {
            maxx = std::max(maxx, mp[i]);
        }

        std::cout << maxx - 1 << std::endl;
    }
    return 0;
}
