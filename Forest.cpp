#include "Drown.h"
#include "MultiRotorDrone.h"
#include "FixedWingHybridDrone.h"
#include "FixedWingDrone.h"
#include "Forest.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>


Forest::Forest(char* simfile, char* drownfile)
{
	drownum = -1; //reset the variables
	iterations = -1;
	ifstream sim(simfile);
	ifstream dfile(drownfile);
	string line, word;
	double nums[2];
	int i = 0;
	if (!sim.is_open() || !dfile.is_open())
	{
		cerr << "Error; invalid input" << endl;
		exit(1);
	}
	getline(sim, line); //reads the coordinates of forest
	stringstream st(line);
	st >> xMin;
	st >> yMin;
	st >> xMax;
	st >> yMax;
	if (xMin > xMax || yMin > yMax)
	{
		cerr << "Error; invalid input" << endl;
		exit(1);
	}
	getline(sim, line); //reads the coordinates of the target
	st.clear();
	st.str(line);
	while (st >> word) //check if the input is valid
	{
		if (!validNum(word))
		{
			cerr << "Error; invalid input" << endl;
			exit(1);
		}
		nums[i] = stringToDouble(word);
		i++;
	}
	if (i < 2) //checks there is more than one number
	{
		cerr << "Error; invalid input" << endl;
		exit(1);
	}
	target.setX(nums[0]);
	target.setY(nums[1]);
	GB.setX(-1);
	GB.setY(-1);
	getline(sim, line); //reads the number of iterations
	st.clear();
	st.str(line);
	st >> iterations;
	if (iterations == -1) //checks if the number is valid
	{
		cerr << "Error; invalid input" << endl;
		exit(1);
	}
	getline(dfile, line); //reads the number of drowns
	st.clear();
	st.str(line);;
	st >> drownum;
	if (drownum == -1)
	{
		cerr << "Error; invalid input" << endl;
		exit(1);
	}
	for (int i = 0; i < xMax; i++) //resets all the areas of the forest
	{
		for (int j = 0; j < yMax; j++)
		{
			areas[i][j].setX(i);
			areas[i][j].setY(j);
		}
	}
	Drown* newdrown = NULL;
	for (int i = 0; i < drownum; i++)//creates the drowns
	{
		getline(dfile, line);
		switch (line[0])
		{
		case 'H': drownsTree.insert(new FixedWingHybridDrone(line, i)); newdrown = new FixedWingHybridDrone(line, i); break;
		case 'M': drownsTree.insert(new MultiRotorDrone(line, i)); newdrown = new MultiRotorDrone(line, i); break;
		case'S': drownsTree.insert(new SingleRotorDrone(line, i)); newdrown = new SingleRotorDrone(line, i); break;
		case 'W': drownsTree.insert(new FixedWingDrone(line, i)); newdrown = new FixedWingDrone(line, i); break;
		}
		if (newdrown)
		{
			areas[(int)newdrown->getPos().getX()][(int)newdrown->getPos().getY()]++; //add a drown to the area
			if (GB.distance(target) > newdrown->getPos().distance(target)) //updates the global best
				GB = newdrown->getPos();
		}
	}
	delete newdrown;
}
Forest::~Forest()
{
	for (int i = 0; i < xMax; i++) //deletes the areas
	{
		delete[] areas[i];
	}
	delete[] areas;
	drownsTree.clear();
}
Forest::Forest(const Forest& other)
{
	drownum = 0;
	*this = other;
}
Forest& Forest::operator = (const Forest& other)
{
	if (this != &other)
	{
		drownsTree = other.drownsTree;
		GB = other.GB;
		target = other.target;
		drownum = other.drownum;
		iterations = other.iterations;
	}
	return *this;
}
const int Forest::operator()(int a, int b)
{
	return areas[a][b].getDrownNum();
}

void Forest::run(char* outfile, int seed)
{
	BSNode<Drown*>* node = drownsTree.getRoot();
	for (int i = 1; i <= iterations; i++) //moves each drown and checks if they reached the target
	{
		node = drownsTree.getRoot();
		while (node != NULL)
		{
			areas[(int)node->getValue()->getPos().getX()][(int)node->getValue()->getPos().getY()]--; //remove a drown from the area
			node->getValue()->move(GB, target, xMax, yMax, seed);
			areas[(int)node->getValue()->getPos().getX()][(int)node->getValue()->getPos().getY()]++; //add a drown to the area
			if (GB.distance(target) > node->getValue()->getPos().distance(target)) //updates the global best
				GB = node->getValue()->getPos();
			if ((int)GB.getX() == (int)target.getX() && (int)GB.getY() == (int)target.getY()) // a drown is in the targets area
			{
				ofstream out(outfile);
				out << i << endl;
				drownsTree.print();
				BSNode<Drown*>* node2 = drownsTree.getRoot();
				while(node2 != NULL)
				{
					out << *node2->getValue() << endl;
					node2 = node2->getRight();
				}
				return;
			}
			node = node->getRight();
		}
	}
	ofstream out(outfile);
	out << iterations << endl;
	node = drownsTree.getRoot();
	while (node != NULL)
	{
		out << *node->getValue() << endl;
		node = node->getRight();
	}
}

