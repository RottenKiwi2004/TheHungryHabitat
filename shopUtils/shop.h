#ifndef shop_h
#define shop_h

#include "../queueSystem/queue.h"
#include "cashier.h"

#include <thread>
#include <windows.h>
#include <iostream>
#include <conio.h>

class Shop
{
    Queue *queue;
    Cashier *cashier;
    void randomSpawn();
    void operate();

public:
    Shop();
    ~Shop();
};

void Shop::randomSpawn()
{
    while (true)
    {
        Sleep(rand() % 10000 + 10000);
        int customerType = rand() % 17;
        double money = rand() % 50 + 50;
        Customer customer(static_cast<AnimalSpecies>(customerType), money);
        this->queue->push(customer);
        std::cout << "New customer has arrived: " << customer.getSpecies() << " with money " << customer.getMoney() << std::endl;
    }
}

void Shop::operate()
{
    while (true)
    {
        switch (getch())
        {
        case '1':
            Interface::displayQueue(this->queue);
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

Shop::Shop()
{

    std::cout << "Shop is now open." << std::endl;

    this->queue = new Queue;
    this->cashier = new Cashier;

    std::thread randomSpawn([this]()
                            { this->randomSpawn(); });
    std::thread operate([this]()
                        { this->operate(); });

    randomSpawn.join();
    operate.join();
}

Shop::~Shop()
{
    delete this->queue;
    delete this->cashier;
}

#endif