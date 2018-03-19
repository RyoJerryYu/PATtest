#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.get();
	vector<string> group(n);
	for (int i = 0; i < n; i++)
	{
		getline(cin, group[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (group[i].size() < 6)
		{
			cout << "Your password is tai duan le." << endl;
			continue;
		}
		bool uncon = false, havenum = false, havealpha = false;
		for (char x : group[i])
		{
			if ('0' <= x && x <= '9')havenum = true;
			else if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))havealpha = true;
			else if (x == '.')continue;
			else
			{
				uncon = true;
				break;
			}
		}
		if (uncon == true)
		{
			cout << "Your password is tai luan le." << endl;
			continue;
		}
		if (havenum == false)
		{
			cout << "Your password needs shu zi." << endl;
			continue;
		}
		if (havealpha == false)
		{
			cout << "Your password needs zi mu." << endl;
			continue;
		}
		cout << "Your password is wan mei." << endl;
	}
	return 0;
}