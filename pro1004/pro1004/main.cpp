#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct classstudent {
	string name;
	string id;
	int grad;
	bool operator<(classstudent& other) {
		return grad < other.grad;
	}
};
int main() {
	int n;
	cin >> n;
	vector<classstudent> students(n);
	for (classstudent& x : students) {
		cin >> x.name >> x.id >> x.grad;
	}
	sort(students.begin(), students.end());
	cout << students.back().name << ' ' << students.back().id << endl;
	cout << students[0].name << ' ' << students[0].id << endl;
}