#include "Station.hpp"

#include "Entry.hpp"
#include "Exit.hpp"
#include "Junction.hpp"
#include "Platform.hpp"
#include "Signal.hpp"
#include "Switch.hpp"
#include "Track.hpp"

Station::Station()
{
    buildLayout();
}

 const RailwayGraph& Station::getGraph() const
{
    return graph;
}

void Station::showLayout() const
{
    graph.printGraph();
}

void Station::buildLayout()
{
   

    auto* entry = new Entry(1, "Entry1");

    auto* j1 = new Junction(2, "J1");

    auto* sw1 = new Switch(3, "SW1");

    auto* sw2 = new Switch(4, "SW2");

    auto* j2 = new Junction(5, "J2");

    auto* p1 = new Platform(6, "Platform1", 1);

    auto* p2 = new Platform(7, "Platform2", 2);

    auto* exit = new Exit(8, "Exit1");


    graph.addNode(entry);

    graph.addNode(j1);

    graph.addNode(sw1);

    graph.addNode(sw2);

    graph.addNode(j2);

    graph.addNode(p1);

    graph.addNode(p2);

    graph.addNode(exit);


  
    // Entry ---- J1
    graph.addTrack(new Track(1, entry, j1));

    // J1 ---- SW1
    graph.addTrack(new Track(2, j1, sw1));


    // SW1 ---- J2
    graph.addTrack(new Track(3, sw1, j2));


    // SW1 ---- SW2
    graph.addTrack(new Track(4, sw1, sw2));


    // SW2 ---- Platform1
    graph.addTrack(new Track(5, sw2, p1));


    // SW2 ---- Platform2
    graph.addTrack(new Track(6, sw2, p2));


    // J2 ---- Exit
    graph.addTrack(new Track(7, j2, exit));



    sw1->setCommonNode(j1);

    sw1->setNormalNode(j2);

    sw1->setReverseNode(sw2);

    sw2->setCommonNode(sw1);

    sw2->setNormalNode(p1);

    sw2->setReverseNode(p2);


}