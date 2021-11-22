/*Napisati program koji će generirati n meta i jednog pucača (oružje). Uz pretpostavku
da je položaj oružja horizontalan i da se oružje može zakretati za 360◦,
izračunati koliko je meta pogođeno jednim punjenjem.*/

#include "C:\Users\ivoda\Desktop\OP_vjezba05\vj05.hpp"
#include <vector>
using std::vector;


void print_vector(vector<target> v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i].hit)
			std::cout << 1 << '\t';
	}
	std::cout << std::endl;
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i].lower_left.z << '\t';
	}
	std::cout << std::endl;
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i].upper_right.z << '\t';
	}
	std::cout << std::endl;
}

int main()
{
	int n, counter = 0;
	weapon uzi;
	uzi.weapon_position.set_to_random(1, 100);
	cin >> n;
	vector<target> v(n);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].lower_left.set_to_random(1, 100);
		v[i].upper_right.set_to_random(1, 100);
	}

	std::cout << "Weapon position: " << uzi.weapon_position.z << endl;

	for (int i = 0; i < v.size() && uzi.clip_current > 0; i++)
	{

		if (uzi.weapon_position.z <= v[i].upper_right.z && uzi.weapon_position.z >= v[i].lower_left.z)
		{
			v[i].hit = true;
			counter++;
			uzi.clip_current--;
		}
		else if (uzi.clip_current > 0 && i == v.size() - 1)
			i = 0;
		uzi.clip_current--;

	}
	print_vector(v);

	cout << "Hit " << counter << " targets!" << endl;
	cout << "Bullets left: " << uzi.clip_current << endl;
}

