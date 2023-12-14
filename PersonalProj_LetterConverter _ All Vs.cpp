#include <iostream>
#include <string>
#include <fstream>

using namespace std;



void lineConverter (string &line) {
    int n = line.length();
    for (int i = 0; i < n; i++) {
        char ch = line[i];
        if (isupper(ch)) {
            line[i] = 'V';
        } else if (islower(ch)) {
            line[i] = 'v';
        }
    }
}

int main() {
    ifstream ifs;
    ofstream out_file("outputFileV.txt", ios_base::out); //, ios_base::out (out/trunc/app, etc.)
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