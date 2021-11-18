#pragma once

#include <iostream>

#include <iostream>
#include "Rectangle.h"
#include "IShapeinputDialog.h"


class RectangleDialog: public IShapeinputDialog {
public:

	virtual IShape* InputShape()  {
		return new Rectangle();
	}
	
};