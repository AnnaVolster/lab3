
#include <iostream>
#include "Square.h"
#include "IShapeinputDialog.h"


class SquareDialog : public IShapeinputDialog {
public:
	
	
	 virtual IShape* InputShape() {
		return new Square();
	}
	 
};