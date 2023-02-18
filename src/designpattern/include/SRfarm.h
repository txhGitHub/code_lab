#include "farm.h"
#include "spinach.h"
#include "cattle.h"
class SRfarm : public farm
{
private:
    /* data */
public:
    SRfarm(/* args */); 
    ~SRfarm();
    plant* createPlant() override;
    animal* createAnimal() override;
};

//C++中虚函数所返回的对象需要设置为指针类型

plant* SRfarm::createPlant() {
    spinach* ptr = new spinach();
    return ptr;
}

animal* SRfarm::createAnimal() {
    cattle* ptr = new cattle();
    return ptr;
}

SRfarm::SRfarm(/* args */)
{
}

SRfarm::~SRfarm()
{
}
