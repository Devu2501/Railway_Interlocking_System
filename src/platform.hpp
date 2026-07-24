#pragma once

#include "RailwayNode.hpp"

class Platform : public RailwayNode
{
private:
    int platformNumber;

    bool occupied;
public:
    Platform(int id, const string& name, int platformNumber);

    ~Platform() override = default;

    int getPlatformNumber() const;

    bool isOccupied() const;

    void setOccupied(bool status);

    void printNodeInfo() const override;
};
