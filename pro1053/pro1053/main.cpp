#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct house {
	vector<double> E;
	int lowday = 0;
	int K;
	house() :E(0), lowday(0), K(0) {};
	friend istream& operator>>(istream&, house&);
	int refresh(double e) {
		lowday = 0;
		for (double x : E) {
			if (x < e)lowday++;
		}
		return lowday;
	}
	int getindenty(int D) {
		int iden = 0;
		if (lowday >(K / 2)) {
			iden = 1;
		}
		if (iden == 1 && K > D) {
			iden = 2;
		}
		return iden;
	}
};
istream& operator>>(istream& input, house& it) {
	input >> it.K;
	double f;
	for (int i = 0; i < it.K; i++) {
		input >> f;
		it.E.push_back(f);
	}
	return input;
}
int main() {
	int n, D;
	double e;
	vector<int> idents(3, 0);
	cin >> n >> e >> D;
	vector<house>houses(0);
	for (int i = 0; i < n; i++) {
		house buff;
		cin >> buff;
		houses.push_back(buff);
	}
	for (house& x : houses) {
		x.refresh(e);
		idents[x.getindenty(D)]++;
	}
	double maybe = (double)idents[1] * 100 / n;
	double itis = (double)idents[2] * 100 / n;
	printf("%.1f%% %.1f%%", maybe, itis);
}