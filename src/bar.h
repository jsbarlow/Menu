//
// FILE: bar.h
//

#ifndef BAR_H
#define BAR_H

#include <iostream>
#include <string>
#include <list>
#include "menuItem.h"
#include "descItem.h"

using namespace std;

namespace abc
{
	class Bar : public BaseItem, public DescItem
	{
	public:
		Bar(string newname, string part, double newcals, double newprice)
		{
			string newpart;
			name = newname;
			i = parts.begin();
			parts.push_back(part);
			cals = newcals;
			price = newprice;
			do
			{
				getline(cin, newpart);
				if (newpart != "0")
					parts.push_back(newpart);
			} while (newpart != "0");
		}

		string BaseItem::Name() { return name; }

		string DescItem::GetDesc()
		{
			string combine;
			list <string> :: iterator j;
			j = parts.end();
			j--;
			for (i = parts.begin(); i != j; ++i)
				combine += *i + ", ";
			combine += *i;
			return combine;
		}

		double BaseItem::Calories() { return cals; }

		double BaseItem::Price() { return price; }

		void DescItem::SetDesc(const string& s)
		{
			parts.insert(i, s);
		}

		void BaseItem::Print()
		{
			cout << name << ": " << " (" << cals << ") $" << price << endl;
			cout << "Parts: " << Bar::GetDesc() << '.' << endl;
		}

	private:
		string name;
		list <string> parts;
		list <string> :: iterator i;
		double cals;
		double price;
	};
}

#endif