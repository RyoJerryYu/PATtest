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
		sum += group[i]*(n - i)*(i + 1);
	}//与(n-i)*(i+1)*group[i]不相同！
	//前者乘出double再与int相乘出double
	//后者先乘出int，会数据溢出。
	printf("%.2f", sum);
}