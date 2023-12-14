#include <iostream>
using namespace std;

long solution(long N) {
    string newS = to_string (N);
    int nSize = newS.length();
    for (int i = 0; i < (nSize/2); i++) {
        char temp = newS[i];
        newS[i] = newS[nSize-1-i];
        newS[nSize-1-i] = temp;
    }
    return atol(newS.c_str());
}

int main() {
    long N;
    cin >> N;
    cout << solution(N);
    return 0;
}
