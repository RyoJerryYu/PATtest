#include <iostream>
#include <stack>
using namespace std;
int main() {
	long A, B, C;
	int D;
	stack<int> res;
	cin >> A >> B >> D;
	C = A + B;
	if (C == 0) res.push(0);//����Ϊ0���
	while (C != 0) {
		res.push(C%D);
		C /= D;
	}
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
	cout << endl;
}