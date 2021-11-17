#pragma once
#include "ShapeBase.h"

class Square : public ShapeBase 
{

public:

	Square(int side): _side(side){}

	virtual double GiveSquare() const { return _side * _side; }
	virtual double GiveCenterGrav() const { return _side / 2; }

	virtual double Side(int pos) const { return _side; }
	
	virtual std::string Type() const {
		std::string typeShape = "Square";
		return typeShape;
	}
	//virtual double Rotate(int pos)  const = 0;
	//virtual double Move(int pos)  const = 0;

private:
	int _side;
};