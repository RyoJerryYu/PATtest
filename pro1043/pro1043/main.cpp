#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char PATest[6] = { 'P','A','T','e','s','t' };
int main() {
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
				if (count[PATest[i]] == 0)res--;
			}
		}
	}
	cout << endl;
	return 0;
}
/*
if (count['P'] > 0) {
cout << 'P';
count['P']--;
if (count['F'] == 0)res--;
}
*/