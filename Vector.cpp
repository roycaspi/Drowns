#include "Vector.h"
#include <cmath>
#include <iomanip>

double Vector::distance(const Vector& v) const //checks the distance between two points
{
	double dx = (double)x - v.getX();
	double dy = (double)y - v.getY();
	return sqrt((dx * dx) + (dy * dy));
}

ostream& operator<<(ostream& os, const Vector& v)
{
	os << fixed << setprecision(2) << v.getX();
	os << " " << fixed << setprecision(2) << v.getY();
	return os;
}
