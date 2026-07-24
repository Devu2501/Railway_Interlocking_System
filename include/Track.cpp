#include "Track.hpp"

Track::Track(int id, RailwayNode* from, RailwayNode* to)

    : track_id(id),
      from(from),
      to(to),
      occupied(false),
      locked(false)
{
}

int Track::getTrackId() const
{
    return track_id;
}

RailwayNode* Track::getFrom() const
{
    return from;
}

RailwayNode* Track::getTo() const
{
    return to;
}

bool Track::isOccupied() const
{
    return occupied;
}

bool Track::isLocked() const
{
    return locked;
}

void Track::setOccupied(bool state)
{
    this->occupied = state;
}

void Track::setLocked(bool state)
{
    this->locked = state;
}

void Track::printTrackStatus() const
{
    cout << "Track" << track_id << ":";
    
    if(locked)
        cout << "LOCKED";
    else
        cout << "FREE";

    cout << '\n';
}