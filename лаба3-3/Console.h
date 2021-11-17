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
		_menuItems.push_back(MenuItem{ "Calculate Center Gravity", std::bind(&Console::CalcCenterGravDialog, this) });
		_menuItems.push_back(MenuItem{ "Rotate shape", std::bind(&Console::RotateShapeDialog, this) });
		_menuItems.push_back(MenuItem{ "Move shape", std::bind(&Console::MoveShapeDialog, this) });
		_menuItems.push_back(MenuItem{ "Compare shapes", std::bind(&Console::CompareDialog, this) });
		_menuItems.push_back(MenuItem{ "Intersection shapes", std::bind(&Console::IntersectionDialog, this) });
		_menuItems.push_back(MenuItem{ "Including shapes", std::bind(&Console::IncludeDialog, this) });
		
	
	}
	int count = 0;
	void Run() {
		while (1) {
			try {

				ShowMenu();

				cout << endl;

				int action;
				cout << "Enter your choice: ";
				cin >> action;

				cout << endl;
				
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

	~Console() {

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
		_shapes.push_back(ShapeDialogFactory().CreateDialog()->InputShape());
	}

	void ShowListShapeDialog() {
		for (int i = 0; i < count; ++i) {
			cout << i << "-" << _shapes.at(i)->Type() << endl;
		}
	}


	void ShowShapeDialog() {

	}

	void CalcSquareDialog() {
		int tmp;
		cout << "Which one of figure: ";
		cin >>tmp;
		cout << "Square is: ";
		if (tmp < count) {
			cout << _shapes.at(tmp)->GiveSquare() << endl;
		}
	}

	void CalcCenterGravDialog() {
		int tmp;
		cout << "Which one of figure: ";
		cin >> tmp;
		cout << "CenterGrav x, y:" << endl;
		if (tmp < count) {
			_shapes.at(tmp)->GiveCenterGrav();
		}
	}

	void RotateShapeDialog() {
		int tmp, angle;
		cout << "Which one of figure: ";
		cin >> tmp;
		cout << "Enter the angle to rotate: " << endl;
		cin >> angle;
		if (tmp < count) {
			_shapes.at(tmp)->Rotate(angle, _shapes.at(tmp)->CoordCenterGrav(1), _shapes.at(tmp)->CoordCenterGrav(2));
		}
		cout << "The shape is rotated";
	}

	void MoveShapeDialog() {
		int tmp;
		cout << "Which one of figure: ";
		cin >> tmp;
		if (tmp < count) {
			_shapes.at(tmp)->Move();
		}
		cout << "The shape is moved";
	}


	void CompareDialog() {
		int tmp1, tmp2;
		cout << "Enter two numbers of figures: ";
		cin >> tmp1 >> tmp2;
		if (tmp1 < count) {
			if ((_shapes.at(tmp1)->Compare(*_shapes.at(tmp2)))==1)
				cout << "The square of the first figure is larger" << endl;
			else cout << "The square of the second figure is larger" << endl;
		}
	}

	void IntersectionDialog() {
		int tmp1, tmp2;
		cout << "Enter two numbers of figures: ";
		cin >> tmp1 >> tmp2;
		if (tmp1 < count) {
			if ((_shapes.at(tmp1)->Intersection(*_shapes.at(tmp2)))==1) 
				cout << "There is an intersection"<< endl;

			else if ((_shapes.at(tmp1)->Intersection(*_shapes.at(tmp2))) == 0) 
				cout << "No intersection"<< endl;
			
		}
		
	}

	
		void IncludeDialog() {
		int tmp1, tmp2;
		cout << "Enter two numbers of figures: ";
		cin >> tmp1 >> tmp2;
		if (tmp1 < count) {
			if ((_shapes.at(tmp1)->Include(*_shapes.at(tmp2))) == 1)
				cout << "The first figure include the second" << endl;

			else if ((_shapes.at(tmp1)->Include(*_shapes.at(tmp2))) == 0)
				cout << "Isn't  included" << endl;
		}

	}
	
	vector<MenuItem> _menuItems;
	vector<IShape*> _shapes;
	
	
};
