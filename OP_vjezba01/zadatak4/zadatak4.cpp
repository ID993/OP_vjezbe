// Zadatak_4.cpp : Napisati rekurzivnu funkciju za traženje najvećeg i najmanjeg broja u nizu.

#include <iostream>
using namespace std;

int minimum_rec(int* arr, int size, int* min)
{
	if (size <= 0)
		return *min;
	*min = arr[size - 1] <= *min ? arr[size - 1] : *min;
	minimum_rec(arr, size - 1, min);
}

int maximum_rec(int* arr, int size, int* max)
{
	if (size <= 0)
		return *max;
	*max = arr[size - 1] >= *max ? arr[size - 1] : *max;
	maximum_rec(arr, size - 1, max);
}

int main()
{
	int arr[] = { 500, -100, 1, 2, 3, 4, 5, -9 };
	int min, max, size;
	min = arr[0];
	max = arr[0];
	size = sizeof arr / sizeof arr[0];
	minimum_rec(arr, size, &min);
	maximum_rec(arr, size, &max);
	cout << "najmanji je: " << min << endl << "najveci je: " << max << endl;
}