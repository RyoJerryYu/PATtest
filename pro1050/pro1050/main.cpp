/*
*
m,n Osquaren
sort Onlogn
luoxuan
ceng a from 0 to m/2
from 0+a,0+a to m-2-a,0+a
from m-1-a,0+a to m-1-a,n-2-a
from m-1-a,n-1-a to 0+1+a,n-1-a
from 0+a,n-1-a to 0+a,0+1+a
*
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int m = 0, n = 0;
	cin >> N;
	vector<int> group(N);
	for (int i = 0; i < N; i++)cin >> group[i];
	sort(group.rbegin(), group.rend());

	if (N == 0) {
		return 0;
	}

	n = (int)sqrt((double)N);
	m = N / n;
	while (m*n != N) {
		n--;
		m = N / n;
	}

	auto p = group.begin();
	vector<vector<int> > nummap(m, vector<int>(n));
	const auto pend = group.end();
	const int maxa = (n + 1) / 2;
	int left, up, right, down;
	for (int a = 0; a < maxa; a++) {
		left = 0 + a;
		up = 0 + a;
		right = n - 1 - a;
		down = m - 1 - a;
		if (left == right) {//n<=m, so right-left <= down-up
			for (int i = up; i <= down; i++) {
				nummap[i][left] = *(p++);
			}
			continue;
		}
		else {//if left==up and right==down, it will be wrong.
			for (int i = left; i < right && p != pend; i++) nummap[up][i] = *(p++);
			for (int i = up; i < down && p != pend; i++) nummap[i][right] = *(p++);
			for (int i = right; i > left && p != pend; i--) nummap[down][i] = *(p++);
			for (int i = down; i > up && p != pend; i--) nummap[i][left] = *(p++);
		}
		
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			cout << nummap[i][j] << ' ';
		}
		cout << nummap[i][n - 1] << endl;
	}
}