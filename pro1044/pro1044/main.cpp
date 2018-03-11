#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
string tomarsnum(int);
string marstoi(string);
string marslow[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string marsup[13] = { "","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main() {
	string input;
	int n;
	cin >> n;
	cin.get();
	vector<string> res(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin.get(c);
		while (c != '\0'&&c != '\n') {
			input += c;
			cin.get(c);
		}
		//cin >> input;
		if ('0' <= *(input.begin()) && *(input.begin()) <= '9') {
			int num = stoi(input);
			res[i] = tomarsnum(num);
		}
		else {
			res[i] = marstoi(input);
		}
		input = "";
	}
	for (string x : res) {
		cout << x << endl;
	}
	return 0;
}
string tomarsnum(int it) {
	int marslower = it % 13;
	int marsupper = it / 13;
	string res = "";
	if (0 < marsupper&&marsupper < 13) {
		res += marsup[marsupper];
		res += " ";
	}
	res += marslow[marslower];
	return res;
}
string marstoi(string it) {
	string first = "", second = "";
	int res = 0;
	auto p = find(it.begin(), it.end(), ' ');
	first.insert(first.begin(), it.begin(), p);
	res = find(marslow, marslow + 13, first) - marslow;
	if (res != 13)return to_string(res);
	res = find(marsup, marsup + 13, first) - marsup;
	res *= 13;
	if (p != it.end()) {
		second.insert(second.begin(), p + 1, it.end());
		res += find(marslow, marslow + 13, second) - marslow;
	}
	return to_string(res);
}