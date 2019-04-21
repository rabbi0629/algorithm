#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

const int maxn = 200200;

std::vector<int> edge[maxn];
int cnt;

int main()
{
    int n, q;
    while(std::cin >> n >> q) {
        for(int i = 1; i <= n; i++) {
            edge[i].clear();
        }

        for(int i = 2; i <= n; i++) {
            int xx;
            std::cin >> xx;
            edge[i].push_back(xx);
            edge[xx].push_back(i);
        }

        cnt = 0;

    }
    return 0;
}
