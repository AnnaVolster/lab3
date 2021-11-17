#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include "ShapeBase.h"
#include "Rectangle.h"
#include "Square.h"
#include "IShape.h"
#include "ShapeDialogFactory.h"
#include "IShapeinputDialog.h"


using namespace std;

class Console {

public:

	Console() {
		_menuItems.push_back(MenuItem{ "Add Shape", std::bind(&Console::AddTriangleDialog, this) });
		_menuItems.push_back(MenuItem{ "Show list of Shapes", std::bind(&Console::ShowListShapeDialog, this) });
		_menuItems.push_back(MenuItem{ "Show the Shape", std::bind(&Console::ShowShapeDialog, this) }); 
		_menuItems.push_back(MenuItem{ "Calculate Square of the shape ", std::bind(&Console::CalcSquareDialog, this) });
		_menuItems.push_back(MenuItem{ "Calculate Center Gravity", std::bind(&Console::CalcSquareDialog, this) });
		_menuItems.push_back(MenuItem{ "Rotate shape", std::bind(&Console::CalcSquareDialog, this) });
		_menuItems.push_back(MenuItem{ "Move shape", std::bind(&Console::CalcSquareDialog, this) });

	
	}
	int count = 0;
	void Run() {
		while (1) {
			try {

				ShowMenu();

				int action;
				cin >> action;

				_menuItems.at(action).Func();

				if (action == 0) count++;
				
			}

			catch (const exception& ex) {
				cout << ex.what() << endl;
				break;
			}
			cout << "\n";
			cout << "\n";
		}
		
	}

private:

	void ShowMenu() {
		for (int i = 0; i < _menuItems.size(); ++i) {
			cout <<i <<" "<< _menuItems[i].Massage<<endl;
		}

	}

	struct MenuItem {
		string Massage;
		function<void(void)> Func;
	};

	void AddTriangleDialog() {
		//_figures.push_back(_figure);
	_shapes.push_back(ShapeDialogFactory().CreateDialog()->InputShape());
		//_figures.at(count).shapes.push_back(ShapeDialogFactory().CreateDialog()->InputShape());
		//_figures.at(count).figureType = "Square";
		//_figures.at(count).figureType->push_back(ShapeDialogFactory().CreateDialog()->Type());
		//strcpy(_figures.at(count).figureType, ShapeDialogFactory().CreateDialog()->Type());
		//_figures.figureType.at(count).push_back(ShapeDialogFactory().CreateDialog()->Type);
		//_figures.at(count).figureType = 'S';
	}

	void ShowListShapeDialog() {
		for (int i = 0; i < count; ++i) {
		//cout << _figures.at(i).figureType << endl;
		//cout << "Shape" << endl;
			cout << i << _shapes.at(i)->Type() << endl;
		}
	}


	void ShowShapeDialog() {

	}

	void CalcSquareDialog() {
		int tmp;
		cout << "Which one of figure: ";
		cin >>tmp;
		cout << "Square is" << endl;
		if (tmp < count) {
			cout << _shapes.at(tmp)->GiveSquare() << endl;
			//cout << _figures.at(tmp).shapes.at(0)->GiveSquare() << endl;
		}
	}

	void CalcCenterGravDialog() {

	}

	void RotateShapeDialog() {

	}

	void MoveShapeDialog() {
	}

	vector<MenuItem> _menuItems;
	vector<IShape*> _shapes;
	/*
	
	struct Figure {
		vector<IShape*> shapes;
		std::string figureType;
		int side_a, side_b;
	};

	vector<Figure> _figures;
	Figure _figure;
	*/
};