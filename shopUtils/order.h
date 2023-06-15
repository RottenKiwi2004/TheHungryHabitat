#ifndef order_h
#define order_h

#include "snack.h"
#include "snackTypes.h"

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
    std::string q = "(x" + to_string(this->quantity) + ")";
    cout << setw(15) << left << this->snack.getName() << setw(5) << q << " ---------- " << setw(4) << right << this->price << endl;
}

int Order::getQuantity()
{
    return this->quantity;
}

#endif