#include "plant.h"

class spinach : public plant
{
private:
    /* data */
public:
    spinach(/* args */);
    ~spinach();
    void show() override;
};

void spinach::show(){
    printf("xinhong the spinach has been created");
}

spinach::spinach(/* args */)
{
}

spinach::~spinach()
{
}
