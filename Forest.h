#pragma once
#include <iostream>
#include <string>
#include "Area.h"
#include "Drown.h"
#include "Vector.h"
#include <fstream>
#include "BSTree.h"

using namespace std;
class Forest
{
private:
	Vector GB;
	Vector target;
	Area areas[72][42];
	BSTree<Drown*> drownsTree;
	//Drown** drownsArray;
	int drownum;
	int iterations;
	int xMax;
	int xMin;
	int yMax;
	int yMin;
public:
	Forest(char* simfile, char* drownfile);
	Forest(const Forest& other);
	void run(char* outfile, int seed);
	Forest& operator = (const Forest& other);
	const int operator()(int a, int b);
	~Forest();
};

