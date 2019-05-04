#include<bits/stdc++.h>

using LL = long long;

std::pair<LL, LL> pp[100100];

bool cmp(std::pair<LL, LL> a, std::pair<LL, LL> b) {
    return a.first-a.second > b.first - b.second;
}

int main()
{
    int n;
    while(std::cin >> n) {
        for(int i = 1; i <= n; i++) {
            std::cin >> pp[i].first >> pp[i].second;
        }
        std::sort(pp+1, pp+n+1, cmp);

        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += pp[i].first *(i-1) + pp[i].second *(n-i);
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
