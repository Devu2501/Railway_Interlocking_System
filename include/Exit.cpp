#include "Exit.hpp"

Exit:: Exit(int id,const string &name)
    : RailwayNode(id,name,RailwayNodeType:: EXIT)
{
}

void Exit::printNodeInfo() const
{
    std::cout << "Exit : " << name << endl;
}