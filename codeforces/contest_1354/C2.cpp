#include<bits/stdc++.h>

const double pi = acos(-1.0);

int main()
{
    int n, T;
    std::cin >> T;
    while(T--) {
        std::cin >> n;
        printf("%.6f\n", 0.5/sin(pi/(4*n)));
    }
    return 0;
}
