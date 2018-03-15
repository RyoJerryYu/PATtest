#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
struct phopeople {
	string name;
	int hight;
	friend istream& operator>>(istream&, phopeople&);
	friend ostream& operator<<(ostream&, phopeople&);
	bool operator<(phopeople&);
};
istream& operator>>(istream& input, phopeople& it) {
	input >> it.name >> it.hight;
	return input;
}
ostream& operator<<(ostream& output, phopeople& it) {
	output << it.name;
	return output;
}
bool phopeople::operator<(phopeople& other) {
	if (hight != other.hight)return hight < other.hight;
	return name > other.name;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<phopeople> peoples(0);
	phopeople buff;
	for (int i = 0; i < n; i++) {
		cin >> buff;
		peoples.push_back(buff);
	}
	sort(peoples.rbegin(), peoples.rend());
	if (k == 0)return 0;
	int m = n / k;
	int last = n - (m*k);
	vector<deque<phopeople> > ques(k);
	bool right = false;
	auto p = peoples.begin();
	for (int i = 0; i < last; i++) {
		if (right)ques[k - 1].push_front(*p);
		else ques[k - 1].push_back(*p);
		p++;
		right = !right;
	}
	for (int i = k - 1; 0 <= i; i--) {
		for (int j = 0; j < m; j++) {
			if (right)ques[i].push_front(*p);
			else ques[i].push_back(*p);
			p++;
			right = !right;
		}
		right = false;
	}
	for (int i = k - 1; 0 <= i; i--) {
		int size = ques[i].size() - 1;
		for (int j = 0; j < size; j++) {
			cout << ques[i][j] << ' ';
		}
		cout << ques[i][size] << endl;
	}
}