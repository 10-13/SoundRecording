#include "Serializeble.h"

namespace Music
{
	namespace Serialization
	{
		std::ostream& operator<<(std::ostream& out, const Serealizeble* const obj)
		{
			obj->ToStream(out);
			return out;
		}
		
		std::istream& operator>>(std::istream& in, Serealizeble* const obj)
		{
			obj->FromStream(in);
			return in;
		}
	}
}