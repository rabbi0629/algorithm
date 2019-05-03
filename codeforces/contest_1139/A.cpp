#include<bits/stdc++.h>

int main()
{
    std::string str;
    int n;
    while(std::cin >> n) {
        std::cin >> str;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if((str[i]-'0')%2 == 0) {
                ans += i+1;
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
