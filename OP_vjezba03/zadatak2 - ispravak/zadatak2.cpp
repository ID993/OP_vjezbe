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
	std::vector<int>::iterator it;

	for (int i = 0; i < v1.size(); i++)
	{
			it = find(v2.begin(), v2.end(), v1[i]);
			if (it == v2.end())
			{
				v3.push_back(v1[i]);
				
			}
			
	}
	cout << endl;
	print_vector(v3);
	
}