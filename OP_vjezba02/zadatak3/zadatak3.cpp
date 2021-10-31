/* Definirati strukturu kruznica i strukturu pravokutnik koja predstavlja
pravokutnik čije su stranice paralelne sa osima apscisa i ordinata.Napisati
funkciju koja prima niz pravokutnika i jednu kruznicu i vraća broj pravokutnika
koji sijeku kružnicu.Niz pravokutnika i kružnica šalju se u funkciju
pomoću const referenci.
Napomena:
– Jednadžba kružnice sa središtem u S(xs, ys) radijusa r:
(x − xs)2 + (y − ys)2 = r2
– Pravokutnik u koordinatnom sustavu je određen sa svojom donjom lijevom
i gornjom desnom točkom.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    double x, y;
};

struct circle
{
    point s;
    double r;
};

struct rectangle
{
   point dl, ur;
};


bool intersect(const rectangle &rect, const circle &circ)
{
    point srect, dist;
    double width, height, corner_distance;


    width = (rect.ur.x - rect.dl.x);
    height = (rect.ur.y - rect.dl.y);

    srect.x = (rect.ur.x + rect.dl.x) / 2;
    srect.y = (rect.ur.y + rect.dl.y) / 2;

    dist.x = abs(circ.s.x - srect.x);
    dist.y = abs(circ.s.y - srect.y);

    if (dist.x > (width / 2 + circ.r))
        return false; 
    if (dist.y > (height / 2 + circ.r))
        return false;

    if (dist.x <= (width / 2))
        return true;
    if (dist.y <= (height / 2))
        return true;

    corner_distance = pow(dist.x - width / 2, 2) + pow(dist.y - height / 2, 2);

    return (corner_distance <= pow(circ.r, 2));

}

int how_many_intersects(const rectangle rect[], const circle &circ, int n)
{
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        if(intersect(rect[i], circ))
            num++;
    }
    return num;
}

int main()
{
    rectangle pravo[] = { {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{1, 2}, {3, 4}} };
    circle kruz;
    kruz.r = 4;
    kruz.s.x = 0;
    kruz.s.y = 0;
    circle& kruzref = kruz;
    int len = sizeof pravo / sizeof pravo[0];

    cout << "koliko: " << how_many_intersects(pravo, kruzref, len) << endl;

}
