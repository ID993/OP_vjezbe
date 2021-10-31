// Zadatak 1.Napisati funkciju koja računa najveći i najmanji broj u nizu od n prirodnih
// brojeva.Funkcija vraća tražene brojeve pomoću referenci.

#include <iostream>
#include <iomanip>
using namespace std;

void minimax(int arr[], int size, int& min, int& max)
{
	for (int i = 0; i < size; i++)
	{
		min = arr[i] <= min ? arr[i] : min;
		max = arr[i] >= max ? arr[i] : max;
	}
}

int main()
{
	int arr[] = { -5,2,3,4,5,-58 };
	int min, max, size;
	min = arr[0];
	max = arr[0];
	size = sizeof arr / sizeof arr[0];
	minimax(arr, size, min, max);

	cout << "Min je: " << min << endl;
	cout << "Max je: " << max << endl;
}


