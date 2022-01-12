#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
    virtual int legs() = 0;
    virtual string type() = 0;
    virtual ~Animal() = 0;
};

Animal::~Animal() {}

class Insect : public Animal {
protected:
    int number_of_legs = 6;
public:
    int legs() {
        return number_of_legs;
    }
    string type() {
        return "Insect";
    }
};

class Cockroach : public Insect {
public:
    string type() {
        return "Cockroach";
    }
};

class Spider : public Animal {
protected:
    int number_of_legs = 8;
public:
    int legs() {
        return number_of_legs;
    }
    string type() {
        return "Spider";
    }
};

class Tarantula : public Spider {
public:
    string type() {
        return "Tarantula";
    }
};

class Bird : public Animal {
protected:
    int number_of_legs = 2;
public:
    int legs() {
        return number_of_legs;
    }
    string type() {
        return "Bird";
    }
};

class Sparrow : public Bird {
public:
    string type() {
        return "Sparrow";
    }
};

#endif