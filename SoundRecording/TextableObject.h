#pragma once
#include <string>

namespace Music
{
	namespace Categorization
	{
		class TextableObject
		{
		public:
			virtual std::string ToString() const = 0;
		};
	}
}