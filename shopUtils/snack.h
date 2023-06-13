#ifndef snack_h
#define snack_h

class Snack
{
private:
    string snack;
    double price;

public:
    Snack(string, double);
    Snack(pair<string, double> snack);
    string getName() { return this->snack; }
    double getPrice() { return this->price; }
};

Snack::Snack(string snack = "Undefined snack", double price = 0)
{
    this->snack = snack;
    this->price = price;
}

Snack::Snack(pair<string, double> snack)
{
    this->snack = snack.first;
    this->price = snack.second;
}

std::pair<string, double> snackList[] = {
    make_pair("Salted peanuts", 5),
    make_pair("Pretzels", 20),
    make_pair("Potato chips", 20),
    make_pair("Banana chips", 20),
    make_pair("Apple chips", 20),
    make_pair("Pork rinds", 20),
    make_pair("Cheese dips", 20),
    make_pair("Mixed nuts", 20),
    make_pair("Popcorn", 20),
    make_pair("Beef jerky", 20),
    make_pair("Crackers", 20),
    make_pair("Corn snacks", 20),
    make_pair("Cheese", 20),
    make_pair("Chocolates", 20),
    make_pair("Candies", 20),
    make_pair("Ice cream", 20),
    make_pair("Milkshakes", 20),
    make_pair("Pastries", 20),
    make_pair("Pies", 20),
    make_pair("Cookies", 20),
    make_pair("Cakes", 20),
    make_pair("Puddings", 20),
    make_pair("Cereal", 20),
    make_pair("Brownies", 20),
    make_pair("Fudge", 20),
    make_pair("Peanut butter", 20),
    make_pair("Pop tarts", 20),
    make_pair("Pancakes", 20),
    make_pair("Scrones", 20)};

#endif