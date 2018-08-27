#include<bits/stdc++.h>

int num[100100];

int main()
{
	int n;
	while(std::cin >> n) {
		memset(num, 0, sizeof(num));
		 int Index = sqrt(n);
        int tmp = 1;
        int Min = n;
        for(int i = n - Index; i >= 0; i -= Index) {
            Min = i;
            for(int j = 0; j < Index; ++j) {
                num[i + j] = tmp++;
            }
        }
        for(int i = 0; i < Min; ++i) {
            num[i] = tmp++;
        }

		for(int i = 0; i < n; i++) {
			std::cout << num[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
