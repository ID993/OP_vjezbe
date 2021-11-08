//6. Napisite funkciju koja stringove, koje korisnik unosi, sprema u vektor stringova,
//   svaki string preokrene te sortira vektor po preokrenutim stringovima.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
using std::vector;

vector<string> string_revector()
{
	vector<string> vs(3);
	string s;

	for (int i = 0; i < vs.size(); i++)
	{
		getline(cin, s);
		vs[i] = s;
	}
	for (int i = 0; i < vs.size(); i++)
	{
		reverse(vs[i].begin(),vs[i].end());
	}

	sort(vs.begin(), vs.end());
	return vs;
}

void print_vector(vector<string>& v)
{
	for (string i: v)
		cout << i << "\t";
	cout << std::endl;
}

int main()
{
	vector<string> vector_string;

	vector_string = string_revector();

	print_vector(vector_string);

	

}