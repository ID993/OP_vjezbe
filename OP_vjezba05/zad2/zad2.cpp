/*Napisati klasu koja predstavlja oruzje.Oruzje ima svoj polozaj u prostoru(jedna tocka u prostoru),
broj metaka koji stanu u jedno punjenje i trenutni broj metaka u punjenju.Moze pucati(shoot) i ponovo se puniti(reload).*/

#include "C:\Users\ivoda\Desktop\OP_vjezba05\vj05.hpp"
#include <iostream>
using namespace std;
/*
class weapon {
public:
    point weapon_position;
    const int clip_size = 30;
    int clip_current = clip_size;

    void shoot(int& clip_current) {
        while (clip_current > 0)
        {
            clip_current--;
        }
    }

    void reload(int& clip_current) {
        if (clip_current < clip_size)
            clip_current = clip_size;
    }
};
*/
int main()
{
    weapon ak47;
    ak47.weapon_position.set_to_random(4, 7);
    ak47.clip_current = ak47.clip_size;

    for (int i = 0; i < 45; i++) 
    {
        ak47.shoot(ak47.clip_current);
        if (ak47.clip_current == 0)
            ak47.reload(ak47.clip_current);       
    }
    cout << ak47.clip_current << endl;
}