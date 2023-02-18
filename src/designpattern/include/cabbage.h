#include "plant.h"

class cabbage : public plant
{
private:
    /* data */
public:
    cabbage(/* args */);
    ~cabbage();
    void show() override;
};

void cabbage::show(){
    printf("xinhong the cabbage has been created");
}

cabbage::cabbage(/* args */)
{
}

cabbage::~cabbage()
{
}
