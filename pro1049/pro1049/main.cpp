#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
	int n;
	double sum = 0;
	cin >> n;
	vector<double>group(n);
	for (int i = 0; i < n; i++)cin >> group[i];
	for (int i = 0; i < n; i++) {
		sum += (n - i)*(i + 1)*group[i];
	}
	printf("%.2f", sum);
}