#pragma once 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//different types of railway nodes
enum class RailwayNodeType
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

    vector<Track*> connectedTracks; //Vector to store connected tracks

public:

   RailwayNode(int id, const string& name, RailwayNodeType type);

    virtual ~RailwayNode()=default;

    int getNodeId() const;

    string getName() const;

    RailwayNodeType getType() const;

    const vector<Track*>& getConnectedTracks() const;

    void addTrack(Track* track);

    virtual void printNodeInfo() const = 0; //Pure virtual function to print node information  


};