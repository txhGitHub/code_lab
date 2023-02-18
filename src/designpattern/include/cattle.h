#include "animal.h"

class cattle : public animal
{
private:
    /* data */
public:
    cattle(/* args */);
    ~cattle();
    void show() override; //override编译器只是帮忙检查
};

void cattle::show()
{
    printf("xinhong the cattle has been created");
}

cattle::cattle()
{}

cattle::~cattle()
{}

