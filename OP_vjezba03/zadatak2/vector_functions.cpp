#include "entry_bounds_print.hpp"


void vector_entry(vector<int>& v, int n)
{
	int m;
	while (v.size() < n && std::cin >> m)
	{
		v.push_back(m);
	}
}

void vector_entry_bounds(vector<int>& v, int a, int b)
{
	int m;
	while (std::cin >> m)
	{
		if (m >= a && m <= b)
			v.push_back(m);
		else
			break;
	}
}

void print_vector(vector<int> v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << "\t";
	std::cout << std::endl;
}
