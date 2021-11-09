#pragma once

#include <iostream>

#include <iostream>
#include "Rectangle.h"
#include "IShapeinputDialog.h"


class RectangleDialog: public IShapeinputDialog {
public:

	virtual IShape* InputShape()  {
		int side_a, side_b;
		std::cout << "Enter the side A and B:\n";
		std::cin >> side_a >> side_b;
		return new Rectangle(side_a, side_b);
	}
};