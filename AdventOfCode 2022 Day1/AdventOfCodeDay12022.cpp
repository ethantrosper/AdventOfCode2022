#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ifstream input;
	input.open("input.txt");
	string line;
	int elfMax = 0;
	int nextElf = 0;
	int topThreeOutput = 0;
	vector<int> elfSaver;

	while (getline(input, line, '\n')) {
		if (line != "") {
			nextElf += stoi(line);
		}
		else {
			if (nextElf > elfMax) {
				elfMax = nextElf;
				elfSaver.push_back(nextElf);
				nextElf = 0;
			}
			else {
				elfSaver.push_back(nextElf);
				nextElf = 0;
			}
		}
	}
	std::sort(elfSaver.begin(), elfSaver.end());
	for (int i = elfSaver.size()-3; i < elfSaver.size(); i++) {
		topThreeOutput += elfSaver.at(i);
	}
	
	cout << "output elfMax: " << elfMax;
	cout << "Topthree: " << topThreeOutput;
	return 0;
}

