#ifndef cashier_h
#define cashier_h

#include "customer.h"

class Cashier
{
private:
    Customer *currentCustomer;

public:
    Cashier();
    void customerCheckOut(double money);
};

Cashier::Cashier()
{
    this->currentCustomer = NULL;
}

void Cashier::customerCheckOut(double money)
{

    std::string species = this->currentCustomer->getSpecies();
    double total = this->currentCustomer->getReceipt().getTotal();
    if (total > money)
    {
        std::cout << "Not anough money! (" << species << ")." << std::endl;
        std::cout << "Paid: " << money << " Total: " << total << std::endl;
        return;
    }

    std::cout << species << " paid " << money << std::endl;
    std::cout << "Change: " << total - money << std::endl;
}

#endif