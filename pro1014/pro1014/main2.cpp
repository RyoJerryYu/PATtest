#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
int main() {
	string sci, res="";
	cin >> sci;
	auto i = sci.begin();
	i++; res += *i;
	for (i += 2; *i != 'E'; i++);
	res += sci.substr(3, i-sci.begin()-3);
	i++;
	int exp = stoi(sci.substr(i-sci.begin()));
	cout << exp;
	if (exp < 0) {
		res.insert(0, "0.");
		exp++;
		res.insert(2, -exp, '0');
	}
	else if (exp < int(res.length()) - 1) {
		res.insert(exp + 1, ".");
	}
	else {
		exp -= res.length() - 1;
		res.append(exp, '0');
	}
	return 0;
}