#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct student
{
	string id;
	int score;
	string school;
	student() :id(""), score(0), school("") {};
	double schoolscore() {
		if (id[0] == 'A')return score;
		if (id[0] == 'B')return (double)score / 1.5;
		return (double)score*1.5;
	}
};
struct school
{
	int paiming;
	string name;
	double totalscore;
	int score;
	int countstu;
	school() :paiming(0), name(""), totalscore(0), countstu(0) {};
	void makescore() {
		score = (int)totalscore;
	}
	bool operator<(school other) {
		if (score != other.score)return score < other.score;
		if (countstu != other.countstu)return countstu > other.countstu;
		return name > other.name;
	}
};
int main() {
	int n;
	cin >> n;
	vector<student> students(n);
	map<string, school> schools;
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].id >> students[i].score >> students[i].school;
		for (char& x : students[i].school)
		{
			x = tolower(x);
		}
		schools[students[i].school].name = students[i].school;
		schools[students[i].school].countstu++;
		schools[students[i].school].totalscore += students[i].schoolscore();
	}
	vector<school> schvect(0);
	for (auto x : schools)
	{
		x.second.makescore();
		schvect.push_back(x.second);
	}
	sort(schvect.rbegin(), schvect.rend());
	schvect[0].paiming = 1;
	cout << schvect.size() << endl;
	cout << schvect[0].paiming << ' ' << schvect[0].name << ' ' << schvect[0].score << ' ' << schvect[0].countstu << endl;
	for (unsigned i = 1; i < schvect.size(); i++)
	{
		if (schvect[i].score != schvect[i - 1].score)
		{
			schvect[i].paiming = i + 1;
		}
		else
		{
			schvect[i].paiming = schvect[i - 1].paiming;
		}
		cout << schvect[i].paiming << ' ' << schvect[i].name << ' ' << schvect[i].score << ' ' << schvect[i].countstu << endl;
	}
	return 0;
}