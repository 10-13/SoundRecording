#pragma once
#include "Composition.h"
#include <unordered_set>

namespace Music
{
	class Disk : public Music::Categorization::NamedObject, public Music::Serialization::Serializeble
	{
	private:
		struct StyleHash
		{
			size_t operator()(const Style& obj) const noexcept;
		};
	public:
		std::vector<Composition> Compositions;

		Disk() = default;

		void ToStream(std::ostream& out) const override;
		void FromStream(std::istream& in) override;

		std::vector<Style> Styles() const;

		TimeSpan Length() const;
	};
}

