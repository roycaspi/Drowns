#pragma once
#include "Drown.h"
class FixedWingDrone:public virtual Drown
{
private:
protected:
	double getA() const { return 0.25; }
	double getB() const { return 1; }
	double getG() const { return 1; }
public:
	FixedWingDrone(const string& input, int i): Drown(input, i) {}
	FixedWingDrone(const Drown& other) :Drown(other) {}
	char getSign() const { return 'W'; }
};

