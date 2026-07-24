#pragma once

#include "RailwayNode.hpp"

enum  SwitchPosition
{
    NORMAL=0,
    REVERSE
};

class Switch : public RailwayNode
{
private:

    SwitchPosition position;

    RailwayNode* commonNode;

    RailwayNode* normalNode;

    RailwayNode* reverseNode;
public:

    Switch(int id, const string& name);
                
    SwitchPosition getPosition() const;

    void setPosition(SwitchPosition position);

    RailwayNode* getCommonNode() const;

    RailwayNode* getNormalNode() const;

    RailwayNode* getReverseNode() const;

    void setCommonNode(RailwayNode* node);

    void setNormalNode(RailwayNode* node);

    void setReverseNode(RailwayNode* node);

    void printNodeInfo() const override;


};