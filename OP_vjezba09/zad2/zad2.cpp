/*
Definirajte interface Zivotinja sa metodama koje vracaju broj nogu te vrstu
(string). Izvedite klase zivotinja: Kukac, Pauk, Ptica, te iz njih neke klase
za konkretne zivotinje. Napisite klasu Brojac koja prima zivotinje (ispisuje
vrstu svake dodane) i racuna ukupan broj nogu svih zivotinja. 
*/

#include "Animal.hpp"
#include "Counter.hpp"


int main()
{   
    Sparrow Spar;
    Tarantula Tara;
    Cockroach Cockro;

    Counter c;
    c.addAnimal(&Tara);
    c.addAnimal(&Cockro);
    c.addAnimal(&Spar);

    cout << "Total legs: " << c.countLegs();
}


