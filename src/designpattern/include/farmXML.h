#include "farm.h"
#include <string>
#include <vector>
#include <map>
#include "SGfarm.h"
#include "SRfarm.h"


enum name
{
    SG,
    SR
};

class farmXML
{
private:
    /* data */
public:
    farmXML(/* args */);
    ~farmXML();
    farm* createPObject(std::string str);
};

farmXML::farmXML(/* args */)
{
}

farmXML::~farmXML()
{
}

farm* farmXML::createPObject(std::string str) {
    std::map<std::string, name> array = {{"SG", SG},{ "SR", SR}};
    switch (array[str])
    {
    case SG:
        {
            SGfarm* ptr = new SGfarm();
            return ptr;   
        }
        break;
    case SR:
        {
            SRfarm* ptr = new SRfarm();
            return ptr;   
        }
        break;
    default:
        break;
    }
};

