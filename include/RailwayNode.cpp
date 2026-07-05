#include "RailwayNode.hpp"

RailwayNode::RailwayNode(int id,const string& name, RailwayNodeType type)
    : node_id(id),
      name(name),
      type(type)
{
}

int RailwayNode::getNodeId() const
{
    return node_id;
}

 string RailwayNode::getName() const
{
    return name;
}

RailwayNodeType RailwayNode::getType() const
{
    return type;
}

void RailwayNode::addTrack(Track* track)
{
    connectedTracks.push_back(track);
}

const vector<Track*>& RailwayNode::getConnectedTracks() const
{
    return connectedTracks;
}
    




