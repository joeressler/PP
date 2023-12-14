#include <iostream>
using namespace std;

class Greeter {
    public:
    void hello() {
        cout << "HELLO WORLD";

    };
};

int main() {
    Greeter solution;
    solution.hello();

    Greeter* solution2 = new Greeter();
    solution2 -> hello();
    delete solution2;
}
