#ifndef customer_h
#define customer_h

#include "receipt.h"
#include "animal.h"
#include <iostream>

class Customer
{
    // Implement customer, they can order food, and come with some amount of money.
private:
    std::string species = "";
    Receipt receipt;
    double money;

public:
    Customer(AnimalSpecies = AnimalSpecies::UnknownSpecies, double = 0);
    void order(Snack, int = 1);
    void order(enum SnackTypes, int = 1);
    Receipt getReceipt();
    std::string getSpecies();
    double getMoney();
};

Customer::Customer(AnimalSpecies species, double money)
{
    Animal a(species);
    this->species = a.getSpecies();
    this->receipt = Receipt(a);
    this->money = money;
}

void Customer::order(enum SnackTypes snack, int amount)
{
    this->order(Snack(snack), amount);
}

void Customer::order(Snack snack, int amount)
{
    std::cout << this->species << " ordered " << amount << " " << snack.getName() << std::endl;
    this->receipt.addOrder(Order(snack, amount));
}

Receipt Customer::getReceipt()
{
    return this->receipt;
}

std::string Customer::getSpecies()
{
    return this->species;
}

double Customer::getMoney()
{
    return this->money;
}

#endif