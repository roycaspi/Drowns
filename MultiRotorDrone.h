#pragma once
#include "Drown.h"
class MultiRotorDrone:public Drown
{
private:
protected:
	double getA() const { return 0.05; }
	double getB() const { return 0.1; }
	double getG() const { return 0; }
public:
	MultiRotorDrone(const string& input, int i) : Drown(input, i) {}
	MultiRotorDrone(const Drown& other) :Drown(other) {}
	char getSign() const { return 'M'; }
};

