#include <iostream>
using namespace std;
int main() {//i:��i������,j:������,k:С��j�ĵ�k������,l:��������ĸ���
	int m = 1, n = 1, i = 0, j = 2, k = 0, l = 0, res = 0;
	cin >> m >> n; m -= 1;
	int *p = new int[n];
	while (i<n) {
		while (!res&&k<i) {
			if (j%p[k] == 0) { res++; }
			k++;
		}
		if (res == 0) {
			p[i] = j;
			if (i >= m) {
				cout << j;
				if ((i - m) % 10 == 9 || i == n - 1) { cout << endl; }
				else { cout << " "; }
			}
			i++;
		}
		j++; res = 0; k = 0;
	}
	return 0;
}