#include "Switch.hpp"

Switch::Switch(int id, const string& name) : RailwayNode(id, name, RailwayNodeType::SWITCH), position(SwitchPosition::NORMAL),
    commonNode(nullptr), normalNode(nullptr), reverseNode(nullptr)
{
}

SwitchPosition Switch::getPosition() const
{
    return position;
}

void Switch::setPosition(SwitchPosition newPosition)
{
    this->position = newPosition;
}

RailwayNode* Switch::getCommonNode() const
{
    return commonNode;
}

RailwayNode* Switch::getNormalNode() const
{
    return normalNode;
}

RailwayNode* Switch::getReverseNode() const
{
    return reverseNode;
}

void Switch::setCommonNode(RailwayNode* node)
{
    this->commonNode = node;
}

void Switch::setNormalNode(RailwayNode* node)
{
    this->normalNode = node;
}

void Switch::setReverseNode(RailwayNode* node)
{
    this->reverseNode = node;
}

void Switch::printNodeInfo() const
{
    cout << "Switch : "<<name<<" ";

    switch(position)
    {
        case SwitchPosition::NORMAL:
            cout << "[NORMAL]";
            break;

        case SwitchPosition::REVERSE:
            cout << "[REVERSE]";
            break;
    }
    cout << endl;
}