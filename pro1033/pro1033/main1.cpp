#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const string upchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main1() {
	string brostr, brokey="", instr, outstr="";
	cin >> brostr >> instr;
	for (const char& x : brostr) {
		if (x == '+')brokey += upchar;
		else {
			brokey += (char)tolower(x);
			brokey += (char)toupper(x);
		}
	}
	sort(brokey.begin(), brokey.end());
	brokey.erase(unique(brokey.begin(), brokey.end()), brokey.end());
	for (const char& x : instr) {
		if (!binary_search(brokey.begin(), brokey.end(), x))outstr += x;
	}
	cout << outstr << endl;
	return 0;
}