#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string instructions;
    getline(cin, instructions);
    // initializing field
    bool field[19][25];
    for (int w = 0; w < 19; w++) {
        for (int h = 0; h < 25; h++) {
            field[w][h] = true;
        }
    }
    // ascii is -97
    stringstream ss(instructions);
    string word;
    int x;
    int y;
    int diameter;
    enum instruction {
        PLANTMOW,
        PLANT,
        MOW
    };
    instruction flag;

    while (ss >> word) {
        int found = word.find("PLANT");
        if (found == 0) {
            int mowFound = word.find("MOW");
            if (mowFound == 5) {
                //PLANT with MOW
                x = word[8] - 97;
                y = word[9] - 97;
                diameter = atoi(word.substr(10).c_str());
                flag = PLANTMOW;
            } else {
                //PLANT but no MOW
                x = word[5] - 97;
                y = word[6] - 97;
                diameter = atoi(word.substr(7).c_str());
                flag = PLANT;
            }
        } else {
            //no PLANT or PLANTMOW
            x = word[0] - 97;
            y = word[1] - 97;
            diameter = atoi(word.substr(2).c_str());
            flag = MOW;
        }
        double radius = diameter / 2.0;
        for (int w = 0; w < 19; w++) {
            for (int h = 0; h < 25; h++) {
                double distance = sqrt(pow((x - w), 2) + pow((y - h), 2));
                if (distance <= radius) {
                    switch(flag) {
                        case PLANTMOW:
                            field[w][h] = !field[w][h];
                            break;
                        case PLANT:
                            field[w][h] = true;
                            break;
                        case MOW:
                            field[w][h] = false;
                            break;
                    }
                }
            }
        }
    }




    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int h = 0; h < 25; h++) {

        for (int w = 0; w < 19; w++) {

            if (field[w][h]) {
                cout << "{}";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}