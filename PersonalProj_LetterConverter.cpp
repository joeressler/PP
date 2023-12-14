#include "PersonalProj_LetterConverter.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string vowelsLow = "aeiou";
string vowelsCap = "AEOIU";
bool vowelLowSearch(char c) {
    return vowelsLow.find(c) != std::string::npos;
}

bool vowelCapSearch(char c) {
    return vowelsCap.find(c) != std::string::npos;
}

void lineConverter (string &line) {
    int n = line.length();
    for (int i = 0; i < n; i++) {
        char ch = line[i];
        if (vowelLowSearch(ch)) {
            line[i] = 'v';
        } else if  (vowelCapSearch(ch)) {
            line[i] = 'V';
        }
    }
}

int main() {
    ifstream ifs;
    ofstream out_file("outputFile.txt", ios_base::out); //, ios_base::out (out/trunc/app, etc.)
    ifs.open ("inputFile.txt", ifstream::in);

    //char c = ifs.get();
    string l;
    string currentLine;
    while (true) {
        std::getline(ifs, l);
        currentLine = l;
        lineConverter(currentLine);
        out_file << currentLine << endl;
        //c = ifs.get();
        if (!ifs.good()) {break;}
    }

    ifs.close();



    return 0;
}