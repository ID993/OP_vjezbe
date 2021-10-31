//Definirati strukturu koja opisuje vektor. Struktura se sastoji od niza int
//elemenata, logičke i fizičke veličine niza. Fizička veličina je inicijalno init, a
// kada se ta veličina napuni vrijednostima, alocira se duplo.
//Napisati funkcije vector_new, vector_delete, vector_push_back, vector_pop_back,
//vector_front, vector_back i vector_size.Funkcije su članovi strukture.

#include "vector.hpp"
#include <iostream>
using namespace std;


void MyVector::vector_new(size_t sz)
{
    arr = new int[1];
    size = 0;
    capacity = 1;
}

void MyVector::vector_delete()
{
    delete[] arr;  
}

void MyVector::vector_push_back(int n)
{
    if (size == capacity) 
    {
        int* temp = new int[2 * capacity];

        for (int i = 0; i < capacity; i++) 
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
    arr[size] = n;
    size++;
}

void MyVector::vector_pop_back()
{
    size--;
}

int& MyVector::vector_front()
{
    return arr[0];
}

int& MyVector::vector_back()
{
    return arr[size-1];
}

size_t MyVector::vector_size()
{
    return size;
}

void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    MyVector mv;
    mv.vector_new();

    int m;
    cout << "Unesi element, Ctrl+d (linux) ili Ctrl+z (win) za kraj unosa" << endl;
    while (cin >> m)
        mv.vector_push_back(m);

    cout << "first element " << mv.vector_front() << endl;
    cout << "last element " << mv.vector_back() << endl;
    mv.print_vector();

    cout << "removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "size " << mv.vector_size() << endl;
    cout << "capacity " << mv.capacity << endl;

    mv.vector_delete();
}
