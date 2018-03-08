#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int n;
	map<int, int> scomap;
	cin >> n;
	int school, mark, max = 0, mxsc;
	for (int i = 0; i < n; i++) {
		cin >> school >> mark;
		scomap[school] += mark;
		if (scomap[school] > max) {
			mxsc = school;
			max = scomap[school];
		}
	}
	cout << mxsc << " " << max << endl;
	return 0;
}