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
	}//��(n-i)*(i+1)*group[i]����ͬ��
	//ǰ�߳˳�double����int��˳�double
	//�����ȳ˳�int�������������
	printf("%.2f", sum);
}