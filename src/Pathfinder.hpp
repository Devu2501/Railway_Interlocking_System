#pragma once

#include "Route.hpp"

class RailwayGraph;
class RailwayNode;

class PathFinder
{
public:

    Route findRoute(const RailwayGraph& graph, RailwayNode* source,RailwayNode* destination);
                   
};