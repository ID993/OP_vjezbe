// Zadatak 2.Napisati funkciju koja vraća referencu na neki element niza.Koristeći povratnu
// vrijednost funkcije kao lvalue uvećajte i - ti element niza za jedan.

#include <iostream>
#include <iomanip>
using namespace std;


int& element(int* arr, int index)
{
	return index;
}


int main()
{	
	int index;
	cout << "Unesi index niza: " << endl;
	cin >> index;
				//0 1 2 3 4
	int arr[] = { 7,9,6,4,2 };

	arr[element(arr, index)]++;

	cout << "Ispis: " << arr[element(arr, index)] << endl;
	
}