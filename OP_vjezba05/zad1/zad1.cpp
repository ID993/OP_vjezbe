#include <iostream>
using namespace std;

class point {
public:
    double x, y, z;

    void set_to_zero() {
        x = 0;
        y = 0;
        z = 0;
    }

    void set_to_random(double a, double b) {
        x = a + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (b - a)));
        y = a + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (b - a)));
        z = a + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (b - a)));
    }

    double get_x(void) {
        return x;
    }

    double get_y(void) {
        return y;
    }

    double get_z(void) {
        return z;
    }

    double distance_2D(double x2, double y2) {
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2) * 1.0);
    }

    double distance_3D(double x2, double y2, double z2) {
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2) + pow(z2 - z, 2) * 1.0);
    }

};

int main()
{
    point p1, p2;
    p1.set_to_zero();
    p2.set_to_random(-100, 100);

    cout << p1.distance_2D(p2.x, p2.y) << endl;
    cout << p1.distance_3D(p2.x, p2.y, p2.z) << endl;
}