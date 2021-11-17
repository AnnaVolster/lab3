#pragma once
#include <string>

struct Point { double x; double y; };

class IShape {
public:
	Point* arc = new Point[4];
	virtual ~IShape() = default;

	virtual double GiveSquare()  const = 0;
	virtual void GiveCenterGrav() const = 0;

	virtual double Side(int pos)  const = 0;
	virtual double CoordCenterGrav(int pos) const = 0;
	virtual std::string  Type() const = 0;
	//virtual double Rotate()  const = 0;
	virtual void Rotate(int angle, double xc, double yc) const = 0;
	virtual void Move()  const = 0;
	virtual bool Compare(IShape& const A) const = 0;
	virtual bool Intersection(IShape& const A) const = 0;
	virtual bool Include(IShape& const A) const = 0;

	/*virtual ~IShape()
	{
		delete[] arc;
	}
	*/
};