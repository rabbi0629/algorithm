#include<bits/stdc++.h>

using LL = long long;

std::pair<LL, LL> point[100100];
int n, belong[100100], line[100100];

bool is_one_line(std::pair<LL, LL> p1, std::pair<LL, LL> p2, std::pair<LL, LL> p3) {
	auto t1 = std::make_pair(p2.first - p1.first, p2.second - p1.second);
	auto t2 = std::make_pair(p3.first - p1.first, p3.second - p1.second);
	auto result = t1.first * t2.second - t2.first * t1.second;
	return result == 0;
}

bool check(int i1, int i2) {
	memset(belong, -1, sizeof(belong));
	belong[i1] = belong[i2] = 0;
	for(int i = 1; i <= n; i++) {
		if(i == i1 || i == i2) {
			continue;
		}
		if(is_one_line(point[i1], point[i2], point[i])) {
			belong[i] = 0;
		}
	}

	int cnt = 0;

	for(int i = 1; i <= n; i++) {
		if(belong[i] == -1) {
			line[cnt++] = i;
		}
	}
	for(int i = 2; i < cnt; i++) {
		if(!is_one_line(point[line[0]], point[line[1]], point[line[i]])) {
			return false;
		}
	}
	return true;
}

int main() 
{
	while(std::cin >> n) {
		for(int i = 1; i <= n; i++) {
			std::cin >> point[i].first >> point[i].second;
		}
		
		if(n < 5) {
			std::cout << "YES" << std::endl;
			continue;
		}

		if(check(1, 2) || check(1, 3) || check(2, 3)) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
