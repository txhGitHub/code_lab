#ifndef _PLANT_H_
#define _PLANT_H_

#include "stdio.h"

class plant
{
private:
    /* data */
public:
    plant(/* args */);
    ~plant();
    virtual void show() = 0;
};

plant::~plant()
{}

plant::plant()
{}
#endif 