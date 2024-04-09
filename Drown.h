#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
using namespace std;

bool validNum(const string& num);
double stringToDouble(string num);

class Drown
{
private:
	int id;
	Vector speed;
	Vector pos;
	Vector PB;
protected:
	virtual double getA() const = 0;
	virtual double getB() const = 0;
	virtual double getG() const = 0;
public:
	Drown(const string& input, int i);
	Drown(const Drown& other):id(other.id), speed(other.speed), pos(other.pos), PB(other.PB) {}
	virtual ~Drown() {}
	void move(const Vector& GB, const Vector& target, int xMax, int yMax, int seed);
	const Vector& getSpeed() const { return speed; }
	const Vector& getPos() const { return pos; }
	const Vector& getPB() const { return PB; }
	friend ostream& operator << (ostream& out, const Drown& d);
	bool operator < (const Drown& other) const { return id < other.id; }
	virtual char getSign() const = 0;
};
ostream& operator << (ostream& out, const Drown& d);

