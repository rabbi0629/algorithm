#include<bits/stdc++.h>

int main()
{
    int n, k;
    while(std::cin >> n >> k) {
        if( k == 1 || k == n ) {
            std::cout << 3*n << std::endl;
            continue;
        }

        std::cout << 3*n + std::min(k-1, n-k) << std::endl;
    }
    return 0;
}
