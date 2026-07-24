#pragma once 

#include<iostream>
#include<vector>
#include<string>

using namespace std;


enum RailwayNodeType
{
   SWITCH=0,
   SIGNAL,
   PLATFORM,
   ENTRY,
   EXIT,
   JUNCTION
};

class Track; //Forward declaration of Track class

class RailwayNode
{
protected:
    int node_id;

    string name;
    
    RailwayNodeType type;

    vector<Track*> connectedTracks;

public:

   RailwayNode(int id, const string& name, RailwayNodeType type);

    virtual ~RailwayNode()=default;

    int getNodeId() const;

    string getName() const;

    RailwayNodeType getType() const;

    const vector<Track*>& getConnectedTracks() const;

    void addTrack(Track* track);

    virtual void printNodeInfo() const = 0;   


};