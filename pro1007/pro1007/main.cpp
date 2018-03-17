#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	int q;
	bool itis;
	cin >> n;
	vector<int> su(0);
	for (int i = 2; i <= n; i++) {
		itis = true;
		q = (int)sqrt(i) + 1;
		for (unsigned j = 0; j < su.size() && su[j] < q; j++) {
			if (i%su[j] == 0) {
				itis = false;
				break;
			}
		}
		if (itis == true)su.push_back(i);
	}
	int res = 0;
	const int con = su.size() - 1;
	for (int i = 0; i < con; i++) {
		if (su[i + 1] - su[i] == 2)res++;
	}
	cout << res << endl;
}