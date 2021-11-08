//5. Napisati funkciju koja broji koliko pojavljivanja danog podstringa ima u stringu koristeci
//funkcije standardne biblioteke.

#include <iostream>
#include <cstring>

using namespace std;

int& string_counter(char* src, char* substr)
{
	int counter = 0;
	char* p, * q;
	p = src;
	q = substr;

	while (strstr(p, substr)) // ??
	{
		p = strstr(p, substr) + strlen(substr);
		counter++;
	}
	
	return counter;
}

int main()
{
	int counter = 0;
	char string[] = "Ovo je stringstring.  SSstring";
	char substring[] = "string";

	counter = string_counter(string, substring);

	cout << "Ponavljanje: " << counter << endl;




}