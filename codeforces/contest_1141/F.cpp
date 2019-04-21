#include<bits/stdc++.h>

using LL = long long;

int num[2000];
std::vector<std::pair<int, int> > vec;
std::map<int, std::vector<std::pair<int, int> > > ret;

int main()
{
    int n;
    while(std::cin >> n) {
        ret.clear();
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
            int sum = 0;
            for(int j = i; j >= 1; j--) {
                sum += num[j];
                ret[sum].push_back(std::make_pair(j,i));
            }
        }

        vec.clear();
        for(auto s : ret) {
            std::vector<std::pair<int,int> > tmp;
            int lastIndex = 0;
            for(auto pp : s.second) {
                if(pp.first > lastIndex) {
                    lastIndex = pp.second;
                    tmp.push_back(std::make_pair(pp.first, pp.second));
                }
            }

            if(vec.size() < tmp.size()) {
                vec = tmp;
            }
        }

        std::cout << vec.size() << std::endl;
        for(auto s: vec) {
            std::cout << s.first << " " << s.second << std::endl;
        }
    }
    return 0;
}
