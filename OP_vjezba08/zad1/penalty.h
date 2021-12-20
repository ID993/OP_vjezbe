#ifndef PENALTY_H
#define PENALTY_H

#include "timer.h"

class penalty
{
    int penal;

public:
    penalty(int p)
    {
        penal = p;
    }

    timer operator() (timer& time)
    {
        time.s += penal;
        if (time.s >= 60)
        {
            time.m += 1;
            time.s -= 60;
        }
        return time;
    }
};

#endif