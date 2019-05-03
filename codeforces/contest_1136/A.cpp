#include<bits/stdc++.h>

std::pair<int, int> ch[110];

int main() 
{
    int n,k;
    while(std::cin >> n) {
        for( int i = 1; i <= n; i++ ) {
            std::cin >> ch[i].first >> ch[i].second;
        }

        std::cin >> k;
        int index = 1;
        for(int i = 1; i <= n; i++) {
            if(ch[i].first <= k && ch[i].second >= k) {
                index = i;
                break;
            }
        }

        std::cout << n - index + 1 << std::endl;
    }
    return 0;
}
