#pragma once

#include "RailwayNode.hpp"

class Exit : public RailwayNode
{

public:
    Exit(int id, const string& name); 

    ~Exit () override = default;

    void printNodeInfo() const override;

};

