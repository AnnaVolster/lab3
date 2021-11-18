#pragma once
#include "ShapeBase.h"
#include <string>

using namespace std;

class Rectangle : public ShapeBase
{

public:

	Rectangle() {
		for (int i = 0; i < 4; i++) {
			cout << "Enter vertex coordinate " << i + 1 << ": ";
			cin >> arc[i].x;
			cin >> arc[i].y;
			cout << endl;
		}

		hight = sqrt((arc[1].x - arc[0].x) * (arc[1].x - arc[0].x) + (arc[1].y - arc[0].y) * (arc[1].y - arc[0].y));
		width = sqrt((arc[2].x - arc[1].x) * (arc[2].x - arc[1].x) + (arc[2].y - arc[1].y) * (arc[2].y - arc[1].y));
		_CenterGrav_x = arc[0].x + width / 2;
		_CenterGrav_y = arc[0].y - hight / 2;
	}


	virtual double GiveSquare() const  {
		return hight * width;
	}
	
	virtual double CoordCenterGrav(int pos) const {
		if (pos == 1) return _CenterGrav_x;
		else if (pos == 2) return _CenterGrav_y;
		else throw std::exception();
	}

	virtual double Side(int pos)  const {
		if (pos == 1) return hight;
		else if (pos == 2) return width;
		else throw std::exception();
	}

	virtual std::string Type() const {
		std::string typeShape = "Rectangle";
		return typeShape;
	}
	
  ~Rectangle()
	{
	  if (&arc!=nullptr)
		delete[] arc;
	}

private:
	double hight;
	double width;
	double _CenterGrav_x;
	double _CenterGrav_y;
};