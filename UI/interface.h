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
    static void showOptions();
};

void Interface::start()
{
    system("cls");
    std::cout << "Press Enter to start game" << std::endl;
}

void Interface::displayCashier(Cashier *cashier)
{
    system("cls");
    std::cout << "Coming soon" << std::endl;
    std::cout << "Press any key to continue" << std::endl;
}

void Interface::displayQueue(Queue *queue)
{
    system("cls");
    std::cout << "Queue:" << std::endl;
    queue->printAll();
    std::cout << "=====================" << std::endl;
    std::cout << "Press any key to continue" << std::endl;
}

void Interface::showOptions()
{
    system("cls");
    std::cout << "1. Show queue" << std::endl;
    std::cout << "2. Show customer receipt" << std::endl;
    std::cout << "3. Change coins" << std::endl;
    std::cout << "4. Check stock" << std::endl;
    std::cout << "5. Customer has not enough money" << std::endl;
    std::cout << "6. Get next customer" << std::endl;
}

#endif