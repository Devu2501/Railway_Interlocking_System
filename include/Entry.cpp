#include "Entry.hpp"

Entry:: Entry(int id,const string &name)
    : RailwayNode(id,name,RailwayNodeType:: ENTRY)
{
}



void Entry::printNodeInfo() const
{
    std::cout << "Entry : " << name << endl;
} 