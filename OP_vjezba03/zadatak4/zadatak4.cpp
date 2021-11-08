//4. Napisati funkciju u za uklanjanje elementa iz vektora sa što manje operacija.Poredak
//elemenata u vektoru nije bitan.

#include <iostream>
#include <vector>
using namespace std;
using std::vector;

void print_vector(vector<int> v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << "\t";
	std::cout << std::endl;
}

void delete_element(vector<int>& v, int m)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == m)
		{
			v.erase(v.begin() + i, v.begin() + i + 1);				
		}
	}
}

int main()
{
	
	vector<int> v{ 1,2,3,4,5 };
	vector<int>& ref_v = v;

	delete_element(ref_v, 5);

	print_vector(v);

}