#pragma once
#include "ShapeBase.h"
#include <iostream>
#include <cmath>
using namespace std;

class Square : public ShapeBase 
{

public:

	Square()  {
		for (int i = 0; i < 4; i++) {
			cout << "Enter vertex coordinate " << i + 1 << ": ";
			cin >> arc[i].x;
			cin >> arc[i].y;
			cout << endl;
		}
		
		_side = sqrt((arc[1].x - arc[0].x)*(arc[1].x - arc[0].x)+ (arc[1].y - arc[0].y)*(arc[1].y - arc[0].y));
		if (_side != (sqrt((arc[2].x - arc[1].x) * (arc[2].x - arc[1].x) + (arc[2].y - arc[1].y) * (arc[2].y - arc[1].y)))
			&&
			_side != (sqrt((arc[3].x - arc[2].x) * (arc[3].x - arc[2].x) + (arc[3].y - arc[2].y) * (arc[3].y - arc[2].y)))
			&&
			_side != (sqrt((arc[0].x - arc[3].x) * (arc[0].x - arc[3].x) + (arc[0].y - arc[3].y) * (arc[0].y - arc[3].y))))
		{
			throw std::exception("Isn't a square!");
		}
		if ((acos(((arc[1].x - arc[0].x * (arc[2].x - arc[1].x)) + (arc[1].y - arc[0].y * (arc[2].y - arc[1].y))) /
			(sqrt((arc[1].x - arc[0].x) * (arc[1].x - arc[0].x) + (arc[1].y - arc[0].y) * (arc[1].y - arc[0].y)) * sqrt((arc[2].x - arc[1].x) * (arc[2].x - arc[1].x) + (arc[2].y - arc[1].y) * (arc[2].y - arc[1].y)))) != 0) && acos(((arc[3].x - arc[2].x * (arc[0].x - arc[3].x)) + (arc[3].y - arc[2].y * (arc[0].y - arc[3].y))) /
			(sqrt((arc[3].x - arc[2].x) * (arc[3].x - arc[2].x) + ((arc[3].y - arc[2].y) * ((arc[3].y - arc[2].y)) * sqrt((arc[0].x - arc[3].x) * (arc[0].x - arc[3].x) + (arc[0].y - arc[3].y) * arc[0].y - arc[3].y)))) != 0)) {

			throw std::exception("Isn't a square!");
		}
		_CenterGrav_x = arc[0].x + _side / 2;
		_CenterGrav_y = arc[0].y - _side / 2;
	}

	virtual double GiveSquare() const { return _side * _side; }

	
	virtual double CoordCenterGrav(int pos) const { 
		if (pos == 1) return _CenterGrav_x;
		else if (pos == 2) return _CenterGrav_y;
		else throw std::exception();
	}
	
	virtual double Side(int pos) const { return _side; }
	
	virtual std::string Type() const {
		std::string typeShape = "Square";
		return typeShape;
	}

	~Square()
	{
		if (&arc != nullptr)
			delete[] arc;
	}

private:
	double _side;
	double _CenterGrav_x;
	double _CenterGrav_y;
};




