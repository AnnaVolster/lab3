#pragma once
#define _USE_MATH_DEFINES

#include "IShape.h"

const double M_PI = 3.14;

using namespace std;

class ShapeBase: public IShape {
public:

	virtual double GiveSquare() const { return Side(0) * Side(1); }

	virtual void CoordShape() const override {
		for (int i = 0; i < 4; i++) {
			cout << arc[i].x << " " << arc[i].y << endl;
		}
	}

	virtual void GiveCenterGrav() const {
		cout << CoordCenterGrav(1) << ",";
		cout << CoordCenterGrav(2);
	}

void Rotate(int angle, double xc, double yc) const {

//фигура вначале смещается в центр координат.

	double a = angle * M_PI / 180; //переводим в радианы

	double X, Y; //повернутые коор-ты углов фигуры

// потом возвращаем повернутую фигуру в исх.центр (xc,yc):

	X = (arc[0].x - xc) * cos(a) - (arc[0].y - yc) * sin(a);
	Y = (arc[0].x - xc) * sin(a) + (arc[0].y - yc) * cos(a);

	cout << "x1=" << X + xc << endl;
	cout << "y1=" << Y + yc << endl;

	X = (arc[1].x - xc) * cos(a) - (arc[1].y - yc) * sin(a);
	Y = (arc[1].x - xc) * sin(a) + (arc[1].y - yc) * cos(a);

	cout << "x2=" << X + xc << endl;
	cout << "y2=" << Y + yc << endl;

	X = (arc[2].x - xc) * cos(a) - (arc[2].y - yc) * sin(a);
	Y = (arc[2].x - xc) * sin(a) + (arc[2].y - yc) * cos(a);

	cout << "x3=" << X + xc << endl;
	cout << "y3=" << Y + yc << endl;

	X = (arc[3].x - xc) * cos(a) - (arc[3].y - yc) * sin(a);
	Y = (arc[3].x - xc) * sin(a) + (arc[3].y - yc) * cos(a);

	cout << "x4=" << X + xc << endl;
	cout << "y4=" << Y + yc << endl;

}

	virtual void Move()  const {
		double Cx, Cy;
		cout << "Enter the displacement factor along X and Y: " << std::endl;
		cin >> Cx >> Cy;
		cout << "New Coord of figure: " << endl;
		for (int i = 0; i < 4; i++) {
			cout << arc[i].x + Cx << " ";
			cout << arc[i].y + Cy << endl;
		}
	}

	virtual double getMaxCoord(double v1, double v2, double v3, double v4) const { //найти макс. координату на оси X или Y

		double m;

		m = (v1 >= v2) ? v1 : v2;

		m = (m >= v3) ? m : v3;

		m = (m >= v4) ? m : v4;

		return m;

	}

	virtual double getMinCoord(double v1, double v2, double v3, double v4) const { //найти мин. координату на оси X или Y

		double m;

		m = (v1 <= v2) ? v1 : v2;

		m = (m <= v3) ? m : v3;

		m = (m <= v4) ? m : v4;

		return m;

	}

	bool Compare(IShape& const A) const {
		if (GiveSquare() > A.GiveSquare())
			return true;
		else return false;
	}

	bool Intersection(IShape& const A) const {

		if ((arc[0].x <= A.arc[3].x) && (A.arc[0].x <= arc[3].x) && (arc[0].y <= A.arc[1].y) && (A.arc[0].y <= arc[1].y) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual bool Include(IShape& const A) const {

		double minXS, maxXS, minXR, maxXR;

		double minYS, maxYS, minYR, maxYR;

		bool res = false;

		minXS = getMinCoord(arc[0].x, arc[1].x, arc[2].x, arc[3].x);

		maxXS = getMaxCoord(arc[0].x, arc[1].x, arc[2].x, arc[3].x);

		minYS = getMinCoord(arc[0].y, arc[1].y, arc[2].y, arc[3].y);

		maxYS = getMaxCoord(arc[0].y, arc[1].y, arc[2].y, arc[3].y);

		minXR = getMinCoord(A.arc[0].x, A.arc[1].x, A.arc[2].x, A.arc[3].x);

		maxXR = getMaxCoord(A.arc[0].x, A.arc[1].x, A.arc[2].x, A.arc[3].x);

		minYR = getMinCoord(A.arc[0].y, A.arc[1].y, A.arc[2].y, A.arc[3].y);

		maxYR = getMaxCoord(A.arc[0].y, A.arc[1].y, A.arc[2].y, A.arc[3].y);

		if ((minXR >= minXS) && (minYR >= minYS) &&

			(maxXR <= maxXS) && (maxYR <= maxYS)

			)

			res = true;

		else

			if ((minXS >= minXR) && (minYS >= minYR) &&

				(maxXS <= maxXR) && (maxYS <= maxYR)

				)

				res = true;

		return res;
	}
	
};
