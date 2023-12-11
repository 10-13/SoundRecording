#pragma once
#include "IPlayble.h"
#include "Style.h"
#include "NamedObject.h"
#include "TimeSpan.h"
#include "TimedObject.h"
#include "Serializeble.h"
#include <string>
#include <vector>

using namespace Music::Styles;
using namespace Music::PlayerCore;
using namespace Music::Categorization;
using namespace Music::Serialization;

namespace Music
{
	class Composition : public IPlayable, public NamedObject, public TimedObject, public TextableObject, public Serealizeble
	{
	private:
		std::vector<Style> styles_;
	public:
		Composition() {};

		void ToStream(std::ostream& out) const override;
		void FromStream(std::istream& in) override;

		std::vector<Style> Styles();

		std::string ToString() const;

		friend class CompositionBuilder;
	};
}

