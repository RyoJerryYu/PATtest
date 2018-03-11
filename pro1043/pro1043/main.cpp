#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	const char PATest[6] = { 'P','A','T','e','s','t' };
	string input;
	int count[128] = { 0 };
	cin >> input;
	for (char x : input)count[x]++;
	int res = 6;
	while (res) {
		for (int i = 0; i < 6; i++) {
			if (count[PATest[i]] > 0) {
				cout << PATest[i];
				count[PATest[i]]--;
			}
			if (count[PATest[i]] == 0) {//考虑初值为0，不能放到上一个if中
				res--;
				count[PATest[i]]--;//用-1储存状态，只会进一次if
			}
		}
	}
	cout << endl;
	return 0;
}