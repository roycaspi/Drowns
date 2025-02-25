# Drowns (Drone Simulation)

## Overview
A **C++ simulation** modeling different types of drones—Single Rotor Drone, Multi Rotor Drone, Fixed Wing Drone, and Fixed Wing Hybrid Drone—searching for a target in a forest environment.

## Features
- Simulates **four types of drones** with unique movement patterns.
- Models **aerial search and rescue operations**.
- Uses **different search algorithms** for efficiency.
- Implements an **object-oriented design**.
- Handles **obstacles and terrain variations**.

## Installation
```bash
git clone https://github.com/roycaspi/Drowns.git
cd Drowns
```

## Compilation
```bash
g++ -o drowns main.cpp Area.cpp BSNode.cpp BSTree.cpp Drown.cpp FixedWingDrone.cpp FixedWingHybridDrone.cpp Forest.cpp MultiRotorDrone.cpp SingleRotorDrone.cpp Vector.cpp
```

## Usage
```bash
./drowns
```

## Example Simulation Output
```
Initializing simulation...
Deploying Single Rotor Drone...
Scanning area... No target found.
Deploying Multi Rotor Drone...
Target found at (5,3)!

Simulation complete.
```
