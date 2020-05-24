#include<bits/stdc++.h>


const int N = 2e5 + 10;
char strs[50][50];
int pos[10]={0,1,4,7,2,5,8,3,6,9};
int main()
{
    int T;
    std::cin >> T;
    while(T--) {
        for(int i = 1; i <= 9; i++) {
            scanf("%s", strs[i]);
        }

        for(int i = 1; i <= 9; i++) {
            if(strs[i][pos[i]-1] == '1') {
                strs[i][pos[i]-1]++;
            } else {
                strs[i][pos[i]-1]--;
            }

        }

        for(int i = 1; i <= 9; i++) {
            std::cout << strs[i] << std::endl;
        }
    }
	return 0;
}
