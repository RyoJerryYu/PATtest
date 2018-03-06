#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
bool isInsSort(const vector<int>&, const vector<int>&);
vector<int> onceInsSort(const vector<int>&);
vector<int> onceMerSort(const vector<int>&);
int main() {
	int N;
	cin >> N;
	vector<int> oriseq(N), midseq(N), finseq(N);
	for (int& x : oriseq) cin >> x;
	for (int& x : midseq) cin >> x;
	bool typ = isInsSort(oriseq, midseq);
	cout << (typ ? "Insertion Sort" : "Merge Sort") << endl;
	if (typ) finseq = onceInsSort(midseq);
	else finseq = onceMerSort(midseq);
	for (int& x : finseq) cout << x << " ";
	cout << endl;
	return 0;
}
bool isInsSort(const vector<int>& oriseq, const vector<int>& midseq) {
	auto orip = oriseq.end(), midp = midseq.end();
	while (*(--orip) == *(--midp));
	while (midp != midseq.begin()) {
		if (*midp < *(midp - 1))return false;
		midp--;
	}
	return true;
}
vector<int> onceInsSort(const vector<int>& midseq) {
	auto midp = midseq.begin();
	vector<int> res;
	while (*midp <= *(midp + 1))res.push_back(*(midp++));//resǰ׺��������
	res.push_back(*(midp++));
	res.insert(upper_bound(res.begin(), res.end(), *midp), *midp);//��ǰ׺���һ��Ԫ������ز���ǰ׺
	midp++;
	const auto mide = midseq.end();
	while (midp != mide)res.push_back(*(midp++));//��׺����ԭ������
	return res;
}
vector<int> onceMerSort(const vector<int>& midseq) {
	vector<int> res;
	auto midp = midseq.begin(), sqend = midseq.end() - 1;
	back_insert_iterator<vector<int> > resbak(res);
	int step = 1, shortest = midseq.size();//shortest��Ϊ�Ѻϲ��ĳ���
	for (midp = midseq.begin(); midp < sqend; midp++) {//`midp<sqend` means `midp+1<end`
		if (*midp <= *(midp + 1)) step++;
		else {
			if (step < shortest) shortest = step;//shortest���������һstep
			step = 1;
		}
	}
	step = shortest << 1;//��һ�ֵ���
	sqend = midseq.end() - step;//then `midp<sqend` means `midp+step<end`
	for (midp = midseq.begin(); midp < sqend; midp += step) {
		merge(midp, midp + shortest, midp + shortest, midp + step, resbak);//���ϲ����һstep
	}
	if (midp + shortest < midseq.end()) merge(midp, midp + shortest, midp + shortest, midseq.end(), resbak);//�ϲ����һstep
	return res;
}
