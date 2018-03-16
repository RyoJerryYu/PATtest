#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int k;
	vector<int> found(1000, 0);
	cin >> k;
	vector<int> n(k);
	for (int& x : n) {
		cin >> x;
	}
	for (int x : n) {
		if (x < 1)continue;
		while (x != 1) {
			if (x % 2 == 0) x /= 2;
			else x = (3 * x + 1) / 2;
			if (found[x] != 0)break;
			else found[x] = 1;
		}
	}
	vector<int> res(0);
	for (int x : n) {
		if (found[x] == 0)res.push_back(x);
	}
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	for (unsigned i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ' ';
	}
	cout << res.back() << endl;
}