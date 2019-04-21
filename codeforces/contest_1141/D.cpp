#include<bits/stdc++.h>

char s1[200000],b[200000];
std::vector<int> LB[30], RB[30], LW, RW;

int main()
{
    int n;
    std::string L, R;
    while(std::cin >> n) {
        std::cin >> L;
        std::cin >> R;

        for(int i = 0; i < 26; i++) {
            LB[i].clear();
            RB[i].clear();
        }

        LW.clear();
        RW.clear();

        for(int i = 0; i < int(L.length()); i++) {
            if(L[i] == '?') {
                LW.push_back(i+1);
                continue;
            }
            LB[L[i]-'a'].push_back(i+1);
        }

        for(int i = 0; i < int(R.length()); i++) {
            if(R[i] == '?') {
                RW.push_back(i+1);
                continue;
            }
            RB[R[i]-'a'].push_back(i+1);
        }

        std::vector<std::pair<int,int> > ans;
        for(int i = 0; i < 26; i++) {
            int len = std::min(LB[i].size(), RB[i].size());
            for(int j = 0; j < len; j++) {
                ans.push_back(std::make_pair(LB[i][j], RB[i][j]));
            }

        }

        for(int i = 0; i < 26; i++) {
            int len = std::min(LB[i].size(), RB[i].size());
            if(int(LB[i].size()) == len) {
                for(int j = len; j < int(RB[i].size()) && !LW.empty(); j++) {
                    ans.push_back(std::make_pair(LW[LW.size()-1], RB[i][j]));
                    LW.pop_back();
                }
            } else{
                for(int j = len; j < int(LB[i].size()) && !RW.empty(); j++) {
                    ans.push_back(std::make_pair(LB[i][j], RW[RW.size()-1]));
                    RW.pop_back();
                }
             }
        }

        for(int i = 0; i < std::min(int(LW.size()), int(RW.size())); i++) {
            ans.push_back(std::make_pair(LW[i], RW[i]));
        }

        std::cout << ans.size() << std::endl;
        for(auto s : ans) {
            std::cout << s.first << " " << s.second << std::endl;
        }
    }
    return 0;
}
