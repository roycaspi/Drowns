#include "Drown.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

double stringToDouble(string num)
{
	double d;
	stringstream st(num);
	st >> d;
	return d;
}

bool validNum(const string& num) //checks if the string is a valid number
{
	int dotCount = 0;
	for (int i = 0; i < (int)num.length(); i++)
	{
		if (num[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return false;
		if (!isdigit(num[i]) && num[i] != '.')
			return false;
	}
	return true;
}

Drown::Drown(const string& input, int i)
{
	id = i;
	string word;
	double nums[4];
	int j = 0;
	stringstream st(input);
	st >> word; //skips the sign of the drown
	while (st >> word) //checks if each number is valid
	{
		if (!validNum(word))
		{
			cerr << "Error; invalid input" << endl;
			exit(1);
		}
		nums[j] = stringToDouble(word);
		j++;
	}
	pos.setX(nums[0]);
	pos.setY(nums[1]);
	speed.setX(nums[2]);
	speed.setY(nums[3]);
	PB = pos;
}

void Drown::move(const Vector& GB, const Vector& target, int xMax, int yMax, int seed)
{
	srand(time(new time_t(seed)));
	Vector newPos = pos + speed;
	if (newPos.getX() > xMax)	// checks if the drown went out of bounds
		newPos.setX(xMax);
	if (newPos.getY() > yMax)
		newPos.setY(yMax);
	if (newPos.getX() < 0)
		newPos.setX(0);
	if (newPos.getY() < 0)
		newPos.setY(0);
	double	r1 = ((double)rand() / (RAND_MAX)), r2 = ((double)rand() / (RAND_MAX));
	speed = (speed * getA()) + ((PB - pos) * r1 * getB()) + ((GB - pos) * r2 * getG());
	pos = newPos;
	if (newPos.distance(target) < PB.distance(target)) //updates the personal best of a drown
		PB = newPos;
}
ostream& operator << (ostream& out, const Drown& d)
{
	out << d.getSign() << " " << d.getPos();
	return out;
}
