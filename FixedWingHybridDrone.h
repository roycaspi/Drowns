#pragma once
#include "Drown.h"
#include "SingleRotorDrone.h"
#include "FixedWingDrone.h"
class FixedWingHybridDrone:public SingleRotorDrone, public FixedWingDrone
{
private:
protected:
	double getA() const { return 0.01; }
	double getB() const { return -0.1; }
	double getG() const { return -0.25; }
public:
	FixedWingHybridDrone(const string& input, int i) : Drown(input, i), FixedWingDrone(input, i),
		SingleRotorDrone(input, i) {}
	FixedWingHybridDrone(const Drown& other) :Drown(other), FixedWingDrone(other),
		SingleRotorDrone(other) {}
	char getSign() const { return 'H'; }

};

