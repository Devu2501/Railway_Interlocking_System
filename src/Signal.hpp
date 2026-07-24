#pragma once

#include "RailwayNode.hpp"

enum SignalColor
{
    RED=0,
    YELLOW,
    GREEN
};

class Signal : public RailwayNode
{
private:

    SignalColor color;

public:

    Signal(int id,const string& name);
           

    SignalColor getColor() const;

    void setColor(SignalColor color);

    void printNodeInfo() const override;
};