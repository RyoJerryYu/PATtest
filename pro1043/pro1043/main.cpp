#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	const char PATest[6] = { 'P','A','T','e','s','t' };
	string input;
	int count[128] = { 0 };
	cin >> input;
	for (char x : input)count[x]++;
	int res = 6;
	while (res) {
		for (int i = 0; i < 6; i++) {
			if (count[PATest[i]] > 0) {
				cout << PATest[i];
				count[PATest[i]]--;
			}
			if (count[PATest[i]] == 0) {//���ǳ�ֵΪ0�����ܷŵ���һ��if��
				res--;
				count[PATest[i]]--;//��-1����״̬��ֻ���һ��if
			}
		}
	}
	cout << endl;
	return 0;
}