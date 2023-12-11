#pragma once
#include <iostream>

namespace Music
{
	namespace Serialization
	{
		class Serealizeble
		{
		public:
			virtual void ToStream(std::ostream& out) const = 0;
			virtual void FromStream(std::istream& in) = 0;

			friend std::ostream& operator<<(std::ostream& out, const Serealizeble* const obj);
			friend std::istream& operator>>(std::istream& in, Serealizeble* const obj);
		};
	}
}



