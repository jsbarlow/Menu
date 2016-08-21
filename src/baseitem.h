//
// FILE: baseitem.h
//

#ifndef BASE_H
#define BASE_H

#include <string>

namespace abc
{
	class BaseItem
	{
	public:
		virtual std::string Name() = 0;
		virtual double Calories() = 0;
		virtual double Price() = 0;
		virtual void Print() = 0;
	};
}

#endif