#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
std::map<string, int> outcomes;
vector<string> InputToVector(string inputFile);
void SetOutcomes();
int TotalCalculator(vector<string> inputVector);

int main()
{
	vector<string> InputData = InputToVector("input.txt");
	SetOutcomes();
	cout << "Player score: " << TotalCalculator(InputData);
	return 0;
}

vector<string> InputToVector(string inputFile)
{
	vector<string> InputData;
	std::ifstream input;
	string line;
	input.open(inputFile);
	while (getline(input, line)) {
		InputData.push_back(line);
	}
	input.close();
	return InputData;
}

void SetOutcomes()
{
	outcomes.insert(pair<string, int>("A X", 3));
	outcomes.insert(pair<string, int>("A Y", 4));
	outcomes.insert(pair<string, int>("A Z", 8));
	outcomes.insert(pair<string, int>("B X", 1));
	outcomes.insert(pair<string, int>("B Y", 5));
	outcomes.insert(pair<string, int>("B Z", 9));
	outcomes.insert(pair<string, int>("C X", 2));
	outcomes.insert(pair<string, int>("C Y", 6));
	outcomes.insert(pair<string, int>("C Z", 7));
}

int TotalCalculator(vector<string> inputVector)
{
	int total = 0;
	for (int i = 0; i < inputVector.size(); i++) {
		total += outcomes[inputVector.at(i)];
	}
	return total;
}

