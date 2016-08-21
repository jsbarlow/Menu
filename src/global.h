//
// FILE: global.h
//

#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <list>
#include <memory>
#include "baseitem.h"
#include "menuItem.h"
#include "bar.h"
#include "soda.h"

using namespace std;

namespace abc
{
	unique_ptr<BaseItem> CreateMenu(string name, string desc, double cals, double price)
	{
		unique_ptr<BaseItem> mi(new MenuItem(name, desc, cals, price));
		return mi;
	}

	unique_ptr<BaseItem> CreateBar(string name, string part, double cals, double price)
	{
		unique_ptr<BaseItem> bi(new Bar(name, part, cals, price));
		return bi;
	}

	unique_ptr<BaseItem> CreateSoda(string name, string size, double cals, double price)
	{
		unique_ptr<BaseItem> si(new Soda(name, size, cals, price));
		return si;
	}
}

#endif