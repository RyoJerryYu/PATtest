#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string oris, ress, difs = "";
	cin >> oris >> ress;
	auto i = oris.begin(), j = ress.begin();
	const auto rese = ress.end();
	while (j != rese) {
		if (*i == *j)i++, j++;
		else if ('a' <= *i&&*i <= 'z' && (find(difs.begin(), difs.end(), *i - 'a' + 'A')) != difs.end())i++;
		else if (find(difs.begin(), difs.end(), *i) != difs.end())i++;
		else if ('a' <= *i&&*i <= 'z')difs += *(i++) - 'a' + 'A';
		else difs += *(i++);
	}
	cout << difs << endl;
}