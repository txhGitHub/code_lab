
#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "stdio.h"

class animal
{
private:
    /* data */
public:
    animal(/* args */);
    ~animal();
    virtual void show() = 0;
};

animal::animal()
{}

animal::~animal()
{}
#endif //_ANIMAL_H_