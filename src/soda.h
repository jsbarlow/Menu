//
// FILE: soda.h
//

#ifndef SODA_H
#define SODA_H

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "baseitem.h"

using namespace std;

namespace abc
{
	class Soda : public BaseItem
	{
	public:
		Soda(string name, string newsize, double newcals, double newprice)
		{
			
			string othername;
			i = names.begin();
			names.push_back(name);
			size = newsize;
			cals = newcals;
			price = newprice;
			do
			{
				getline(cin, othername);
				if (othername != "0")
				{
					names.push_back(othername);
				};
			} while (othername != "0");
		}

		string BaseItem::Name()
		{
			string combine;
			list <string> ::iterator j;
			j = names.end();
			j--;
			for (i = names.begin(); i != j; ++i)
				combine += *i + ", ";
			combine += *i + " - " + size;
			return combine;
		}

		double BaseItem::Calories() { return cals; }

		double BaseItem::Price() { return price; }

		void SetName(const string& s)
		{
			names.insert(i, s);
		}

		void BaseItem::Print()
		{
			cout << Soda::Name();
			cout << " (" << cals << ") $" << price << endl;
		}

	private:
		list <string> names;
		list <string> :: iterator i;
		string size;
		double cals;
		double price;
	};
}

#endif