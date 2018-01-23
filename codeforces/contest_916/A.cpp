#include<bits/stdc++.h>

bool check_luck(int x) {
	while(x) {
		if(x%10 == 7) {
			return true;
		}
		x /= 10;
	}
	return false;
}

int main() 
{
	int x, hh, mm;
	while(std::cin >> x >> hh >> mm) {
		int ans = 0;
		
		while(!(check_luck(hh) || check_luck(mm))) {
			ans++;
			mm -= x;
			if(mm < 0) {
				mm += 60;
				hh--;
				if(hh < 0) {
					hh += 24;
				}
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
