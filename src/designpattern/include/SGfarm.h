#include "farm.h"
#include "cabbage.h"
#include "horse.h"

class SGfarm : public farm
{
private:
    /* data */
public:
    SGfarm(/* args */); 
    ~SGfarm();
    plant* createPlant() override;
    animal* createAnimal() override;
};

//C++中虚函数所返回的对象需要设置为指针类型

plant* SGfarm::createPlant() {
    cabbage* ptr = new cabbage();
    return ptr;
}

animal* SGfarm::createAnimal() {
    horse* ptr = new horse();
    return ptr;
}

SGfarm::SGfarm(/* args */)
{
}

SGfarm::~SGfarm()
{
}
