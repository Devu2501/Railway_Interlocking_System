#pragma once

#include "RailwayNode.hpp"

class Entry : public RailwayNode
{

public:
    Entry(int id, const string& name); 

    ~Entry () override = default;

    void printNodeInfo() const override;

};