#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long> num(n);
	vector<long> llower(n), rbiger(n);
	vector<long> res;
	for (long&x : num) {
		cin >> x;
	}
	long bigestl = num[0], lowestr = num[n - 1];
	for (int i = 0; i < n; i++) {
		if (bigestl < num[i])bigestl = num[i];
		llower[i] = bigestl;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (num[i] < lowestr)lowestr = num[i];
		rbiger[i] = lowestr;
	}
	for (int i = 0; i < n; i++) {
		if (llower[i] <= num[i] && num[i] <= rbiger[i])res.push_back(num[i]);
	}
	cout << res.size() << endl;
	for (unsigned i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ' ';
	}
	cout << res[res.size() - 1] << endl;
}