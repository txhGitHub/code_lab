# CXX_Template
Collect common template information

#cmake总结
采用install方式，注意执行make install 更新库


//工厂模式调用实例
// std::cout << "helloworld!" << std::endl;
// farmXML* ptr = new farmXML();
// farm* f = ptr->createPObject("SG");
// animal* a = f->createAnimal();
// a->show();
// delete ptr;
// delete f;
// delete a;
// if(a != nullptr)
// {
//     std::cout << "null! " << std::endl;
// }

//YAML的用法
// YAML::Node config = YAML::LoadFile("./dong.yaml");
// std::cout << "api: " << config["api"].as<std::string>() << std::endl;
// std::cout << "v: " << config["v"].as<int>() << std::endl;    
// for (auto it : config["label"]) {
// 	YAML::Node test2 = YAML::Load(it.second.as<std::string>());
// 	std::cout << " Type: " << test2.Type() << std::endl; //< 2
// 	std::cout << it.first.as<std::string>() << ":" << it.second.as<std::string>() << std::endl;
// }

