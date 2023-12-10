#pragma once
#include "IPlayble.h"
#include "Style.h"
#include "NamedObject.h"
#include "TimeSpan.h"
#include "TimedObject.h"
#include <string>
#include <vector>

using namespace Music::Styles;
using namespace Music::PlayerCore;
using namespace Music::Categorization;

namespace Music
{
	class Composition : public IPlayable, public NamedObject, public TimedObject, public TextableObject
	{
	private:
		std::vector<Style> styles_;
	public:
		std::string ToString() const
		{
			return NamedObject::ToString() + "(" + TimedObject::ToString() + ")";
		}
	};
}

