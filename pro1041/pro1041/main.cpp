#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct stud {
	string id;
	int site;
	stud() {};
};
int main() {
	map<int, stud> group;
	int m, n, site, trisite;
	string id;
	stud tstud;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> trisite >> site;
		tstud.id = id;
		tstud.site = site;
		group[trisite] = tstud;
	}
	cin >> m;
	vector<int> que(m);
	for (int& x:que) {
		cin >> x;
	}
	for (int x:que) {
		cout << group[x].id << ' ' << group[x].site << endl;
	}
	return 0;
}