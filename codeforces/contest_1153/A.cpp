#include<bits/stdc++.h>

std::pair<int, int> pp[20020];
int ww[100100];

int main()
{
    int n, t;
    while(std::cin >> n >> t) {
        memset(ww, 0, sizeof(ww));
        for(int i = 1; i <= n; i++) {
            std::cin >> pp[i].first >> pp[i].second ;
        }

        for(int i = 1; i <= n; i++) {
            if(pp[i].first >= t) {
                ww[i] = pp[i].first-t;
            } else {
                int tt = t-pp[i].first;
                if(tt % pp[i].second == 0) {
                    ww[i] = 0;
                } else {
                    ww[i] = (tt / pp[i].second + 1) * pp[i].second + pp[i].first - t;
                }
            }
        }

        int mx = 100000000, id = -1;
        for(int i = 1; i <= n; i++) {
            if(mx > ww[i]) {
                mx = ww[i];
                id = i;
            }
        }

        std::cout << id << std::endl;
    }
    return 0;
}
