#pragma once
#include "Drown.h"
class SingleRotorDrone:public virtual Drown
{
private:
protected:
	double getA() const { return 0.01; }
	double getB() const { return -0.1; }
	double getG() const { return -0.25; }
public:
	SingleRotorDrone(const string& input, int i) : Drown(input, i) {}
	SingleRotorDrone(const Drown& other) :Drown(other) {}
	char getSign() const { return 'S'; }
};

