#ifndef snack_h
#define snack_h

#include "snackTypes.h"
#include <utility>

class Snack
{
private:
    std::string snack;
    double price;
    std::pair<std::string, double> getNameAndPrice(enum SnackTypes snack);

public:
    Snack(SnackTypes);
    Snack();
    std::string getName() { return this->snack; }
    double getPrice() { return this->price; }
};

Snack::Snack()
{
    this->snack = "UnknownSnack";
    this->price = 0;
}

Snack::Snack(SnackTypes snack)
{
    pair<string, double> s = this->getNameAndPrice(snack);
    this->snack = s.first;
    this->price = s.second;
}

std::pair<std::string, double> Snack::getNameAndPrice(enum SnackTypes snack)
{
    switch (snack)
    {
    case SaltedPeanuts:
        return std::make_pair("SaltedPeanuts", 13);
    case Pretzels:
        return std::make_pair("Pretzels", 25);
    case PotatoChips:
        return std::make_pair("PotatoChips", 15);
    case BananaChips:
        return std::make_pair("BananaChips", 30);
    case AppleChips:
        return std::make_pair("AppleChips", 30);
    case PorkRinds:
        return std::make_pair("PorkRinds", 40);
    case CheeseDips:
        return std::make_pair("CheeseDips", 20);
    case MixedNuts:
        return std::make_pair("MixedNuts", 20);
    case Popcorn:
        return std::make_pair("Popcorn", 40);
    case BeefJerky:
        return std::make_pair("BeefJerky", 45);
    case Crackers:
        return std::make_pair("Crackers", 30);
    case CornSnacks:
        return std::make_pair("CornSnacks", 17);
    case Cheese:
        return std::make_pair("Cheese", 50);
    case Chocolates:
        return std::make_pair("Chocolates", 30);
    case Candies:
        return std::make_pair("Candies", 10);
    case IceCream:
        return std::make_pair("IceCream", 25);
    case Milkshakes:
        return std::make_pair("Milkshakes", 40);
    case Pastries:
        return std::make_pair("Pastries", 50);
    case Pies:
        return std::make_pair("Pies", 70);
    case Cookies:
        return std::make_pair("Cookies", 13);
    case Cakes:
        return std::make_pair("Cakes", 70);
    case Puddings:
        return std::make_pair("Puddings", 20);
    case Cereal:
        return std::make_pair("Cereal", 25);
    case Brownies:
        return std::make_pair("Brownies", 40);
    case Fudge:
        return std::make_pair("Fudge", 50);
    case PeanutButter:
        return std::make_pair("PeanutButter", 30);
    case PopTarts:
        return std::make_pair("PopTarts", 25);
    case Pancakes:
        return std::make_pair("Pancakes", 20);
    case Scrones:
        return std::make_pair("Scrones", 40);
    case UnknownSnack:
    default:
        return std::make_pair("UnknownSnack", 0);
    }
}

#endif