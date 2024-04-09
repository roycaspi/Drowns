#pragma once
class Area
{
private:
	int x;
	int y;
	int drownum;
public:
	Area(int newx, int newy) :x(newx), y(newy), drownum(0) {}
	Area(const Area& other):x(other.x), y(other.y), drownum(other.drownum) {}
	Area():x(-1), y(-1), drownum(0) {}
	~Area() {}
	int getDrownNum() const { return drownum; }
	void setX(int newx) { x = newx; }
	void setY(int newy) { y = newy; }
	Area& operator++();
	const Area operator++(int);
	Area& operator -- ();
	const Area operator -- (int);

};

