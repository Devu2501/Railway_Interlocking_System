# 🚆 Railway Interlocking System Simulator

A console-based **Railway Interlocking System Simulator** developed in **C++** that demonstrates the core principles of railway route management and safe train movement using **Object-Oriented Programming (OOP)** and **graph algorithms**.

The simulator models a railway station as a graph consisting of **entry/exit points, junctions, switches, platforms, and tracks**. Given a source and destination, it computes a valid route using **Breadth-First Search (BFS)** and establishes it through an **interlocking mechanism** that aligns switches, locks the required tracks, and prevents conflicting train movements.

Once a route is successfully established, a train can be dispatched to travel along the reserved path. The simulator also provides an interactive console interface for route establishment, train dispatch, monitoring switch and track states, and releasing routes after train movement.

The project is designed to demonstrate the practical application of **Object-Oriented Programming, graph traversal algorithms, and resource management** while simulating the workflow of a simplified railway interlocking system.

---

## ✨ Features

- 🚆 Models a railway station using interconnected nodes and tracks.
- 🔍 Computes routes between railway nodes using **Breadth-First Search (BFS)**.
- 🔀 Automatically configures switch positions based on the selected route.
- 🔒 Locks tracks during route establishment to prevent conflicting train movements.
- ✅ Validates route availability before allowing train dispatch.
- 🚄 Simulates train movement along an established route.
- 🎮 Interactive menu-driven console application for station operations.
- 🏗️ Modular object-oriented architecture for easy future extensions.

---

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:** Object-Oriented Programming (OOP)
- **Algorithms:** Breadth-First Search (BFS), Graph Traversal
- **Libraries:** C++ Standard Template Library (STL)
- **Version Control:** Git & GitHub


---

## 🏗️ System Architecture

The simulator follows a modular object-oriented architecture where each component is responsible for a single aspect of the railway interlocking system.

```text
                    +----------------------+
                    |      Simulator       |
                    +----------+-----------+
                               |
          +--------------------+--------------------+
          |                    |                    |
          v                    v                    v
   +--------------+    +---------------+    +---------------+
   |   Station    |    |  PathFinder   |    | Interlocking  |
   +------+-------+    +-------+-------+    +-------+-------+
          |                      |                    |
          |                      |                    |
          v                      v                    |
   +--------------+       +--------------+           |
   | RailwayGraph |------>|    Route     |<----------+
   +------+-------+       +--------------+
          |
          |
          v
   +-------------------------------+
   | Railway Infrastructure        |
   |                               |
   | • Entry                       |
   | • Exit                        |
   | • Junctions                   |
   | • Switches                    |
   | • Platforms                   |
   | • Tracks                      |
   +-------------------------------+
                               |
                               |
                               v
                         +-----------+
                         |   Train   |
                         +-----------+
```

The **Simulator** coordinates the complete workflow, while each module is responsible for a specific task. This modular design improves readability, maintainability, and makes future extensions straightforward.

---

## 🚉 Station Layout

The railway station in **Version 1.0** is represented as a graph consisting of an **Entry**, **Exit**, **two Junctions**, **two Switches**, **two Platforms**, and the connecting tracks.

```text

Entry
  │
 J1
  │
 SW1 ─────────► J2 ─────────► Exit
  │
  ▼
 SW2
 ├────────► Platform1
 └────────► Platform2
                  
```

#### Switch Configuration

| Switch | Normal Position | Reverse Position |
|---------|-----------------|------------------|
| **SW1** | J2 (towards Exit) | SW2 |
| **SW2** | Platform 1 | Platform 2 |

During route establishment, the **Interlocking** module automatically configures the switches according to the selected destination before allowing train movement.

---

## 🔄 System Workflow

The simulator follows the workflow shown below when a train is dispatched.

```text
                 User
                   │
                   ▼
          Select Destination
                   │
                   ▼
        BFS Route Computation
                   │
                   ▼
           Route Successfully Found
                   │
                   ▼
      Interlocking Verification
                   │
         ┌─────────┴─────────┐
         │                   │
         ▼                   ▼
   Route Rejected      Route Accepted
                               │
                               ▼
                    Configure Switches
                               │
                               ▼
                         Lock Tracks
                               │
                               ▼
                       Dispatch Train
                               │
                               ▼
                  Simulate Train Movement
                               │
                               ▼
                         Release Route
                               │
                               ▼
                           End Simulation
```

The interlocking system ensures that a train is dispatched **only after** the route has been validated, switches have been correctly aligned, and all required tracks have been safely reserved.

---

## 🧩 Object-Oriented Design

The project is built using Object-Oriented Programming principles to achieve modularity, maintainability, and extensibility.

| OOP Concept | Implementation |
|-------------|----------------|
| **Encapsulation** | Each class manages its own state and behavior through private data members and public member functions (e.g., `Track`, `Train`, `Switch`). |
| **Inheritance** | `Entry`, `Exit`, `Junction`, `Platform`, and `Switch` inherit from the common `RailwayNode` base class. |
| **Polymorphism** | The simulator works with `RailwayNode*` pointers, allowing different railway node types to be handled uniformly. |
| **Composition** | `Station` owns a `RailwayGraph`, `RailwayGraph` contains railway nodes and tracks, and `Route` stores the sequence of nodes traversed by a train. |
| **Abstraction** | High-level classes such as `PathFinder`, `Interlocking`, and `Simulator` expose simple interfaces while hiding implementation details. |

---

## 🧠 Algorithms & Techniques

The simulator combines graph algorithms with railway domain logic to establish safe train routes.

| Algorithm / Technique | Purpose |
|-----------------------|---------|
| **Breadth-First Search (BFS)** | Computes the shortest valid route between two railway nodes. |
| **Graph Representation** | Models the railway station as a network of interconnected nodes and tracks. |
| **Route Validation** | Ensures all tracks on the selected route are available before establishing it. |
| **Track Locking** | Prevents conflicting train movements by reserving tracks for an active route. |
| **Switch Configuration** | Automatically aligns switches according to the selected route. |

---

## 📂 Project Structure

```text
Railway-Interlocking-System/
│
├── include/
│   ├── RailwayNode.hpp
│   ├── Entry.hpp
│   ├── Exit.hpp
│   ├── Junction.hpp
│   ├── Platform.hpp
│   ├── Switch.hpp
│   ├── Track.hpp
│   ├── RailwayGraph.hpp
│   ├── Route.hpp
│   ├── PathFinder.hpp
│   ├── Interlocking.hpp
│   ├── Train.hpp
│   ├── Station.hpp
│   └── Simulator.hpp
│
├── src/
│   ├── RailwayNode.cpp
│   ├── Entry.cpp
│   ├── Exit.cpp
│   ├── Junction.cpp
│   ├── Platform.cpp
│   ├── Switch.cpp
│   ├── Track.cpp
│   ├── RailwayGraph.cpp
│   ├── Route.cpp
│   ├── PathFinder.cpp
│   ├── Interlocking.cpp
│   ├── Train.cpp
│   ├── Station.cpp
│   ├── Simulator.cpp
│   └── main.cpp
│
├── .gitignore
└── README.md
```

---

## 🎯 Design Decisions

Some key design decisions made during development:

- A **graph-based representation** was chosen to naturally model railway infrastructure and simplify route computation.
- **Breadth-First Search (BFS)** was selected as the routing algorithm because all track segments are treated with equal cost.
- The **Interlocking** module is responsible only for route safety, switch alignment, and track locking.
- A dedicated **Simulator** class coordinates user interaction without embedding application logic inside `main()`.
---
