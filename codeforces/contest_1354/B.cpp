#include<bits/stdc++.h>

const int INF = 100000000;

int main() 
{
    int T;
    std::string str;
    std::cin >> T;
    while(T--) {
        int last1 = -1, last2 = -1, last3 = -1;
        int ans = INF;
        std::cin >> str;

        for(auto i = 0; i < int(str.length()); i++) {
            if(str[i] == '1') {
                if(last2 != -1 && last3 != -1) {
                    ans = std::min(ans, i- std::min(last2, last3)+1);
                }
                last1 = i;
            }else if(str[i] == '2') {
                if(last1 != -1 && last3 != -1) {
                    ans = std::min(ans, i - std::min(last1, last3)+1);
                }
                last2 = i;
            } else {
                if(last1 != -1 && last2 != -1) {
                    ans = std::min(ans, i - std::min(last1, last2) + 1);
                }
                last3 = i;
            }
        }

        if(ans == INF) {
            ans = 0;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
