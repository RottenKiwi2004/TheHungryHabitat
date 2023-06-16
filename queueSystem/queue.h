#ifndef queue_h
#define queue_h

#include "node.h"
#include <iostream>

// I know this is kinda funny, but bits/stdc++.h contains queue library anyways

// This is still unfinished
class Queue
{
private:
    Node *first = NULL;
    Node *last = NULL;
    int size = 0;

public:
    Queue();
    Customer front();
    void push(Customer);
    void pop();
    bool empty();
    void printAll();
    int getSize();
    ~Queue();
};

Queue::Queue()
{
    this->first = NULL;
    this->last = NULL;
}

void Queue::push(Customer customer)
{
    Node *newCustomer = new Node(customer);
    if (this->first == NULL)
    {
        this->last = newCustomer;
        this->first = newCustomer;
    }
    else
    {
        this->last->setNext(newCustomer);
        this->last = this->last->getNext();
    }
    this->size++;
}

bool Queue::empty()
{
    return this->first == NULL;
}

Customer Queue::front()
{
    if (this->empty())
        throw std::runtime_error(std::string("No customer left in queue while trying to get front element."));
    return this->first->getCustomer();
}

void Queue::pop()
{
    if (this->empty())
        throw std::runtime_error(std::string("No customer left in queue while trying to pop."));
    Node *temp = this->first;
    if (this->first == this->last)
    {
        this->first = NULL;
        this->last = NULL;
    }
    else
        this->first = this->first->getNext();
    this->size--;
    delete temp;
}

void Queue::printAll()
{
    for (Node *temp = this->first; temp != NULL; temp = temp->getNext())
        std::cout << temp->getCustomer().getSpecies() << ", " << temp->getCustomer().getMoney() << std::endl;
}

int Queue::getSize()
{
    return this->size;
}

Queue::~Queue()
{
    while (!this->empty())
    {
        this->pop();
    }
}

#endif