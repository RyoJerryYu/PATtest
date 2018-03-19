#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> cards(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}
	vector<int> countminus(n, 0);
	for (int i = 0; i < n; i++)
	{
		int minus = abs(cards[i] - i - 1);
		countminus[minus]++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (countminus[i] > 1)
		{
			cout << i << ' ' << countminus[i] << endl;
		}
	}
	return 0;
}