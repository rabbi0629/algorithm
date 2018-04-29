#include<bits/stdc++.h>

using LL = long long;

int A[1010], B[1010];

int main()
{
	int n, k1, k2;
	while(std::cin >> n >> k1 >> k2) {
		for(int i = 1; i <= n; i++) {
			std::cin >> A[i];
		}

		for(int i = 1; i <= n; i++) {
			std::cin >> B[i];
		}

		std::multiset<std::tuple<int, int, int> > st;
		for(int i = 1; i <= n; i++) {
			int delta = std::abs(A[i] - B[i]);
			st.insert(std::make_tuple(delta, A[i], B[i]));
		}

		//std::cout << "size: " << st.size() << std::endl;

		for(int i = 1; i <= k1; i++) {
			auto it = --st.end();
			auto tmp = *it;
			st.erase(it);
			
			auto delta = std::get<0>(tmp);
			auto a = std::get<1>(tmp);
			auto b = std::get<2>(tmp);
			if(a < b) {
				a++;
			} else {
				a--;
			}

			delta = std::abs(a - b);
			st.insert(std::make_tuple(delta, a, b));
		}
		
		for(int i = 1; i <= k2; i++) {
			auto it = --st.end();
			auto tmp = *it;
			st.erase(it);

			auto delta = std::get<0>(tmp);
			auto a = std::get<1>(tmp);
			auto b = std::get<2>(tmp);

			if(a < b) {
				b--;
			} else {
				b++;
			}
			delta = std::abs(a - b);
			st.insert(std::make_tuple(delta, a, b));
		}

		LL ans = 0;
		//std::cout << st.size() << std::endl;
		for(auto it = st.begin(); it != st.end(); it++) {
			//std::cout << "debug " << std::get<0>(*it) << " " << std::get<1>(*it) << " " << std::get<2>(*it) << std::endl;
			auto tmp = std::get<0>(*it);
			ans += (LL)tmp * (LL)tmp;
		}

		std::cout << ans << std::endl;
	}
	return 0;
}
