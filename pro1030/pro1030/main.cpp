#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	long p;
	cin >> N >> p;
	vector<long> num(N);
	for (long& x:num) cin >> x;
	sort(num.begin(), num.end());
	int q = 1;//p是正整数，至少有一个
	for (auto i = num.begin(); i != num.end(); i++) {
		long long max = (long long)*i * p;
		auto maxi = upper_bound(i, num.end(), max);//从i开始查找而不是从0开始
		if (maxi - i > q)q = int(maxi - i);//maxi-i为完美序列中元素的个数
	}
	cout << q;
}