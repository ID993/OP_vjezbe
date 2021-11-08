//2. Koristeci funkcije iz prvog zadatka unijeti dva vektora i formirati novi vektor koji
//se sastoji od elemenata iz prvog vektora koji nisu u drugom vektoru.

#include "entry_bounds_print.hpp"
#include "vector_functions.cpp"
using namespace std;
using std::vector;


int main()
{
	
	int numEl, a, b, j = 0;
	vector<int> v1;
	vector<int>& ref_v1 = v1;
	vector<int> v2;
	vector<int>& ref_v2 = v2;
	

	std::cout << "Unesi broj elemenata vektora: " << std::endl;
	std::cin >> numEl;
	std::cout << "Unesi intervale elemenata vektora: " << std::endl;
	std::cin >> a >> b;

	vector_entry(ref_v1, numEl);
	vector_entry_bounds(ref_v2, a, b);
	print_vector(v1);
	cout << endl;
	print_vector(v2);
	
	vector<int> v3;
	
	for (int i = 0; i < v1.size(); i++)
	{
		for (j ; j < v2.size(); j++)
		{
			if (v1[i] == v2[j] && v3[i] == v2[j])
			{
				break;				
			}
			v3.push_back(v1[i]);
		}

	}
	cout << endl;
	print_vector(v3);
	
}