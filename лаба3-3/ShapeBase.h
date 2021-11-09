#pragma once

#include "IShape.h"

class ShapeBase: public IShape
{
	virtual double GiveSquare() const { return Side(0) * Side(1); }

	virtual double GiveCenterGrav() const { return Side(0)/2 ; }
};
