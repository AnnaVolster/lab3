#pragma once
#include <string>

class IShape {
public:
	virtual ~IShape() = default;

	virtual double GiveSquare()  const = 0;
	virtual double GiveCenterGrav()  const = 0;

	virtual double Side(int pos)  const = 0;
	virtual std::string  Type() const = 0;
	//virtual double Rotate(int pos)  const = 0;
	//virtual double Move(int pos)  const = 0;
};