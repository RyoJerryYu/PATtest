#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool judge(string&);
int main() {
	int n;
	string buff;
	vector<int> res(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buff;
		if (judge(buff)) res.push_back(1);
		else res.push_back(0);
	}
	for (int x : res) {
		if (x == 1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
bool judge(string& it) {
	int p = -1, t = -1;
	int cp = 0, ct = 0;
	for (unsigned i = 0; i < it.size(); i++) {
		if (it[i] != 'P'&&it[i] != 'A'&&it[i] != 'T')return false;
		if (it[i] == 'P') {
			p = i;
			cp++;
		}
		if (it[i] == 'T') {
			t = i;
			ct++;
		}
		if (cp > 1 || ct > 1)return false;
	}
	if (p < 0 || t < 1 || t < p)return false;
	int a = p, b = t - p - 1, c = it.size() - t - 1;
	if (c < a || b < 1)return false;
	if (a == 0 && c != 0)return false;
	if (a == 0 && c == 0)return true;
	if (c%a != 0)return false;
	int time = c / a;
	if (b == time)return true;
	else return false;
}