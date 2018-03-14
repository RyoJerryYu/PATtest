#include <iostream>
using namespace std;
int main() {
	int teamscore[1001] = { 0 };
	int team, p, score;
	int n;
	int maxteam = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> team >> p >> score;
		teamscore[team] += score;
	}
	for (int i = 0; i < 1001; i++) {
		if (teamscore[i] > teamscore[maxteam])maxteam = i;
	}
	cout << maxteam << ' ' << teamscore[maxteam] << endl;
}