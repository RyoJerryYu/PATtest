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
	int q = 1;//p����������������һ��
	for (auto i = num.begin(); i != num.end(); i++) {
		long long max = (long long)*i * p;
		auto maxi = upper_bound(i, num.end(), max);//��i��ʼ���Ҷ����Ǵ�0��ʼ
		if (maxi - i > q)q = int(maxi - i);//maxi-iΪ����������Ԫ�صĸ���
	}
	cout << q;
}