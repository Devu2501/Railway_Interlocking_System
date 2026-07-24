
#include "Signal.hpp"

Signal::Signal(int id, const string& name) : RailwayNode(id, name, RailwayNodeType::SIGNAL),
color(SignalColor::RED)
{
}

SignalColor Signal::getColor() const
{
    return color;
}

void Signal::setColor(SignalColor newColor)
{
    this->color = newColor;
}

void Signal::printNodeInfo() const
{
    cout << "Signal : "<<name<<" ";
           
    switch(color)
    {
        case SignalColor::RED:
            cout << "[RED]";
            break;

        case SignalColor::YELLOW:
            cout << "[YELLOW]";
            break;

        case SignalColor::GREEN:
            cout << "[GREEN]";
            break;
    }
    cout << endl;
}