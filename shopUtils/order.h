#ifndef order_h
#define order_h

#include "snack.h"

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
};

Order::Order(Snack snack, int quantity)
{
    this->snack = snack;
    this->quantity = quantity;
    this->price = snack.getPrice() * quantity;
}

void Order::print()
{
    std::string q = this->quantity > 1 ? ("(x" + to_string(this->quantity) + ")") : "";
    cout << this->snack.getName() << q << " ---------- " << this->price << endl;
}

#endif