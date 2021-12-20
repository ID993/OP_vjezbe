#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using std::vector;

class timer {
    int h;
    int m;
    double s;

public:
    timer()
    {
        h = 0; m = 0; s = 0;
    }
    timer(int hours, int minutes, double seconds)
    {
        h = hours; m = minutes; s = seconds;
    }
    ~timer() {}

    int& getHours() {
        return h;
    }
    int& getMinutes() {
        return m;
    }
    double& getSeconds() {
        return s;
    }

    timer operator+(const timer& other)
    {
        timer tim;
        tim.s = this->s + other.s;
        while (tim.s >= 60.0)
        {
            tim.m += 1;
            tim.s -= 60;
        }
        tim.m = this->m + other.m;
        while (tim.m >= 60)
        {
            tim.h += 1;
            tim.m -= 60;
        }
        tim.h = this->h + other.h;
        return tim;
    }

    timer operator+=(const timer& other)
    {
        this->s += other.s;
        while (this->s >= 60)
        {
            this->s -= 60;
            this->m += 1;
        }
        this->m += other.m;
        while (this->m >= 60)
        {
            this->m -= 60;
            this->h += 1;
        }
        this->h += other.h;
        return *this;
    }

    timer operator-(const timer& other)
    {
        timer tim;
        if (this->s < other.s)
        {
            this->s += 60;
            this->m -= 1;
        }
        tim.s = this->s - other.s;

        if (this->m < other.m)
        {
            this->m += 60;
            this->h -= 1;
        }
        tim.m = this->m - other.m;
        tim.h = this->h - other.h;
        return tim;
    }

    timer operator-=(const timer& other)
    {
        if (this->s < other.s)
        {
            this->s += 60;
            this->m -= 1;
        }
        this->s -= other.s;

        if (this->m < other.m)
        {
            this->m += 60;
            this->h -= 1;
        }
        this->m -= other.m;
        this->h -= other.h;

        return *this;
    }

    timer operator/(const int& other)
    {
        timer tim;
        tim.h = this->h / other;
        tim.m = this->m / other;
        tim.s = this->s / other;
        return tim;
    }

    timer operator/=(const int& other)
    {
        this->h /= other;
        this->m /= other;
        this->s /= other;
        return *this;
    }

    int operator<(const timer& other)
    {
        if (other.h > this->h)
            return 1;
        else if (other.h < this->h)
            return 0;
        else if (other.m > this->m)
            return 1;
        else if (other.m < this->m)
            return 0;
        else if (other.s > this->s)
            return 1;
        else if (other.s < this->s)
            return 0;
    }

    friend ostream& operator<<(ostream& cout, const timer& other)
    {
        cout << other.h << ":" << other.m << ":" << other.s;
        return cout;
    }

    operator double()
    {
        return (this->h * 3600 + this->m * 60 + this->s);
    }

    friend class penalty;
};

#endif
