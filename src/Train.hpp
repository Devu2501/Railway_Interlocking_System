#pragma once

#include <string>
using namespace std;

class Route;
class RailwayNode;

class Train
{
private:

    string trainName;

    Route* route;

    int currentIndex;

    bool moving;

public:

    Train(const string& trainName);

    ~Train();

    void assignRoute(Route* assignedRoute);

    void startJourney();

    void move();

    bool hasReachedDestination() const;

    RailwayNode* getCurrentNode() const;

    void printCurrentPosition() const;

    string getTrainName() const;
};