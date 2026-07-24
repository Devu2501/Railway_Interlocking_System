#pragma once 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class RailwayNode; //forward declaration of RailwayNode class

class Track
{
private:

    bool occupied; 

    bool locked; 

    int track_id;

    RailwayNode* from; //Pointer to the starting railway node

    RailwayNode* to;   //Pointer to the ending railway node


    public:

    Track(int id, RailwayNode* start, RailwayNode* end); 

    virtual ~Track()=default;

    int getTrackId() const;

    bool isOccupied() const;

    bool isLocked() const;

    void setOccupied(bool state);

    void setLocked(bool state);

    RailwayNode* getFrom() const;

    RailwayNode* getTo() const;

    void printTrackStatus() const;
    
    
};
