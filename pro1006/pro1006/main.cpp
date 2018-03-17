#include <iostream>
using namespace std;
int main() {
	int input, a, b, c;
	cin >> input;
	a = input / 100;
	for (int i = 0; i < a; i++) {
		cout << 'B';
	}
	input %= 100;
	b = input / 10;
	for (int i = 0; i < b; i++) {
		cout << 'S';
	}
	input %= 10;
	c = input;
	for (int i = 0; i < c; i++) {
		cout << i + 1;
	}
	return 0;
}