Drowns

Overview

The Drowns project is a C++ simulation that models four different types of drones—Single Rotor Drone, Multi Rotor Drone, Fixed Wing Drone, and Fixed Wing Hybrid Drone—searching for a target within a forest environment. Each drone type exhibits unique movement patterns and search strategies, providing a comprehensive simulation of aerial search operations.

Features

Diverse Drone Models: Simulates four distinct drone types, each with specific characteristics and behaviors.
Forest Environment: Represents the search area with varying terrain and obstacles.
Search Algorithms: Implements different search strategies tailored to each drone type.
Object-Oriented Design: Utilizes classes and inheritance to model drones and environment components effectively.

Installation

To set up the project locally:

Clone the repository:

bash
Copy
Edit
git clone https://github.com/roycaspi/Drowns.git
cd Drowns
Ensure you have a C++ compiler installed (GCC recommended).

Compilation
Compile the program using:

bash
Copy
Edit
g++ -o drowns main.cpp Area.cpp BSNode.cpp BSTree.cpp Drown.cpp FixedWingDrone.cpp FixedWingHybridDrone.cpp Forest.cpp MultiRotorDrone.cpp SingleRotorDrone.cpp Vector.cpp
Usage
Run the executable:

bash
Copy
Edit
./drowns
Simulation Instructions
Initialization: Upon running the program, the forest environment and drones are initialized.
Simulation Execution: The drones begin their search for the target within the forest, each following its unique algorithm.
Output: The program outputs the progress and results of the search, including which drone locates the target and the path taken.
Code Structure
The project follows an object-oriented design with the following key components:

Drone Classes: Abstract Drown class serving as a base for specific drone types:
SingleRotorDrone
MultiRotorDrone
FixedWingDrone
FixedWingHybridDrone
Environment Classes:
Forest: Represents the search area with trees and obstacles.
Area: Defines specific regions within the forest.
Data Structures:
Vector: Implements vector mathematics for drone movement.
BSTree and BSNode: Binary search tree structures used for efficient data management.
Contributions
Contributions are welcome! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -m 'Add new feature').
Push to the branch (git push origin feature-branch).
Open a pull request.
