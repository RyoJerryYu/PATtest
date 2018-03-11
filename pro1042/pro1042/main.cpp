#include <iostream>
using namespace std;
int main() {
	int count[256] = { 0 };
	char c;
	while ((c = cin.get()) != '\n') {
		count[tolower(c)]++;
	}
	int maxc = 'a';
	for (int i = 'a'; i <= 'z'; i++) {
		if (count[i] > count[maxc])maxc = i;
	}
	cout << (char)maxc << ' ' << count[maxc] << endl;
}