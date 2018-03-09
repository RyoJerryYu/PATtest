#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	string brostr, instr, outstr="";
	set<char> brokey;
	cin >> brostr >> instr;
	for (char x : brostr) {
		if (x == '+') {
			for (char i = 'A'; i <= 'Z'; i++)brokey.insert(i);
		}
		else { brokey.insert(x); brokey.insert((char)tolower(x)); }
	}
	for (char x : instr) {
		if (brokey.find(x)==brokey.end())outstr += x;
	}
	cout << outstr << endl;
}