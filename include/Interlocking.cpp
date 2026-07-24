
#include "Route.hpp"
#include "Interlocking.hpp"
#include "Switch.hpp"
#include "Track.hpp"


bool Interlocking :: configureSwitches(Route& route)
{
    for (int i = 0; i < route.size() - 1; ++i)
    {
        RailwayNode* currentNode = route[i];
        RailwayNode* nextNode = route[i + 1];

        if (currentNode->getType() == RailwayNodeType::SWITCH)
        {
            Switch* sw = dynamic_cast<Switch*>(currentNode);

            if (sw->getNormalNode() == nextNode)
            {
                sw->setPosition(SwitchPosition::NORMAL);
            }
            else if (sw->getReverseNode() == nextNode)
            {
                sw->setPosition(SwitchPosition::REVERSE);
            }
        }
    }

    return true;
}

bool Interlocking:: lockTracks(Route& route)
{
    for (int i = 0; i < route.size() - 1; ++i)
    {
        RailwayNode* currentNode = route[i];
        RailwayNode* nextNode = route[i + 1];

        for (Track* track : currentNode->getConnectedTracks())
        {
            if ((track->getFrom() == currentNode && track->getTo() == nextNode) ||
                (track->getFrom() == nextNode && track->getTo() == currentNode))
            {
                track->setLocked(true);
                break;
            }
        }
    }
    return true;
}

bool Interlocking::checkRoute(Route& route)
{
    for (int i = 0; i < route.size() - 1; ++i)
    {
        RailwayNode* currentNode = route[i];
        RailwayNode* nextNode = route[i + 1];

        for (Track* track : currentNode->getConnectedTracks())
        {
            if ((track->getFrom() == currentNode && track->getTo() == nextNode) ||
                (track->getFrom() == nextNode && track->getTo() == currentNode))
            {
                if (track->isOccupied() || track->isLocked())
                {
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

bool Interlocking::setRoute(Route& route)
{
    if (!checkRoute(route))
    {
        return false;
    }

    configureSwitches(route);
    lockTracks(route);

    return true;
}

bool Interlocking::releaseRoute(Route& route)
{
    for (int i = 0; i < route.size() - 1; ++i)
    {
        RailwayNode* currentNode = route[i];
        RailwayNode* nextNode = route[i + 1];

        for (Track* track : currentNode->getConnectedTracks())
        {
            if ((track->getFrom() == currentNode && track->getTo() == nextNode) ||
                (track->getFrom() == nextNode && track->getTo() == currentNode))
            {
                track->setLocked(false);
                break;
            }
        }
    }
    return true;
}



