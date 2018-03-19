#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
struct eranta
{
	string name;
	int x, y;
	eranta() :x(0), y(0), name("") {};
	double direct() {
		return sqrt((double)(x*x + y * y));
	}
};
int main() {
	int n;
	cin >> n;
	vector<eranta>erants(n);
	for (int i = 0; i < n; i++)
	{
		cin >> erants[i].name >> erants[i].x >> erants[i].y;
	}
	int maxi = 0;
	int mini = 0;
	double maxd = 0;
	double mind = erants[0].direct();
	for (int i = 0; i < n; i++)
	{
		double d = erants[i].direct();
		if (maxd < d)
		{
			maxi = i;
			maxd = d;
		}
		if (mind > d)
		{
			mini = i;
			mind = d;
		}
	}
	cout << erants[mini].name << ' ' << erants[maxi].name << endl;
	return 0;
}