#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
#define MAX 1000

template<typename TYPE>
class Stack
{
    int top;

public:
    TYPE arr[MAX];
    Stack() { top = -1; }

    void push(TYPE n)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack Overflow";
            return;
        }
        else
            arr[++top] = n;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return;
        }
        else
            arr[top--];
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    TYPE peek()
    {
        if (top < 0) 
        {
            cout << "Stack is Empty";
            return 0;
        }
        else 
        {
            TYPE x = arr[top];
            return x;
        }
    }
};

#endif