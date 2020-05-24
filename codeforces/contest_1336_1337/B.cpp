#include<bits/stdc++.h>

int main()
{
    int T, n, m, s;
    std::cin >> T;
    while(T--) {
        std::cin >> s >> n >> m;
        while(s > 0) {
            if(n <= 0 && m <= 0) {
                break;
            }

            int p1 = s/2+10;
            int p2 = s - 10;
            if(n > 0 && m > 0) {
                if(p1 <= p2) {
                    s = p1;
                    n--;
                } else {
                    s = p2;
                    m--;
                }
            } else if(n > 0) {
                s = p1;
                n--;
            } else if (m > 0) {
                s = p2;
                m--;
            }
        }


        if(s <= 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
