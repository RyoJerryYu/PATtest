#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string input = "";
	string res = "";
	char c;
	c = cin.get();
	while (c != '\n'&&c != '\0') {
		input += c;
		c = cin.get();
	}
	if (input.size() == 0)return 0;
	auto i = input.end();
	auto j = input.end();
	i--;
	while (j != input.begin()) {
		if (i == input.begin()) {
			res.insert(res.end(), i, j);
			j = i;
		}
		else if (*i == ' ') {
			res.insert(res.end(), i + 1, j);
			res.push_back(' ');
			j = i;
			i--;
		}
		else {
			i--;
		}
	}
	cout << res << endl;
	return 0;
}