#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct day {
	int y, m, d;
	day() {};//Ҫ�����ն����趨��Ĭ�Ϲ��캯��
	day(int a, int b, int c) :y(a), m(b), d(c) {};
	bool operator>(day & other) {
		return (y > other.y) || (y == other.y && m > other.m) || (y == other.y && m == other.m && d > other.d);
	}
};
struct people1018 {
	string name;
	day birthd;
	people1018() {};
	bool structp(string& births) {
		birthd.y = stoi(births.substr(0, 4));
		birthd.m = stoi(births.substr(5, 2));
		birthd.d = stoi(births.substr(8, 2));
		day oldest(1814, 9, 6), newest(2014, 9, 6);
		if (birthd > newest || oldest > birthd)return false;
		return true;
	}
	//bool operator>(people1018&other) { return birthd > other.birthd; }
	bool operator<(people1018&other) { return !(birthd > other.birthd) && (birthd.d != other.birthd.d || birthd.m != other.birthd.m || birthd.y != other.birthd.y); }
};
int main() {
	int N;
	cin >> N;
	vector<people1018> peoples;
	for (int i = 0; i < N; i++) {
		people1018 a;
		string d;
		cin >> a.name >> d;
		if (a.structp(d)) peoples.push_back(a);
	}
	sort(peoples.begin(), peoples.end());//����ֻ����operator>������ֻ����operator<
	N = peoples.size();
	cout << N << " " << peoples[0].name << " " << peoples[N - 1].name << endl;
	return 0;
}