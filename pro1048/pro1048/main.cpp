#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int count = 1;
	int sub;
	string n1, n2;
	string res = "";
	cin >> n1 >> n2;
	auto p1 = n1.rbegin();
	auto p2 = n2.rbegin();
	auto p1end = n1.rend();
	auto p2end = n2.rend();
	while (p1 != p1end && p2 != p2end) {
		int c1 = *p1 - '0';
		int c2 = *p2 - '0';
		if (count % 2 == 1) {
			sub = (c1 + c2) % 13;
			if (sub == 10)res.push_back('J');
			else if (sub == 11)res.push_back('Q');
			else if (sub == 12)res.push_back('K');
			else res.push_back((char)(sub + '0'));
		}
		else {
			sub = (c2 - c1);
			if (sub < 0)sub += 10;
			res.push_back((char)(sub + '0'));
		}
		count++;
		p1++;
		p2++;
	}
	while (p2 != p2end) res.push_back(*(p2++));
	reverse(res.begin(), res.end());
	cout << res << endl;
}