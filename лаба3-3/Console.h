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

		_menuItems[0] = MenuItem{ "Add Shape", std::bind(&Console::AddTriangleDialog, this) };
		_menuItems[1] = MenuItem{ "Show list of Shapes", std::bind(&Console::ShowListShapeDialog, this) };
		_menuItems[2] = MenuItem{ "Show the Shape", std::bind(&Console::ShowShapeDialog, this) };
		_menuItems[3] = MenuItem{ "Calculate Square of the shape ", std::bind(&Console::CalcSquareDialog, this) };
		_menuItems[4] = MenuItem{ "Calculate Center Gravity", std::bind(&Console::CalcCenterGravDialog, this) };
		_menuItems[5] = MenuItem{ "Rotate shape", std::bind(&Console::RotateShapeDialog, this) };
		_menuItems[6] = MenuItem{ "Move shape", std::bind(&Console::MoveShapeDialog, this) };
		_menuItems[7] = MenuItem{ "Compare shapes", std::bind(&Console::CompareDialog, this) };
		_menuItems[8] = MenuItem{ "Intersection shapes", std::bind(&Console::IntersectionDialog, this) };
		_menuItems[9] = MenuItem{ "Including shapes", std::bind(&Console::IncludeDialog, this) };

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
				if (action == 10) break;
				cout << endl;

				_menuItems[action].Func();

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

	~Console() = default;

private:

	void ShowMenu() {
		for (int i = 0; i < 10; ++i) {
			cout << i << " " << _menuItems[i].Massage << endl;
		}

	}

	struct MenuItem {
		string Massage;
		function<void(void)> Func;
	};

	void AddTriangleDialog() {
		_shapes[count] = ShapeDialogFactory().CreateDialog()->InputShape();
	}

	void ShowListShapeDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			for (int i = 0; i < count; ++i) {
				cout << i << "-" << _shapes[i]->Type() << endl;
			}
		}
	}


	void ShowShapeDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
		}
		int tmp1;
		cout << "Which one of figure: ";
		cin >> tmp1;
		cout << "It's a " << _shapes[tmp1]->Type() << endl;
		_shapes[tmp1]->CoordShape();
	}

	void CalcSquareDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1;
			cout << "Which one of figure: ";
			cin >> tmp1;
			cout << "Square is: ";
			if (tmp1 < count) {
				cout << _shapes[tmp1]->GiveSquare() << endl;
			}
		}
	}

	void CalcCenterGravDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1;
			cout << "Which one of figure: ";
			cin >> tmp1;
			cout << "CenterGrav x, y:" << endl;
			if (tmp1 < count) {
				_shapes[tmp1]->GiveCenterGrav();
			}
		}
	}

	void RotateShapeDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1, angle;
			cout << "Which one of figure: ";
			cin >> tmp1;
			cout << "Enter the angle to rotate: " << endl;
			cin >> angle;
			if (tmp1 < count) {
				_shapes[tmp1]->Rotate(angle, _shapes[tmp1]->CoordCenterGrav(1), _shapes[tmp1]->CoordCenterGrav(2));
			}
			cout << "The shape is rotated";
		}
	}

	void MoveShapeDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1;
			cout << "Which one of figure: ";
			cin >> tmp1;
			if (tmp1 < count) {
				_shapes[tmp1]->Move();
			}
			cout << "The shape is moved";
		}
	}


	void CompareDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1, tmp2;
			cout << "Enter two numbers of figures: ";
			cin >> tmp1 >> tmp2;
			if (tmp1 < count) {
				if ((_shapes[tmp1]->Compare(*_shapes[tmp2])) == 1)
					cout << "The square of the first figure is larger" << endl;
				else cout << "The square of the second figure is larger" << endl;
			}
		}
	}

	void IntersectionDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1, tmp2;
			cout << "Enter two numbers of figures: ";
			cin >> tmp1 >> tmp2;
			if (tmp1 < count) {
				if ((_shapes[tmp1]->Intersection(*_shapes[tmp2])) == 1)
					cout << "There is an intersection" << endl;

				else if ((_shapes[tmp1]->Intersection(*_shapes[tmp2])) == 0)
					cout << "No intersection" << endl;

			}
		}
	}

	
	void IncludeDialog() {
		if (count == 0) throw std::exception("There is no shapes!");
		else {
			int tmp1, tmp2;
			cout << "Enter two numbers of figures: ";
			cin >> tmp1 >> tmp2;
			if (tmp1 < count) {
				if ((_shapes[tmp1]->Include(*_shapes[tmp2])) == 1)
					cout << "The first figure include the second" << endl;

				else if ((_shapes[tmp1]->Include(*_shapes[tmp2])) == 0)
					cout << "Isn't  included" << endl;
			}

		}
	}
	
	MenuItem _menuItems[10];
	IShape* _shapes[100];
	
	
};
