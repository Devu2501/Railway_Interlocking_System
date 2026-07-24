#pragma once

#include "RailwayNode.hpp" 

class Route
{
private:

   vector<RailwayNode*> path;

public:

    Route();

    void addNode(RailwayNode* node);

    void clear();

    bool empty() const;

    int size() const;

    RailwayNode* operator[](int index) const;

    const vector<RailwayNode*>& getPath() const;
    
    vector<Track*> getTracks() const;

    void printRoute() const;

    void printCurrentRouteStatus() const;
};