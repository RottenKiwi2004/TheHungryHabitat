#ifndef cashier_h
#define cashier_h

#include "customer.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

class Cashier
{
private:
    Customer *currentCustomer = NULL;
    double change = 0;

public:
    Cashier();
    bool customerCheckOut(Customer customer);
    bool operate();
};

Cashier::Cashier()
{
    this->currentCustomer = NULL;
}

bool Cashier::customerCheckOut(Customer customer)
{
    this->currentCustomer = &customer;
    double money = customer.getMoney();
    std::string species = this->currentCustomer->getSpecies();
    double total = this->currentCustomer->getReceipt()->getTotal();
    if (total > money)
    {
        // std::cout << "Not anough money! (" << species << ")." << std::endl;
        // std::cout << "Paid: " << money << " Total: " << total << std::endl;
        return false;
    }

    this->change = money - total;
    // std::cout << species << " paid " << money << std::endl;
    // std::cout << "Change: " << this->change << std::endl;
    return true;
}

bool Cashier::operate()
{

    int coinCount[7] = {0, 0, 0, 0, 0, 0, 0};
    double amount[7] = {100, 50, 20, 10, 5, 2, 1};
    int current = 0;
    while (true)
    {
        system("cls");
        // std::cout << "Change need to be made: " << this->change << std::endl;
        for (int i = 0; i < 7; i++)
            std::cout << (current == i ? "> $" : "  $") << std::left << std::setw(4) << amount[i] << ": " << coinCount[i] << std::endl;
        switch (getch())
        {
        // Prev
        case 72:
            current += 6;
            current %= 7;
            break;
        // Next
        case 80:
            current++;
            current %= 7;
            break;

        case 43:
            coinCount[current]++;
            break;
        case 45:
            if (!coinCount[current])
                break;
            coinCount[current]--;
            break;

        case 13:
        {
            double totalChange = 0;
            for (int i = 0; i < 7; i++)
            {
                totalChange += amount[i] * coinCount[i];
            }
            return totalChange == this->change;
        }
        default:
            break;
        }
    }
}

#endif