#include<bits/stdc++.h>

int num[200200];

int main()
{
    int n, b, a;
    while(std::cin >> n >> b >> a) {
        for(int i = 1; i <= n; i++) {
            std::cin >> num[i];
        }

        int ans = 0;
        int B = b;
        int A = a;
        for(int i = 1; i <= n; i++) {
            if(num[i] == 1) {
                if(B > 0 && A < a) {
                    B--;
                    ans++;
                    A++;
                } else if(A > 0) {
                    A--;
                    ans++;
                } else {
                    break;
                }
            } else {
                if(A > 0) {
                    A--;
                    ans++;
                } else if(B > 0) {
                    B--;
                    ans++;
                } else {
                    break;
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
