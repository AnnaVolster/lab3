#include "ShapeDialogFactory.h"
#include <stdexcept>
#include "SquareDialog.h"
#include "RectangleDialog.h"
#include "Rectangle.h"
#include "Square.h"


IShapeinputDialog* ShapeDialogFactory::CreateDialog() {
	int shapeType = 0;

	std::cout << "Add Shape:\n 1 - Square;\n 2 - Rectangle.\n";

	std::cin >> shapeType;
	
	switch (shapeType) {

	case 1:
		return new SquareDialog();
	case 2:
		return new RectangleDialog();

	default: throw std::exception();
	}
}
/*

IShape* ShapeDialogFactory::CalculateDialog() {
	int actType = 0;

	std::cout << "Calculate:\n 1 - Square;\n 2 - Center Gravity.\n";

	std::cin >> actType;

	switch (actType) {

	case 1:
		return new SquareDialog();
	case 2:
		return new RectangleDialog();

	default: throw std::exception();
	}

}
*/