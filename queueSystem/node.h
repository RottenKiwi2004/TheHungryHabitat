#ifndef node_h
#define node_h

#include "../shopUtils/customer.h"

class Node
{
private:
    Customer customer;
    Node *nextCustomer;

public:
    Node(Customer);
    void setNext(Node *);
};

Node::Node(Customer customer)
{
    this->customer = customer;
}

Node::setNext()

#endif