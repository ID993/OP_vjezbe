//3. Koristeci STL funkcije sortirajte vektor, ubacite 0 ispred najmanjeg elementa, te
//sumu svih elemenata iza najveceg elementa.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

void print_vector(vector<int> v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << "\t";
	std::cout << std::endl;
}

int main()
{
	int sum = 0;
	vector<int> v{ 1,2,3,4,5,-5 };

	for (int i = 0; i < v.size(); i++)
		sum += v[i];

	sort(v.begin(), v.end());

	v.insert(min_element(v.begin(), v.end()), 0);
	v.insert(max_element(v.begin(), v.end()) + 1, sum);

	print_vector(v);

}