#include <iostream>
#include <string>
using namespace std;
int main1() {
	int N;
	char c;
	cin >> N >> c;
	string a = "", b = "";
	for (int i = 0; i < N; i++)a += c;
	b += c;
	for (int i = 1; i < N - 1; i++)b += " ";
	b += c;
	cout << a << endl;
	for (int i = 1; i < (N + 1) / 2 - 1; i++)cout << b << endl;
	cout << a << endl;
	return 0;
}