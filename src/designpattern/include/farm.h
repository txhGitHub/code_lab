#ifndef _FARM_H_
#define _FARM_H_

#include "plant.h"
#include "animal.h"

class farm
{
private:
    
public:
    farm(/* args */);
    ~farm();
    virtual plant* createPlant() = 0;
    virtual animal* createAnimal() = 0;
};

farm::farm()
{}

farm::~farm()
{}


#endif 