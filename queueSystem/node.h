#ifndef node_h
#define node_h

#include "../shopUtils/customer.h"

class Node
{
private:
    Customer customer;
    Node *nextCustomer = NULL;

public:
    Node(Customer);
    void setNext(Node *);
    Node *getNext();
    Customer getCustomer();
};

Node::Node(Customer customer)
{
    this->customer = customer;
}

// This is still unfinished
void Node::setNext(Node *nextCustomer)
{
    this->nextCustomer = nextCustomer;
}

Node *Node::getNext()
{
    return this->nextCustomer;
}

Customer Node::getCustomer()
{
    return this->customer;
}

#endif