#pragma once
#pragma once

#include "IShape.h"
#include <string>

class IShapeinputDialog {
public:
	virtual IShape* InputShape() = 0;
};