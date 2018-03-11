#include <iostream>
#include <map>
#include <string>
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
	int* que = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> que[i];
	}
	for (int i = 0; i < m; i++) {
		cout << group[que[i]].id << ' ' << group[que[i]].site << endl;
	}
	return 0;
}