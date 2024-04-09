#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include "BSTree.h"
#include "Drown.h"
#include "Forest.h"
#include "Vector.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4 || argc > 5)
	{
		cerr << "Error; invalid input";
		exit(1);
	}
	Forest* f = new Forest(argv[1], argv[2]);
	if (argc == 5) //checks if a seed was given
	{
		string seed = argv[4];
		for (int i = 0; i < seed.length(); i++) //checks if the seed is an integer
		{
			if (seed[i] == '.')
			{
				cerr << "Error; invalid input";
				exit(1);
			}
		}
		f->run(argv[3], (int)stringToDouble(argv[4]));
	}
	else
		f->run(argv[3], NULL);
	cout << f->operator()(10, 2); //prints the number of drowns that found the target
	return 0;
}