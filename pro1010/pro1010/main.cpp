#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	string input = "";
	vector<int> inputint(0);
	vector<int> res(0);
	char c;
	c = cin.get();
	while (c != '\n'&&c != '\0') {
		input += c;
		c = cin.get();
	}
	unsigned i = 0, j = 0;
	while (i < input.size() && input[i] == ' ')i++;
	j = i;
	while (i <input.size()) {
		if (input[i] == ' ') {
			inputint.push_back(stoi(input.substr(j, i - j)));
			while (i < input.size() && input[i] == ' ')i++;
			j = i;
		}
		i++;
	}
	if (j < input.size())inputint.push_back(stoi(input.substr(j, i - j)));
	if (inputint.size() % 2 == 1)inputint.pop_back();
	i = 0;
	while (i < inputint.size()) {
		if (inputint[i + 1] == 0) {
			i += 2;
		}
		else {
			res.push_back(inputint[i] * inputint[i + 1]);
			res.push_back(inputint[i + 1] - 1);
			i += 2;
		}
	}
	if (res.size() == 0) {
		res.push_back(0);
		res.push_back(0);
	}
	for (i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ' ';
	}
	cout << res.back() << endl;
	return 0;
}