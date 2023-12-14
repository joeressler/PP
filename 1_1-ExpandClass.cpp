#include <iostream>
using namespace std;

class Greeter {
    public:
    void hello() {
        cout << "HELLO WORLD";
    };
    string greet(const string name) {
        return ("Hello " + name);
    };
    string name = "Jim";
    string giveName() {
        return name;
    };
};

int main() {
    string user;
    cin >> user;
    Greeter* solution = new Greeter();
    string greeting = solution -> greet(user);
    auto position = greeting.find_first_of(' ');
    cout << greeting.insert(position, ",") << "!\n";
    delete solution;
    return 0;
}
