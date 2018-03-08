#include <iostream>
#include <map>
using namespace std;
int main2() {
	int n;
	map<int, int> scomap;
	cin >> n;
	int school, mark;
	for (int i = 0; i < n; i++) {
		cin >> school >> mark;
		scomap[school] += mark;
	}
	auto p = scomap.begin();
	for (auto i = scomap.begin(); i != scomap.end(); i++) {
		if (i->second > p->second) p = i;
	}
	cout << p->first << " " << p->second << endl;
	return 0;
}