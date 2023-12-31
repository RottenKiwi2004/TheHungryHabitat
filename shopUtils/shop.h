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
        srand(time(0));
        int customerType = rand() % 17;
        double money = rand() % 100 + 200;
        Customer customer(static_cast<AnimalSpecies>(customerType), money);
        int orderCount = rand() % 3 + 1;
        for (int i = 0; i < orderCount; i++)
            customer.order(static_cast<SnackTypes>(rand() % 29), rand() % 5 + 1);
        this->queue->push(customer);
        // std::cout << "* New customer: " << customer.getSpecies() << " $" << customer.getMoney() << " with " << orderCount << " orders." << std::endl;
        if (this->queue->getSize() > 10)
        {
            this->gameOver = true;
            Interface::longQueue();
            exit(0);
            break;
        }
        Beep(Notes::B5, 250);
        Beep(Notes::Gsharp5, 250);
        Sleep(rand() % 10000 + 10000);
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
                this->gameOver = true;
                Interface::notEnough();
                exit(0);
                return;
            }
            if (!this->cashier->operate())
            {
                this->gameOver = true;
                Interface::fired();
                exit(0);
                return;
            }
            else
            {
                this->queue->pop();
                Beep(Notes::E4, 100);
                Beep(Notes::Gsharp4, 100);
                Beep(Notes::B4, 100);
                Beep(Notes::E5, 100);
            }
            break;

        case '4':
        {
            double total = this->queue->front().getReceipt()->getTotal();
            double money = this->queue->front().getMoney();
            if (total < money)
            {
                this->gameOver = true;
                Interface::denyRage();
                Beep(Notes::G5, 200);
                Beep(Notes::G5, 100);
                Beep(Notes::G5, 400);
                Beep(Notes::G5, 100);
                Beep(Notes::G5, 200);
                exit(0);
                return;
            }
            std::cout << "How much money this customer is missing: $";
            double missing;
            std::cin >> missing;

            if (missing == total - money)
            {
                this->queue->pop();
                Beep(Notes::E4, 100);
                Beep(Notes::Gsharp4, 100);
                Beep(Notes::B4, 100);
                Beep(Notes::E5, 100);
            }
            else
            {
                this->gameOver = true;
                Interface::cashRage();

                Beep(Notes::C4, 200);
                Beep(Notes::Dsharp4, 200);
                Beep(Notes::F4, 400);
                Beep(Notes::Fsharp4, 400);
                exit(0);
                return;
            }
            // Implement what happen if it's correct / incorrect
        }
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