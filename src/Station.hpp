#pragma once

#include "RailwayGraph.hpp"


class Station
{
private:

    RailwayGraph graph;

    void buildLayout();

public:

    Station();

    const RailwayGraph& getGraph() const;

    void showLayout() const;
};