#include <bits/stdc++.h>
using namespace std;

#include "shopUtils/snack.h"
#include "shopUtils/animal.h"
#include "shopUtils/order.h"

int main()
{
    Snack s("Chocolate", 20);
    Order order(s, 2);
    order.print();
}