#include "yaml-cpp/yaml.h"
#include <mutex>

class GlobalConfiguration
{
    
    static std::mutex mtx;
private:
    /* data */
    GlobalConfiguration(/* args */);
    ~GlobalConfiguration();
    static GlobalConfiguration* instance;
    YAML::Node m_config;
public:
    YAML::Node& getYamlConfig();
    static GlobalConfiguration* GetInstance()
    {
        if(instance == nullptr) {
            std::lock_guard<std::mutex> guard(mtx);
            if(instance == nullptr) {
                instance = new GlobalConfiguration();
            }
        }
        return instance;
    }
};

GlobalConfiguration* GlobalConfiguration::instance = nullptr;
std::mutex GlobalConfiguration::mtx;

GlobalConfiguration::GlobalConfiguration()
{
    m_config = YAML::LoadFile("./dong.yaml");
}

YAML::Node& GlobalConfiguration::getYamlConfig()
{
    return m_config;
}

