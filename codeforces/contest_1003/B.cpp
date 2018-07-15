#include<bits/stdc++.h>

bool get(int a, int b, int x, std::string &str) {
	char tmp = str[0];
	while(x>0) {
		if(tmp == '0' && b>0) {
			b--;
			tmp = '1';
			str += tmp;
			x--;
		} else if(tmp == '1' && a > 0) {
			a--;
			tmp = '0';
			str += tmp;
			x--;
		} else {
			return false;
		}
	}

	//std::cout << "str : " << str << " " << a << " " << b << std::endl;

	if(a > 0) {
		auto pos = str.find("0");
		//std::cout << "pos: " << pos << std::endl;
		std::string s1 = str.substr(0, pos+1);
		std::string s2 = str.substr(pos+1);
		std:: string s3 = std::string(a, '0');
		//std::cout << "debug1:" << s1 << " " << s2 << " " << s3 << std::endl;
		str = s1 + s3 + s2;
	}

	//std::cout << "debug2: " << str << std::endl;

	if(b > 0) {
		auto pos = str.find("1");
		std::string s1 = str.substr(0, pos+1);
		std::string s2 = str.substr(pos+1);
		std::string s3 = std::string(b, '1');
		//std::cout << "debug3:" << s1 << " " << s2 << " " << s3 << std::endl;
		str = s1 + s3 + s2;
	}
	return true;
}

int main()
{
	int a, b, x;
	while(std::cin >> a >> b >> x) {
		std::string str = "";
		str = "1";
		bool ok = get(a, b-1, x, str);
		if (ok) {
			std::cout << str << std::endl;
			continue;
		}

		//std::cout << "##################################" << std::endl;

		str = "0";
		ok = get(a-1, b, x, str);
		if (ok) {
			std::cout << str << std::endl;
			continue;
		}
	}
	return 0;
}
