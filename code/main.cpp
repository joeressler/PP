#include <cstdlib>
#include <vector>
#include <iostream>
using std::istream;

#include "Pizza.h"

using std::string;

#include <algorithm>
#include <iomanip>

int deletes = 0;
/* void operator delete(void* p) noexcept
{
    if (p) {
        free(p);
        deletes += 1;
    }
} */

istream& next_int(istream& source, int& answer)
{
    using namespace std;
    while (source && !(source >> answer)) {
        source.clear();
        string consume;
        source >> consume;
    }
    return source >> ws;
}


Pizza::Pizza(int size)
    :    _size {size}
{
    std::cout << "constructing" << std::endl;
    _n_toppings = 0;
    _toppings = nullptr;
}

Pizza::~Pizza() {
    std::cout << "destroying" << std::endl;
    if (_toppings != nullptr) 
    {_toppings = nullptr;}
}

void Pizza::add(std::string topping) {
    std::cout << "adding toppings" << std::endl;
    std::string* newToppings = new std::string[_n_toppings+1];
    if (_toppings != nullptr) {
        std::cout << "already has toppings" << std::endl;
        for (int i = 0; i < _n_toppings; i++) {
            newToppings[i] = _toppings[i];
        }
        std::cout << "about to delete toppings" << std::endl;
        delete _toppings;
        std::cout << "finished deleting toppings" << std::endl;
    }
    std::cout << "inserting last topping" << std::endl;
    newToppings[_n_toppings] = topping;
    _toppings = newToppings;
    _n_toppings++;
    std::cout << "done adding" << std::endl;
}


void Pizza::print() const 
{
    using namespace std;
    cout << "printing" << endl;
    cout << "Size:" << setw(5) << _size << "\n";
    for (int i = 0; i < _n_toppings; i++) {
        cout << _toppings[i] << endl;
    }
    cout << "done printing" << endl;

}



int main() // int argc, char* argv[]
{
    using namespace std;
    cout << "making pizza" << endl;
    /*if (argc >= 3) {
        if (argc >= 4) { srand(strtoul(argv[3], NULL, 10)); }
        int count = strtol(argv[2], NULL, 10);
        vector<string> toppings = {"Cheese", "Olives", "Pepperoni", "Sausage", "Peppers", "Pineapple", "Ham", "Mushrooms"};
        for (int i = 0; i < count; ++i) {
            Pizza order { rand() % 10 + 8 };
            for (int t = 0; t < 3; ++t) {
                order.add(toppings[rand() % toppings.size()]);
            }
        }
        cout << deletes;
    } else {*/
        int size;
        while (next_int(cin, size)) {
            Pizza order {size};
            string topping;
            while (getline(cin, topping) && topping != "") {
                order.add(topping);
            }
            order.print();
        }
    //}
    return 0;
}