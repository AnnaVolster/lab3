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


	void Run() {
		while (true) {
			try {

				ShowMenu();

				int action;
				cin >> action;

				_menuItems.at(action).Func();
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
		//_shapes.push_back(ShapeDialogFactory().CreateDialog()->InputShape());
		_figures.push_back(_figure);
		_figures.at(0).shapes.push_back(ShapeDialogFactory().CreateDialog()->InputShape());
	}
	void ShowListShapeDialog() {
		for (int i = 0; i < _menuItems.size(); ++i) {
			//cout << _shapes.at(i) << endl;
		}
	}


	void ShowShapeDialog() {

	}

	void CalcSquareDialog() {
		cout << "Which one of figure ";
		//cout << _shapes[0]->GiveSquare() << endl;
	}

	void CalcCenterGravDialog() {

	}

	void RotateShapeDialog() {

	}

	void MoveShapeDialog() {
	}

	vector<MenuItem> _menuItems;
	//vector<IShape*> _shapes;
	
	struct Figure {
		vector<IShape*> shapes;
		char figureType;
		int side_a, side_b;
	};

	vector<Figure> _figures;
	Figure _figure;
};