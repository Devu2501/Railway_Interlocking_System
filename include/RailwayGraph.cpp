

#include "RailwayGraph.hpp"
#include "RailwayNode.hpp"
#include "Track.hpp"

RailwayGraph::RailwayGraph()
{
}

RailwayGraph::~RailwayGraph()
{
    for(auto track : tracks)
        delete track;

    for(auto node : nodes)
        delete node;
}

void RailwayGraph::addNode(RailwayNode* node)
{
    nodes.push_back(node);
}

void RailwayGraph::addTrack(Track* track)
{
    tracks.push_back(track);

    track->getFrom()->addTrack(track);
    track->getTo()->addTrack(track);
}

const vector<RailwayNode*>& RailwayGraph::getNodes() const
{
    return nodes;
}

const vector<Track*>& RailwayGraph::getTracks() const
{
    return tracks;
}

RailwayNode* RailwayGraph::getNodeById(int id) const
{
    for(auto node : nodes)
    {
        if(node->getNodeId()==id)
            return node;
    }

    return nullptr;
}

Track* RailwayGraph::getTrackById(int id) const
{
    for(auto track : tracks)
    {
        if(track->getTrackId()==id)
            return track;
    }

    return nullptr;
}

void RailwayGraph::printNodes() const
{
    cout<<"========== Nodes ==========\n\n";

    for(auto node:nodes)
        node->printNodeInfo();

    cout<<endl;
}

void RailwayGraph::printTrackStructure() const
{
    cout<<"========== Track Structure ==========\n\n";

    for(auto track:tracks)
    {
        cout  << "Track "<< track->getTrackId() << " : "  << track->getFrom()->getName()
              << " <----> "  << track->getTo()->getName() 
              << '\n';
           
    }

    cout<<endl;
}

void RailwayGraph::printSwitches() const
{
    cout<<"========== Switches ==========\n\n";

    for(auto node:nodes)
    {
        if(node->getType() == RailwayNodeType::SWITCH)
            node->printNodeInfo();
    }

    cout<<endl;
}

void RailwayGraph::printTracks() const
{
     cout<<"========== Tracks ==========\n\n";

    for(auto track:tracks)
    {
       track->printTrackStatus();
           
    }

    cout<<endl;
}

void RailwayGraph::printGraph() const
{
    printNodes();

    printTrackStructure();
}