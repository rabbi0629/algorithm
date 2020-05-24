#include<bits/stdc++.h>

int main()
{
    int T;
    int n, a, b;
    std::cin >> T;
    while(T--) {
        std::cin >> n >> a >> b;
        std::string ans;
        for(int i = 0; i < b; i++) {
            ans += 'a'+ i;
        }

        for(int i = b; i < a; i++) {
            ans += 'a';
        }

        int index = 0;

        for(int i = a; i < n; i++) {
            ans += ans[index];
            index = (index+1) % a;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
