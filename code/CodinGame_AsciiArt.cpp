#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;


void processToken (string token) {
    int numTimes;
    string printValue;
    int tokLength = token.length();
    if (isdigit(token[token.length()-1])) {
        numTimes = atoi(token.substr(0, tokLength - 1).c_str());
        printValue = token.substr(token.length() - 1, 1);
    } else {
        numTimes = atoi(token.c_str());
        if (numTimes == 0) {
            numTimes = 1;
        }
        for (int i=0; i < tokLength; i++) {
            if (!isdigit(token[i])) {
                printValue = token.substr(i, string::npos);
                break;
            }
        }
        if (printValue.compare("sp") == 0) {
            printValue = " ";
        } else if (printValue.compare("bS") == 0) {
            printValue = "\\";
        }  else if (printValue.compare("sQ") == 0) {
            printValue = "'";
        }  else if (printValue.compare("nl") == 0) {
            printValue = "\n";
        }
    }
    for (int i2=0; i2 < numTimes; i2++) {
        cout << printValue;
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string t;
    getline(cin, t);
    //t = "1sp 1/ 1bS 1_ 1/ 1bS nl 1( 1sp 1o 1. 1o 1sp 1) nl 1sp 1> 1sp 1^ 1sp 1< nl 2sp 3|";
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    /*
    std::string s = "scott>=tiger";
    std::string delimiter = ">=";
    std::string token = s.substr(0, s.find(delimiter)); // token is "scott"
    */
    string delimiter = " ";
    int start = 0;
    int end = t.find(delimiter);
    string token;
    while (end != -1) {
        token = t.substr(start, end - start);
        start = end + delimiter.size();
        end = t.find(delimiter, start);
        processToken(token);
    }
    token = t.substr(start, string::npos);
    processToken(token);
}