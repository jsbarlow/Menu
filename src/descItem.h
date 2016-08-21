//
// FILE: descItem.h
//

#ifndef DESC_H
#define DESC_H

#include <string>

namespace abc
{
	class DescItem
	{
	public:
		virtual std::string GetDesc() = 0;
		virtual void SetDesc(const std::string& s) = 0;
	};
}

#endif