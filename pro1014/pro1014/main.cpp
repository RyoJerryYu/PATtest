#include <iostream>
#include <string>
#include <iterator>
using namespace std;
int main() {
	string sci, res = "", real = "";
	unsigned exp = 0;
	bool expsign;
	unsigned i;
	cin >> sci;
	real += sci[1];
	for (i = 3; sci[i] != 'E'; i++)real += sci[i];
	i++;
	expsign = sci[i] == '+' ? true : false;
	for (i++; i<sci.length(); i++)exp = exp * 10 + (sci[i] - '0');
	if (sci[0] == '-')res += '-';
	if (!expsign) {
		res += "0.";
		for (i = 0; i<exp - 1; i++)res += '0';
		res += real;
	}
	else if (exp + 1 >= real.length()) {
		res += real;
		for (i = 0; i<real.length() - exp + 1; i++)res += '0';
	}
	else {
		for (i = 0; i<exp + 1; i++)res += real[i];
		res += ".";
		for (; i<real.length(); i++)res += real[i];
	}
	cout << res;
}