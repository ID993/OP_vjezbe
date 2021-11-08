/*1. Napisati funkcije za unos i ispis vektora brojeva. Prototipove funkcija staviti u
.hpp datoteke, a implementaciju u .cpp datoteke.
Za unos vektora napisati dvije funkcije:
• funkcija ciji su parametri referenca na vektor i broj elemenata vektora,
• funkcija ciji su parametri referenca na vektor i granice intervala u kojem
trebaju biti elementi vektora. Elementi vektora se unose u funkciji, sve dok
se ne unese broj koji nije u danom intervalu.*/

#include "entry_bounds_print.hpp"
using std::vector;

int main()
{
	vector<int> v;
	vector<int>& ref_v = v;
	int numEl, a, b;

	std::cout << "Unesi broj elemenata vektora: " << std::endl;
	std::cin >> numEl;
	std::cout << "Unesi intervale elemenata vektora: " << std::endl;
	std::cin >> a >> b;

	std::cout << "Enter elements of vector: " << std::endl;
	vector_entry(ref_v, numEl);
	print_vector(v);

	v.clear();

	std::cout << "Enter elements of vector in bounds: " << std::endl;
	vector_entry_bounds(ref_v, a, b);
	print_vector(v);

}