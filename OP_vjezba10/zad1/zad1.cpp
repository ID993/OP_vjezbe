#include "mySort.hpp"

int main()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	char arr1[] = { 'A', 'z', 'F', 'b', 'd' };
	int size = sizeof arr / sizeof arr[0];
	int size1 = sizeof arr1 / sizeof arr1[0];
	mySort(arr, size);
	mySort(arr1, size1);
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << endl;	
	for (size_t i = 0; i < size1; i++)
		cout << arr1[i] << endl;
}
