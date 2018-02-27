#include <iostream>
#include <stdio.h>
using namespace std;
class thenum {
	int num[4] = { 0 }, max = 0, min = 0, res = 0, last = 0;
public:
	void breaknum(int N) {
		for (int i = 0; i < 4; i++) { num[i] = N % 10; N /= 10; }
		make();
		res = max - min;
	}
	void make() {
		for (int i = 3; i > 0; i--)
			for (int j = 0; j < i; j++) {
				if (num[j] < num[j + 1]) { int k = num[j]; num[j] = num[j + 1]; num[j + 1] = k; }//could be changed as bubblesort or others
			}
		max = 0;
		min = 0;
		for (int i = 0; i < 4; i++) { max *= 10; max += num[i]; min *= 10; min += num[3 - i]; }
	}
	void print() {
		while (last != res) {
			printf("%04d - %04d = %04d\n", max, min, res);
			last = res; breaknum(res);
			make(); res = max - min;
		}
	}
};
int main() {
	int N = 0; thenum A;
	cin >> N;
	A.breaknum(N);
	A.print();
	return 0;
}