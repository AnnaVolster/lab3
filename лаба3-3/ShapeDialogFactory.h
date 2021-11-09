#pragma once
#include "IShapeinputDialog.h"

class ShapeDialogFactory
{
public:
	IShapeinputDialog* CreateDialog();
	//IShape* CalculateDialog();
};
