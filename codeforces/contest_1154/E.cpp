#include<bits/stdc++.h>
const int maxn = 200200;

int rfa[maxn], lfa[maxn], mark[maxn], num[maxn];
std::set<int, std::greater<int> > st;
std::map<int, int> pos;
int n, k;

void rm(int p, int col) {
    lfa[rfa[p]] = lfa[p];
    rfa[lfa[p]] = rfa[p];
    st.erase(num[p]);
    mark[p] = col;
}

int main() 
{
    while(std::cin >> n >> k) {
        st.clear();
        memset(mark, -1, sizeof(mark));
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
            st.insert(num[i]);
            pos[num[i]] = i;
            lfa[i] = i-1;
            rfa[i] = i+1;
        }

        int cnt = n;

        auto col = 1;
        while(cnt > 0) {
            auto it = st.begin();
            auto p = pos[*it];
            cnt--;
            rm(p, col);

            for(int i = rfa[p],cnt1 = 0; cnt1 < k && i <=n;cnt1++, i = rfa[i]) {
                cnt--;
                rm(i, col);
            }

            for(int i = lfa[p],cnt1 = 0; cnt1 < k && i >=1; cnt1++, i = lfa[i]) {
                cnt--;
                rm(i, col);
            }
            col = 3-col;
        }

        std::string ans;
        for(int i = 1; i <= n; i++) {
            if(mark[i] == 1) {
                ans += "1";
            } else {
                ans += "2";
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
