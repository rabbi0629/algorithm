#include<bits/stdc++.h>

int num[110];

int main()
{
    int n;
    while(std::cin >> n) {
        int maxx = -1000, minn = 1000;
        for(int i = 0; i < n; i++) {
            std::cin >> num[i];
            maxx = std::max(maxx, num[i]);
            minn = std::min(minn, num[i]);
        }

        if(maxx == minn) {
            std::cout << 0 << std::endl;
            continue;
        }

        int ans = (maxx - minn)%2 ? maxx - minn: (maxx - minn) / 2;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(num[i] == maxx || num[i] == minn) {
                continue;
            }
            if(num[i] != minn + ans && num[i] != maxx - ans) {
                ok = false;
                break;
            }
        }

        if(ok) {
            std::cout << ans << std::endl;
            continue;
        }
        std::cout << -1 << std::endl;
    }
    return 0;
}
