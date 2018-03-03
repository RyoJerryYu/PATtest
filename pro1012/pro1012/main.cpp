#include <iostream>
#include <stack>
using namespace std;
int main() {
	long A, B, C;
	int D;
	stack<int> res;
	cin >> A >> B >> D;
	C = A + B;
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