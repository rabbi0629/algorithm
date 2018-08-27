#include<bits/stdc++.h>

struct Stu {
	int score;
	int id;
}pp[10100];

bool cmp(const Stu &t1, const Stu &t2) {
	if(t1.score != t2.score) {
		return t1.score > t2.score;
	}
	return t1.id < t2.id;
}

int main()
{
	int n;
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			int a, b, c, d;
			std::cin >> a >> b >> c >> d;
			int sum = a + b + c + d;
			pp[i].id = i;
			pp[i].score = sum;
		}
		std::sort(pp+1, pp+n+1, cmp);
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(pp[i].id == 1) {
				ans = i;
				break;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
