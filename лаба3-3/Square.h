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
		delete[] arc;
	}

private:
	double _side;
	double _CenterGrav_x;
	double _CenterGrav_y;
};




