
#include "Route.hpp"
#include "Track.hpp"
#include "RailwayNode.hpp"

Route::Route() {}

void Route::addNode(RailwayNode* node)
{
    path.push_back(node);
}

void Route::clear()
{
    path.clear();
}

int Route::size() const
{
    return path.size();
}

bool Route::empty() const
{
    return path.empty();
}

RailwayNode* Route:: operator[](int index) const
{
    if (index >= 0 && index < path.size())
    {
        return path[index];
    }
    else
    {
        throw out_of_range("Index out of range");
    }
}


vector<Track*> Route::getTracks() const
{
    vector<Track*> tracks;

    for (auto i = 0; i < path.size() - 1; ++i)
    {
        RailwayNode* currentNode = path[i];
        RailwayNode* nextNode = path[i + 1];

        for (Track* track : currentNode->getConnectedTracks())
        {
            if ((track->getFrom() == currentNode && track->getTo() == nextNode)
                )
            {
                tracks.push_back(track);
                break;
            }
        }
    }

    return tracks;
}


void Route::printRoute() const
{
     cout << "\n=========== ROUTE ===========\n\n";

    if(path.empty())
    {
        cout << "No Route Found\n";
        return;
    }

    for (auto i=0; i<path.size();i++)
    {
        cout << path[i]->getName();
        if(i + 1 != path.size())
            cout << "\n  |\n  v\n";
    }
    cout<<endl;

}

void Route::printCurrentRouteStatus() const
{
    cout << "\n=========== ROUTE STATUS ===========\n\n";

    if(path.empty())
    {
        cout << "No Route Found\n";
        return;
    }

    const vector<Track*>& tracks = getTracks();

    for (const auto& track : tracks)
    {
        track->printTrackStatus();
    }

    for (const auto& node : path)
    {
       if(node->getType() == RailwayNodeType::SWITCH){node->printNodeInfo();}
    }
}
