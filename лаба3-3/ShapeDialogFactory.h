#pragma once
#include "IShapeinputDialog.h"
#include "string"

class ShapeDialogFactory
{
public:
	IShapeinputDialog* CreateDialog();
	
};
