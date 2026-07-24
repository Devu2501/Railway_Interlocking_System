#pragma once

class Route;

class Interlocking
{

private:

    bool configureSwitches(Route& route);

    bool lockTracks(Route& route);

public:


    bool checkRoute(Route& route);

    bool setRoute(Route& route);

    bool releaseRoute(Route& route);
};