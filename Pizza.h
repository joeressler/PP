#pragma once
#ifndef PIZZA
#define PIZZA

#include <string>

class Pizza {
public:
    Pizza(int size);
    void add(std::string topping);
    ~Pizza();
    void print() const;
private:
    int _size;
    int _n_toppings;
    std::string* _toppings;
};

#endif
