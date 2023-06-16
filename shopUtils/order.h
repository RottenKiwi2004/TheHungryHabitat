#ifndef order_h
#define order_h

#include "snack.h"
#include "snackTypes.h"
#include <string>
#include <iostream>
#include <iomanip>

class Order
{
private:
    Snack snack;
    int quantity;
    double price;

public:
    Order(Snack, int);
    std::string getName() { return this->snack.getName(); }
    double getPrice() { return this->price; }
    void print();
    int getQuantity();
};

Order::Order(Snack snack, int quantity)
{
    // cout << "New order: " << quantity << " x " << snack.getName() << endl;
    this->snack = snack;
    this->quantity = quantity;
    this->price = snack.getPrice() * quantity;
}

void Order::print()
{
    std::string q = "(x" + std::to_string(this->quantity) + ")";
    std::cout << std::setw(15) << std::left << this->snack.getName() << std::setw(5) << q << " ---------- " << std::setw(4) << std::right << this->price << std::endl;
}

int Order::getQuantity()
{
    return this->quantity;
}

#endif