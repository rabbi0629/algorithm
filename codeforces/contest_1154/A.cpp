#include<bits/stdc++.h>

using LL = long long;

LL num[10];

int main()
{
    while(std::cin >> num[0] >> num[1] >> num[2] >> num[3]) {
        LL sum = 0;
        for(int i = 0; i < 4; i++) {
            sum += num[i];
        }

        sum /= 3; 
        for(int i = 0; i < 4; i++) {
            if(sum == num[i]) {
                continue;
            }
            std::cout << sum - num[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
