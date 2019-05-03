#include<bits/stdc++.h>

int food[7] = {1,1,2,3,1,3,2};

int main()
{
    int a, b, c;
    while(std::cin >> a >> b >> c) {
        int dayCnt = 0;
        int weekCnt = std::min(a / 3, std::min(b / 2, c / 2));
        dayCnt += weekCnt*7;
        a -= 3*weekCnt;
        b -= 2*weekCnt;
        c -= 2*weekCnt;

        int maxx = 0;
        for(int i = 0; i < 7; i++) {
            int A = a;
            int B = b;
            int C = c;
            int cnt = 0;
            for(int j = i; j < 20; j++) {
                if(food[j%7] == 1 && A > 0) {
                    A--;
                    cnt++;
                } else if(food[j%7] == 2 && B > 0) {
                    B--;
                    cnt++;
                } else if(food[j%7] == 3 && C > 0) {
                    C--;
                    cnt++;
                } else {
                    break;
                }
            }
            maxx = std::max(maxx, cnt);
        }
        dayCnt += maxx;
        std::cout << dayCnt << std::endl;
    }
    return 0;
}
