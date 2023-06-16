#include <bits/stdc++.h>
using namespace std;

#include "../shopUtils/customer.h"
#include "../shopUtils/animal.h"
#include "../shopUtils/animalSpecies.h"
#include "queue.h"
#include "node.h"

int main()
{
    Customer a(AnimalSpecies::Emu), b(AnimalSpecies::FallowDeer);
    Queue q;
    q.push(a);
    q.push(b);
    cout << q.front().getSpecies() << endl;
    q.pop();
    cout << q.front().getSpecies() << endl;
    q.pop();
    q.pop(); // Runtime error
}