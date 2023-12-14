#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w;
    cin >> w; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    string arr[h];
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        while (line.length() != w) {cout << "Wrong length, try again with " << to_string(w) << " length." << endl; getline(cin, line);}
        arr[i] = line;
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 'x') {continue;}

            int bombN = 0;
            // diagonal left up check
            if (i == 0 || j == 0) {
            } else {
                if (arr[i-1][j-1] == 'x') {bombN++;} // getting top left           
            }
            // up check
            if (i == 0) {
            } else {
                if (arr[i-1][j] == 'x') {bombN++;} // getting up
            }
            // diagonal right up check
            if (i == 0 || j == w-1) {
            } else {
                if (arr[i-1][j+1] == 'x') {bombN++;} // getting top right  
            }
            // middle left check
            if (j == 0) {
            } else {
                if (arr[i][j-1] == 'x') {bombN++;} // getting left
            }
            // middle right check
            if (j == w-1) {
            } else {
                if (arr[i][j+1] == 'x') {bombN++;} // getting right
            }
            // bottom left check
            if (i == h-1 || j == 0) {
            } else {
                if (arr[i+1][j-1] == 'x') {bombN++;} // getting bottom left           
            }
            // down check
            if (i == h-1) {
            } else {
                if (arr[i+1][j] == 'x') {bombN++;} // getting down
            }
            // diagonal right down check
            if (i == h-1 || j == w-1) {
            } else {
                if (arr[i+1][j+1] == 'x') {bombN++;} // getting bottom right  
            }

            //setting the square
            if (bombN > 0) {arr[i][j] = char(48+bombN);}
        };
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 'x') {
                //erasing bombs
                arr[i][j] = '.';
            }
        }
    }

    

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int i=0;i<h;i++) {cout<< arr[i] << endl;}
}