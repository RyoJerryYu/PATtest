#include <iostream>
#include <string>
using namespace std;
int main() {
	const string pinyin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	string input;
	string output;
	cin >> input;
	int sum = 0;
	for (char x : input) {
		sum += x - '0';
	}
	output = to_string(sum);
	for (unsigned i = 0; i < output.size() - 1; i++) {
		cout << pinyin[output[i] - '0'] << ' ';
	}
	cout << pinyin[output[output.size() - 1] - '0'] << endl;
}