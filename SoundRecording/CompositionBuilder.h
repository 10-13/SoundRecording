#pragma once
#include "Composition.h"

namespace Music
{
	class CompositionBuilder
	{
	private:
		Composition comp_;

	public:
		CompositionBuilder() = default;

		CompositionBuilder& SetLength(size_t Hours, size_t Minutes, size_t Seconds)
		{
			comp_.length_ = TimeSpan(Hours, Minutes, Seconds);
			return *this;
		}

		CompositionBuilder& SetName(std::string Name)
		{
			comp_.name_ = Name;
			return *this;
		}

		CompositionBuilder& SetDescription(std::string Description)
		{
			comp_.description_ = Description;
			return *this;
		}

		CompositionBuilder& AddAuthor(std::string Author)
		{
			comp_.authors_.push_back(Author);
			return *this;
		}

		CompositionBuilder& AddStyle(Style style)
		{
			comp_.styles_.push_back(style);
			return *this;
		}

		Composition Result()
		{
			return comp_;
		}
	};
}

