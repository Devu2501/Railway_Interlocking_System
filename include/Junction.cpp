#include "Junction.hpp"

Junction::Junction(int id,const string& name)
    : RailwayNode(id,name,RailwayNodeType::JUNCTION)
{
}
void Junction::printNodeInfo() const
{
    cout << "Junction: " << name << endl;
}