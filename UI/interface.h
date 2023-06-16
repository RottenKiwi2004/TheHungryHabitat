#ifndef interface_h
#define interface_h

#include <iostream>
#include "../shopUtils/cashier.h"
#include "../queueSystem/queue.h"

class Interface
{
public:
    static void start();
    static void displayQueue(Queue *);
    static void displayCashier(Cashier *);
};

void Interface::start()
{
    std::cout << "Press Enter to start game" << std::endl;
}

void Interface::displayCashier(Cashier *cashier)
{
    std::cout << "Coming soon" << std::endl;
}

void Interface::displayQueue(Queue *queue)
{
    queue->printAll();
}

#endif