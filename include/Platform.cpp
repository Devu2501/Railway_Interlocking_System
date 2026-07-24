#include "Platform.hpp"

Platform::Platform(int id, const string& name, int platformNumber) : RailwayNode(id, name,RailwayNodeType::PLATFORM), platformNumber(platformNumber), occupied(false)
{
}

int Platform::getPlatformNumber() const
{
    return platformNumber;
}
bool Platform::isOccupied() const
{
    return occupied;
}
void Platform::setOccupied(bool status)
{   
    this->occupied = status;
}
void Platform::printNodeInfo() const
{
    cout<<"Platform:"<<platformNumber<<":"<<name<<endl;
}