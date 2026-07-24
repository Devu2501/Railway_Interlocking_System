#pragma once


#include "Station.hpp"
#include "Pathfinder.hpp"
#include "Interlocking.hpp"
#include "Train.hpp"
#include "Route.hpp"

class Simulator
{
private:

    Station station;

    PathFinder pathFinder;

    Interlocking interlocking;

    Train* train;

    Route currentRoute;

    bool routeFound;

    bool routeEstablished;

public:

    Simulator();

    ~Simulator();

    void run();

private:

    void showMenu() const;

    void showStationLayout() const;

    void findRoute();

    void establishRoute();

    void dispatchTrain();

    void releaseRoute();

    void showSwitchStatus() const;

    void showTrackStatus() const;
};