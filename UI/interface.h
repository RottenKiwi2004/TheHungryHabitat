#ifndef interface_h
#define interface_h

#include <iostream>
#include <windows.h>
#include "../shopUtils/cashier.h"
#include "../queueSystem/queue.h"
#include "../soundSystem/notes.h"

class Interface
{
public:
    static void start();
    static void displayQueue(Queue *);
    static void displayCashier(Cashier *);
    static void displayReceipt(Receipt *);
    static void showOptions();
    static void fired();
    static void longQueue();
};

void Interface::start()
{
    system("cls");
    std::cout << "Press Enter to start game" << std::endl;
}

void Interface::displayCashier(Cashier *cashier)
{
    system("cls");
    Beep(Notes::B5, 75);
    Beep(Notes::B5, 150);
    Beep(Notes::B5, 150);
    Beep(Notes::B5, 75);
}

void Interface::displayQueue(Queue *queue)
{
    system("cls");
    std::cout << "Queue:" << std::endl;
    queue->printAll();
    std::cout << "=======================================" << std::endl;
    std::cout << "Press any key to continue" << std::endl;
    Beep(Notes::C4, 100);
    Beep(Notes::F4, 100);
    Beep(Notes::A4, 100);
    Beep(Notes::C5, 100);
}

void Interface::displayReceipt(Receipt *receipt)
{
    system("cls");
    std::cout << "Receipt:" << std::endl;
    receipt->print();
    std::cout << "Press any key to continue" << std::endl;
    Beep(Notes::D4, 100);
    Beep(Notes::Fsharp4, 100);
    Beep(Notes::A4, 100);
    Beep(Notes::C5, 100);
}

void Interface::showOptions()
{
    system("cls");
    std::cout << "1. Show queue" << std::endl;
    std::cout << "2. Show customer receipt" << std::endl;
    std::cout << "3. Change coins" << std::endl;
    std::cout << "4. Customer has not enough money" << std::endl;
    Beep(Notes::C4, 100);
    Beep(Notes::E4, 100);
    Beep(Notes::G4, 100);
    Beep(Notes::C5, 100);
}

void Interface::fired()
{
    std::cout << "You are fired for changing too much / too few money to customer." << std::endl;
    std::cout << "Game Over!" << std::endl;
    Beep(Notes::C5, 200);
    Beep(Notes::A4, 200);
    Beep(Notes::Fsharp4, 200);
    Beep(Notes::Dsharp4, 200);
    Beep(Notes::C4, 200);
}

void Interface::longQueue()
{
    std::cout << "You lose, the queue is too long. Customers have to wait outside the shop and got hit by a car." << std::endl;
    Beep(Notes::B4, 200);
    Beep(Notes::F5, 400);
    Beep(Notes::F5, 200);
    Beep(Notes::F5, 200);
    Beep(Notes::E5, 200);
    Beep(Notes::D5, 200);
    Beep(Notes::C5, 400);
    Beep(Notes::C6, 200);
}

#endif