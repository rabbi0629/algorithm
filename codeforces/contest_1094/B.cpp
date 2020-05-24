#include<bits/stdc++.h>

int main() 
{
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int> > pp;
        for(int i = 1; i <= n; i++) {
            int x, y;
            std::cin >> x >> y;
            pp.push_back(std::make_pair(y, x));
        }

        std::sort(pp.begin(), pp.end());
        bool flag = true;
        std::string ans = "";
        int curX = 0;
        int curY = 0;

        for(int i = 0; i < n; i++) {
            if(curX > pp[i].second) {
                flag = false;
                break;
            }

            while(curX < pp[i].second) {
                curX++;
                ans += "R";
            }

            while(curY < pp[i].first) {
                curY++;
                ans += "U";
            }
        }

        if(!flag) {
            std::cout << "NO" << std::endl;
            continue;
        }

        std::cout << "YES" << std::endl;
        std::cout << ans << std::endl;
    }
    return 0;
}
