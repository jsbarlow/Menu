//
// FILE: menuItem.h
//

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "baseitem.h"
#include "descItem.h"

using namespace std;

namespace abc
{
	class MenuItem : public BaseItem, public DescItem
	{
	public:
		MenuItem(string newname, string newdesc, double newcals, double newprice)
		{ 
			name = newname;
			desc = newdesc;
			cals = newcals;
			price = newprice;
		}

		string BaseItem::Name() { return name; }

		double BaseItem::Calories() { return cals; }

		double BaseItem::Price() { return price; }

		void BaseItem::Print()
		{
			cout << name << ": " << desc << " (" << cals << ") $" << price << endl;
		};

		string DescItem::GetDesc() { return desc; }

		void DescItem::SetDesc(const std::string& s) { desc = s; }

	private:
		string name;
		string desc;
		double cals;
		double price;
	};
}

#endif