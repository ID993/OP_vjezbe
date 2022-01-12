#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Animal.hpp"

class Counter
{
public:
    std::vector<Animal*> animal{};
    void addAnimal(Animal* a);
    int countLegs();
};

void Counter::addAnimal(Animal* a) {
    animal.push_back(a);
    cout << "Added: " << a->type() << endl;
}

int Counter::countLegs()
{
    int n = 0;
    for (size_t i = 0; i < animal.size(); i++)
        n += animal[i]->legs();
    return n;
}

#endif 

