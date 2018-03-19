#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int i, n;
	cin >> i >> n;
	i %= 10;
	vector<string> res(n, "");
	res[0] += to_string(i);
	for (int j = 0; j < n - 1; j++)
	{
		int count = 0;
		char c = res[j][0];
		for (char x : res[j])
		{
			if (x == c)count++;
			else
			{
				res[j + 1] += c;
				res[j + 1] += to_string(count);
				c = x;
				count = 1;
			}
		}
		res[j + 1] += c;
		res[j + 1] += to_string(count);
	}
	cout << res.back() << endl;
	return 0;
}