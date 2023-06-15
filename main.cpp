#include <bits/stdc++.h>
using namespace std;

#include "shopUtils/snack.h"
#include "shopUtils/animalSpecies.h"
#include "shopUtils/order.h"
#include "shopUtils/receipt.h"
#include "shopUtils/customer.h"
#include "shopUtils/animal.h"

int main()
{
    Customer kangaroo(AnimalSpecies::Kangaroo, 200);
    kangaroo.order(SnackTypes::Cheese, 2);
    kangaroo.order(SnackTypes::BananaChips, 2);
    kangaroo.order(SnackTypes::Brownies, 3);
    kangaroo.order(SnackTypes::BananaChips, 1);
    kangaroo.order(SnackTypes::SaltedPeanuts, 1);
    Receipt bill = kangaroo.getReceipt();
    bill.print();
}