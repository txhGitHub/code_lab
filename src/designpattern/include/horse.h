#include "animal.h"

class horse : public animal
{
private:
    /* data */
public:
    horse(/* args */);
    ~horse();
    void show() override; //override编译器只是帮忙检查
};

void horse::show()
{
    printf("xinhong the horse has been created");
}

horse::horse()
{}
horse::~horse()
{}