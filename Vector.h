#pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	double x;
	double y;
public:
	Vector() :x(-1), y(-1) {}
	Vector(int x, int y):x(x), y(y) {}
	Vector(const Vector& other):x(other.x), y(other.y){}
	~Vector(){}
	double distance(const Vector& v) const;
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double newx) { x = newx; }
	void setY(double newy) { y = newy; }
	Vector& operator = (const Vector& v) { x = v.x; y = v.y; return *this; }
	Vector operator + (const Vector& v) const { Vector vsum; vsum.x = x + v.x; vsum.y = y + v.y; return vsum; }
	Vector operator - (const Vector& v) const { Vector vsum; vsum.x = x - v.x; vsum.y = y - v.y; return vsum; }
	Vector operator * (double num) { Vector vsum; vsum.x = x * num; vsum.y = y * num; return vsum; }
	friend ostream& operator<<(ostream& os, const Vector& v);
};

