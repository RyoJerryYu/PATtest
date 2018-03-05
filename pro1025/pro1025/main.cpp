#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
bool isInsSort(const vector<int>&, const vector<int>&);
vector<int>&& onceInsSort(const vector<int>&);
vector<int>&& onceMerSort(const vector<int>&);
int main() {
	int N;
	cin >> N;
	vector<int> oriseq(N), midseq(N), finseq(N);
	for (int& x : oriseq) cin >> x;
	for (int& x : midseq) cin >> x;
	bool typ = isInsSort(oriseq, midseq);
	cout << (typ ? "Insert Sort" : "Merge Sort") << endl;
	if (typ) finseq = onceInsSort(midseq);
	else finseq = onceMerSort(midseq);
	for (int& x : finseq) cout << x << " ";
	cout << endl;
	return 0;
}
bool isInsSort(const vector<int>& oriseq, const vector<int>& midseq) {
	auto orip = oriseq.end(), midp = midseq.end();
	while (*(--orip) == *(--midp));
	while (orip != oriseq.begin()) {
		if (*orip < *(orip - 1))return false;
		orip--;
	}
	return true;
}
