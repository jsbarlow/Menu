//
// Author: Joseph Barlow
// FILE: menus4.cpp
//

#include <iostream>
#include <memory>
#include "restaurant.h"

using namespace std;
using namespace abc;

int main()
{
	int leave;
	string name, desc;
	leave = 1;
	Restaurant ri;
	ri.printMenu();
	cout << "\nNow enter a name of a menu item or bar that you would like to change the description of." << endl;
	getline(cin, name);
	cout << "\nNow enter the new description, or new bar item." << endl;
	getline(cin, desc);
	ri.setDescription(name, desc);
	system("PAUSE");
}