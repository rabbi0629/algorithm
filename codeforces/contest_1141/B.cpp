#include<bits/stdc++.h>

int num[500100];

int main() 
{
    int n;
    while(std::cin >> n) {
        for(int i = 0; i < n; i++) {
            std::cin >> num[i];
        }

        for(int i = n; i < 2*n; i++) {
            num[i] = num[i-n];
        }

        int ans = 0;
        int i = 0;
        while(i < 2*n) {
            while(num[i] == 0) {
                i++;
                continue;
            }

            if(i >=2*n) {
                break;
            }

            int j = i+1;
            while(j < 2*n && num[j] == 1)j++;
            ans = std::max(ans, j-i);
            i=j;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
