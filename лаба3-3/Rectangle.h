#pragma once
#include "ShapeBase.h"

class Rectangle : public ShapeBase 
{

public: 

	Rectangle(int side_a, int side_b) {
		_side_a = side_a;
		_side_b = side_b;
	}

	virtual double GiveSquare() const override { 
		return _side_a * _side_b; 
	}

	virtual double GiveCenterGrav() const override { 
		return _side_a / 2; 
	}

	virtual double Side(int pos)  const override {
		if (pos == 1) return _side_a;
		else if (pos == 2) return _side_b;
		else throw std::exception();
	}
	//virtual double Rotate(int pos)  const = 0;
	//virtual double Move(int pos)  const = 0;

private:
	int _side_a;
	int _side_b;
};