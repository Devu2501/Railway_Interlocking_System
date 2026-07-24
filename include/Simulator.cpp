#include "Simulator.hpp"


Simulator::Simulator()
{   


    train = nullptr;

    routeFound = false;

    routeEstablished = false;
}

Simulator::~Simulator()
{
    if(train != nullptr)
        delete train;
}

void Simulator::showMenu() const
{
    cout << "\n=====================================\n";
    cout << " Railway Interlocking Simulator\n";
    cout << "=====================================\n";

    cout << "1. Show Station Layout\n";
    cout << "2. Find Route\n";
    cout << "3. Establish Route\n";
    cout << "4. Dispatch Train\n";
    cout << "5. Release Route\n";
    cout << "6. Show Switch Status\n";
    cout << "7. Show Track Status\n";
    cout << "8. Exit\n";

    cout << "\nEnter Choice : ";
}

void Simulator::showStationLayout() const
{
    station.showLayout();
}

void Simulator::findRoute()
{
    int choice;

    cout << "\nDestination\n";
    cout << "1. Exit\n";
    cout << "2. Platform 1\n";
    cout << "3. Platform 2\n";

    cout << "\nEnter Choice : ";

    cin >> choice;


    RailwayNode* source = station.getGraph().getNodeById(1);

    RailwayNode* destination = nullptr;

    switch(choice)
    {
        case 1:
            destination = station.getGraph().getNodeById(8);
            break;

        case 2:
            destination = station.getGraph().getNodeById(6);
            break;

        case 3:
            destination = station.getGraph().getNodeById(7);
            break;

        default:
            cout << "Invalid Choice\n";
            return;
    }

    currentRoute = pathFinder.findRoute(station.getGraph(),source,destination);

    routeFound = true;

    cout << "\nRoute Found\n\n";

    currentRoute.printRoute();
}

void Simulator::establishRoute()
{
    if(!routeFound)
    {
        cout << "\nPlease find a route first.\n";
        return;
    }

    if(interlocking.setRoute(currentRoute))
    {
        routeEstablished = true;

        cout << "\nRoute Established Successfully.\n";
    }
    else
    {
        cout << "\nRoute Rejected.\n";
    }
}

void Simulator::dispatchTrain()
{
    if(!routeEstablished)
    {
        cout << "\nPlease establish a route first.\n";
        return;
    }

    string trainName;

    cout << "\nEnter Train Name : ";

    cin.ignore();

    getline(cin, trainName);

    if(train != nullptr)
        delete train;

    train = new Train(trainName);

    train->assignRoute(&currentRoute);

    train->startJourney();

    cout << "\nJourney Completed Successfully.\n";
}

void Simulator::releaseRoute()
{
    if(!routeEstablished)
    {
        cout << "\nNo active route.\n";
        return;
    }

    interlocking.releaseRoute(currentRoute);

    routeEstablished = false;

    cout << "\nRoute Released Successfully.\n";
}

void Simulator::showSwitchStatus() const
{
    station.getGraph().printSwitches();
}

void Simulator:: showTrackStatus() const
{
    station.getGraph().printTracks();
}


void Simulator::run()
{
    int choice;

    while (true)
    {
        showMenu();

        cin >> choice;

        switch (choice)
        {
            case 1:
                showStationLayout();
                break;

            case 2:
                findRoute();
                break;

            case 3:
                establishRoute();
                break;

            case 4:
                dispatchTrain();
                break;

            case 5:
                releaseRoute();
                break;

            case 6:
                showSwitchStatus();
                break;

            case 7:
                showTrackStatus();
                break;

            case 8:
                cout << "\nThank you for our using Railway Interlocking Simulator.\n";
                return;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}