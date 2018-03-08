#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu1022 {
	int No = 0, Mark = 0;
	bool operator<(stu1022 other) {
		return Mark < other.Mark;
	}
};
int main1() {
	int N;
	cin >> N;
	vector<stu1022> a(N);
	for (stu1022& x : a) {
		cin >> x.No >> x.Mark;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	cout << a[0].No << " " << a[0].Mark << endl;
	return 0;
}