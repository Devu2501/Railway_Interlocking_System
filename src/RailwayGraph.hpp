#pragma once

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class RailwayNode;
class Track;

class RailwayGraph
{
private:

    vector<RailwayNode*> nodes;

    vector<Track*> tracks;

public:

    RailwayGraph();

    ~RailwayGraph();


    void addNode(RailwayNode* node);

    void addTrack(Track* track);


    const vector<RailwayNode*>& getNodes() const;

    const vector<Track*>& getTracks() const;

    RailwayNode* getNodeById(int id) const;

    Track* getTrackById(int id) const;

    void printNodes() const;

    void printTrackStructure() const;

    void printSwitches() const;

    void printTracks() const;

    void printGraph() const;
};