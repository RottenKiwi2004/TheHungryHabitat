#ifndef shop_h
#define shop_h

#include "../queueSystem/queue.h"
#include "cashier.h"
#include "../soundSystem/notes.h"

#include <thread>
#include <windows.h>
#include <iostream>
#include <conio.h>

class Shop
{
private:
    Queue *queue;
    Cashier *cashier;
    void randomSpawn();
    void operate();
    bool gameOver = false;

public:
    Shop();
    ~Shop();
};

void Shop::randomSpawn()
{
    while (!this->gameOver)
    {
        int customerType = rand() % 17;
        double money = rand() % 100 + 200;
        Customer customer(static_cast<AnimalSpecies>(customerType), money);
        int orderCount = rand() % 3 + 1;
        for (int i = 0; i < orderCount; i++)
            customer.order(static_cast<SnackTypes>(rand() % 29), rand() % 5 + 1);
        this->queue->push(customer);
        std::cout << "* New customer: " << customer.getSpecies() << " $" << customer.getMoney() << " with " << orderCount << " orders." << std::endl;
        Beep(Notes::B5, 250);
        Beep(Notes::Gsharp5, 250);
        if (this->queue->getSize() > 10)
        {
            std::cout << "You lose, the queue is too long. Customers have to wait outside the shop and got hit by a car." << std::endl;
            this->gameOver = true;
            break;
        }
        Sleep(rand() % 15000 + 15000);
    }
}

void Shop::operate()
{
    while (!this->gameOver)
    {
        Interface::showOptions();
        switch (getch())
        {
        case '1':
            if (this->queue->empty())
                break;
            Interface::displayQueue(this->queue);
            getch();
            break;
        case '2':
            if (this->queue->empty())
                break;
            Interface::displayReceipt(this->queue->front().getReceipt());
            getch();
            break;
        case '3':
            if (this->queue->empty())
                break;
            Interface::displayCashier(this->cashier);
            if (!this->cashier->customerCheckOut(this->queue->front()))
            {
                getch();
                break;
            }
            if (!this->cashier->operate())
            {
                this->gameOver = true;
                std::cout << "You are fired for changing too much / too few money to customer." << std::endl;
                std::cout << "Game Over!" << std::endl;
                return;
            }
            else
            {
                this->queue->pop();
            }
            getch();
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