
#include <iostream>
#include "Square.h"
#include "IShapeinputDialog.h"

class SquareDialog : public IShapeinputDialog {
public:

	 virtual IShape* InputShape() {
		int side;
		std::cout << "Enter the side:\n";
		std::cin >> side;
		return new Square(side);
	}

};