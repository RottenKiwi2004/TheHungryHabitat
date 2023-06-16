#ifndef receipt_h
#define receipt_h

#include "order.h"
#include "animal.h"
#include <vector>
#include <iostream>
#include <iomanip>

void swap(Order *, Order *);

class Receipt
{
    // Implement Receipt from order class. Those must be sorted by name
    // If same name, sort by quantity
private:
    Animal customer;
    std::vector<Order> orderList;
    double total = 0;
    void sortOrder();

public:
    Receipt();
    Receipt(Animal);
    void addOrder(Order);
    void print();
    double getTotal();
};

Receipt::Receipt()
{
    this->customer = Animal();
}

Receipt::Receipt(Animal animal)
{
    this->customer = animal;
}

void Receipt::addOrder(Order order)
{
    this->orderList.push_back(order);
    this->total += order.getPrice();
    this->sortOrder();
}

void Receipt::print()
{
    std::cout << "=============== Receipt ===============" << std::endl;
    std::cout << "Customer: " << this->customer.getSpecies() << std::endl;
    std::cout << "=======================================" << std::endl;
    for (int i = 0; i < this->orderList.size(); i++)
        this->orderList[i].print();
    std::cout << "=======================================" << std::endl;
}

void Receipt::sortOrder()
{

    for (int i = 0; i < this->orderList.size() - 1; i++)
    {
        for (int j = i; j < this->orderList.size() - 1; j++)
        {
            if (this->orderList[j].getName() > this->orderList[j + 1].getName())
                swap(&this->orderList[j], &this->orderList[j + 1]);
            else if (this->orderList[j].getName() > this->orderList[j + 1].getName())
                if (this->orderList[j].getQuantity() < this->orderList[j + 1].getQuantity())
                    swap(&this->orderList[j], &this->orderList[j + 1]);
        }
    }
}

double Receipt::getTotal()
{
    return this->total;
}

void swap(Order *a, Order *b)
{
    Order *tmp = a;
    a = b;
    b = tmp;
}

#endif