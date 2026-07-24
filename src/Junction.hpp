#pragma once

#include "RailwayNode.hpp"

class Junction : public RailwayNode
{
public:

    Junction(int id,const string& name);
            
    void printNodeInfo() const override;
};