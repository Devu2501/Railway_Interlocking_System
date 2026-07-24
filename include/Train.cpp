#include "Train.hpp"
#include "Route.hpp"
#include "RailwayNode.hpp"



Train::Train(const string& trainName)
{
    this->trainName = trainName;

    route = nullptr;

    currentIndex = 0;

    moving = false;
}

Train::~Train()
{
}

void Train::assignRoute(Route* assignedRoute)
{
    this->route = assignedRoute;
}

void Train::startJourney()
{
    if(route == nullptr)
    {
        cout << "No Route Assigned!\n";
        return;
    }

    if(route->empty())
    {
        cout << "Empty Route!\n";
        return;
    }

    moving = true;

    cout << "\n=====================================\n";
    cout << trainName << " Starting Journey...\n";
    cout << "=====================================\n\n";

    printCurrentPosition();

    while(!hasReachedDestination())
    {
        move();
    }

    cout << "\n=====================================\n";
    cout << trainName << " Reached Destination.\n";
    cout << "=====================================\n";

    moving = false;
}

void Train::move()
{
    if(hasReachedDestination())
        return;

    currentIndex++;

    printCurrentPosition();
}

bool Train::hasReachedDestination() const
{
    if(route == nullptr)
        return true;

    return currentIndex >= route->size() - 1;
}

RailwayNode* Train::getCurrentNode() const
{
    if(route == nullptr)
        return nullptr;

    return (*route)[currentIndex];
}

void Train::printCurrentPosition() const
{
    RailwayNode* current = getCurrentNode();

    if(current == nullptr)
        return;

    cout << trainName << " is at " << current->getName() <<endl;
            
}

string Train::getTrainName() const
{
    return trainName;
}


