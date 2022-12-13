#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

char findCommonBadge(string input, string input2, string input3);

map<char, int> prioritization{ {'a', 1} , {'b', 2} , {'c', 3} , {'d', 4} , {'e', 5} , {'f', 6} , {'g', 7} , {'h', 8} , {'i', 9} , {'j', 10} ,
{'k', 11} , {'l', 12} , {'m', 13} , {'n', 14} , {'o', 15} , {'p', 16} , {'q', 17} , {'r', 18} , {'s', 19} , {'t', 20} , {'u', 21} , {'v', 22} ,
{'w', 23} , {'x', 24} , {'y', 25} , {'z', 26} , {'A', 27} , {'B', 28} , {'C', 29} , {'D', 30} , {'E', 31} , {'F', 32} , {'G', 33} , {'H', 34} , {'I', 35}, 
{'J', 36} , {'K', 37} , {'L', 38} , {'M', 39} , {'N', 40} , {'O', 41} , {'P', 42} , {'Q', 43} , {'R', 44} , {'S', 45} , {'T', 46} , {'U', 47} , {'V', 48},
{'W', 49} , {'X', 50} , {'Y', 51} , {'Z', 52} };

int main()
{
    ifstream inputFile;
    string line1;
    string line2;
    string line3;
    char c;
    int output = 0;
    inputFile.open("input.txt");
    while (getline(inputFile, line1)) {
        getline(inputFile, line2);
        getline(inputFile, line3);
        if(line1.length() >= line2.length() && line1.length() >= line3.length())
            c = findCommonBadge(line1, line2, line3);
        if (line2.length() >= line1.length() && line2.length() >= line3.length())
            c = findCommonBadge(line2, line1, line3);
        if (line3.length() >= line2.length() && line3.length() >= line1.length())
            c = findCommonBadge(line3, line2, line1);
        
        output += prioritization.at(c);
    }
    cout << "output: " << output << endl;
    return 0;
}

char findCommonBadge(string input1, string input2, string input3)
{
    for (char c : input1) {
        if (input2.find(c) != string::npos && input3.find(c) != string::npos) {
            return c;
        }
    }
    return 0;
}
