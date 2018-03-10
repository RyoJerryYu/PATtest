#include <iostream>
#include <array>
using namespace std;
int main() {
	int N, school, mark, maxsch = 0;
	array<int, 100010> schmark = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> school >> mark;
		schmark[school] += mark;
		if (schmark[school] > schmark[maxsch])maxsch = school;
	}
	cout << maxsch << " " << schmark[maxsch] << endl;
	return 0;
}