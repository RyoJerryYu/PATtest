#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> input(n);
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	if (n == 0)return 0;
	m = m % n;
	int cut = n - m;
	for (int i = 0; i < cut; i++) {
		res[i + m] = input[i];
	}
	for (int i = cut; i < n; i++) {
		res[i - cut] = input[i];
	}
	for (unsigned i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ' ';
	}
	cout << res[res.size() - 1] << endl;
	return 0;
}