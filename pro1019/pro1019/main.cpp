#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string oris, ress, difs = "";
	cin >> oris >> ress;
	auto i = oris.begin(), j = ress.begin();
	const auto orie = oris.end();
	while (i != orie) {
		if (*i == *j)i++, j++;
		else if (find(difs.begin(), difs.end(), (char)toupper(*i)) != difs.end())i++;
		else difs += (char)toupper(*(i++));
	}
	cout << difs << endl;
}