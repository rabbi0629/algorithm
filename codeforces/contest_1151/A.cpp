#include<bits/stdc++.h>

int main()
{
    int n;
    std::string str;
    while(std::cin >> n) {
        std::cin >> str;
        int ans = 1000000000;
        for(int i = 0; i+3  < n; i++) {
            int cnt = 0;
            auto det = abs(str[i]-'A');
            cnt += std::min(det, 26-det);

            det = abs(str[i+1]-'C');
            cnt += std::min(det, 26-det);

            det = abs(str[i+2] -'T');
            cnt += std::min(det, 26-det);

            det = abs(str[i+3] - 'G');
            cnt += std::min(det, 26-det);

            ans = std::min(ans, cnt);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
