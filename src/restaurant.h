//
// FILE: restaurant.h
//

#ifndef REST_H
#define REST_H

#include <iostream>
#include <string>
#include "baseitem.h"
#include "descitem.h"
#include "global.h"

namespace abc
{
	class Restaurant
	{
	public:
		Restaurant()
		{
			char meit, saba, soba;
			string name, desc, part, size;
			double cals, price;
			i = menu.begin();
			meit = 0;
			saba = 0;
			soba = 0;

			// Menu Item Loop
			cout << "Create three menu items." << endl;
			while (meit < 3)
			{
				cout << "What is the name of the menu item?" << endl;
				getline(cin, name);
				cout << "What is its description?" << endl;
				getline(cin, desc);
				cout << "How many calories does it contain?" << endl;
				cin >> cals;
				cout << "What is its price?" << endl;
				cin >> price;
				cin.ignore();
				menu.push_back(CreateMenu(name, desc, cals, price));
				meit++;
			}

			// Bar Item Loop
			cout << "\nCreate three bars." << endl;
			while (saba < 3)
			{
				cout << "What is the name of the bar?" << endl;
				getline(cin, name);
				cout << "How many calories does it contain?" << endl;
				cin >> cals;
				cout << "What is bar's price?" << endl;
				cin >> price;
				cin.ignore();
				cout << "What items does it contain? Name them one at a time." << endl;
				cout << "Enter '0' when finished." << endl;
				getline(cin, part);
				menu.push_back(CreateBar(name, part, cals, price));
				saba++;
			}

			// Soda Item Loop
			cout << "\nCreate three soda sizes." << endl;
			while (soba < 3)
			{
				cout << "What is the size of the drinks?" << endl;
				getline(cin, size);
				cout << "How many calories do they contain?" << endl;
				cin >> cals;
				cout << "What are their prices?" << endl;
				cin >> price;
				cin.ignore();
				cout << "What drinks belong to this list? Name them one at a time." << endl;
				cout << "Enter '0' when finished." << endl;
				getline(cin, name);
				menu.push_back(CreateSoda(name, size, cals, price));
				soba++;
			} 
		}

		void printMenu()
		{
			cout << "\nHere is the menu: " << endl;
			for (i = menu.begin(); i != menu.end(); ++i)
			{
				(*i)->Print();
				cout << "--------------------" << endl;
			}
		}

		void setDescription(string nm, string desc)
		{
			for (i = menu.begin(); i != menu.end(); i++)
			{
				if ((*i)->Name() == nm)
				{
					BaseItem* temp(i->get());
					DescItem* descPtr = dynamic_cast<DescItem*>(temp);
					descPtr->SetDesc(desc);
					cout << "\nHere is the new, revised menu: " << endl;
					Restaurant::printMenu();
					return;
				}
			}
			cout << "The named item could not be found." << endl;
		}

	private:
		list<unique_ptr<BaseItem>> menu;
		list<unique_ptr<BaseItem>>::iterator i;
		unique_ptr<Bar> tempbar;
	};
}

#endif