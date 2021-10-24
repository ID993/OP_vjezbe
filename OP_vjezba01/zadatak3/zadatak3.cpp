// Zadatak_3.cpp : Napisati iterativnu funkciju za traženje najvećeg i najmanjeg broja u nizu.

#include <iostream>
using namespace std;

/*
void minimax(int* arr, int size, int* min, int* max)
{
	*min = arr[0];
	*max = arr[0];

	for (int i = 0; i < size; i++)
	{
		*min = arr[i] <= *min ? arr[i] : *min;
		*max = arr[i] >= *max ? arr[i] : *max;
	}
}
*/

void minimum(int* arr, int size, int* min)
{
	*min = arr[0];
	for (int i = 0; i < size; i++)
		*min = arr[i] <= *min ? arr[i] : *min;
}

void maximum(int* arr, int size, int* max)
{
	*max = arr[0];
	for (int i = 0; i < size; i++)
		*max = arr[i] >= *max ? arr[i] : *max;
}

int main()
{
	int arr[] = { 0, 1, 2, -5, 4, 98 };
	int min, max, size;
	size = sizeof arr / sizeof arr[0];
	minimum(arr, size, &min);
	maximum(arr, size, &max);
	cout << "najmanji je: " << min << endl << "najveci je: " << max << endl;

}

