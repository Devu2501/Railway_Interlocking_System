#include "Pathfinder.hpp"
#include "RailwayGraph.hpp"
#include "RailwayNode.hpp"
#include "Track.hpp"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

Route PathFinder::findRoute(const RailwayGraph& graph,RailwayNode* source,RailwayNode* destination)                      
{
    Route route;

    if(source == nullptr || destination == nullptr)
        return route;

    queue<RailwayNode*> q;

    unordered_set<RailwayNode*> visited;

    unordered_map<RailwayNode*, RailwayNode*> parent;

    q.push(source);
    visited.insert(source);
    parent[source] = nullptr;

    while(!q.empty())
    {
        RailwayNode* current = q.front();
        q.pop();

        if(current == destination)
            break;

        for(Track* track : current->getConnectedTracks())
        {
            RailwayNode* next;
            if(track->getFrom() == current)
                next = track->getTo();
            else
                next = track->getFrom();


            if(next == nullptr)
                continue;

            if(visited.count(next))
                continue;

                
            visited.insert(next);
            parent[next] = current;
            q.push(next);
        }
    }

    if(parent.find(destination) == parent.end())
        return route;

    vector<RailwayNode*> reversedPath;

    RailwayNode* current = destination;

    while(current != nullptr)
    {
        reversedPath.push_back(current);
        current = parent[current];
    }

    reverse(reversedPath.begin(), reversedPath.end());

    for(auto node : reversedPath)
        route.addNode(node);

    return route;
}