#include <iostream>
using namespace std;
int main() {
	int p1 = 0, p2 = 0, sum;
	int p1s, p1u, p2s, p2u;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p1s >> p1u >> p2s >> p2u;
		sum = p1s + p2s;
		if (sum == p1u && sum != p2u) {
			p2++;
		}
		else if (sum == p2u && sum != p1u) {
			p1++;
		}
	}
	cout << p1 << ' ' << p2 << endl;
}