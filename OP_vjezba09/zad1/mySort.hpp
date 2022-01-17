#ifndef MYSORT_H
#define MYSORT_H

#include <iostream>
using namespace std;

template<typename TYPE>

void mySort(TYPE arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
}

template<>void mySort<char>(char arr[], int n)
{
	for (size_t i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (tolower(arr[j]) < tolower(arr[j - 1]))
				swap(arr[j], arr[j - 1]);
}

#endif