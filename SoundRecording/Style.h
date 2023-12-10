#pragma once
#include "TextableObject.h"
#include <string>
#include <vector>

namespace Music
{
	namespace Styles
	{
		class Style : public Music::Categorization::TextableObject
		{
		private:
			size_t indexing_;
		public:
			const std::string& GetName() const;

			const std::string& GetDescription() const;

			Style(size_t index);

			Style(const Style& other) = default;
			Style(Style&& other) = default;
			Style& operator=(const Style& other) = default;
			Style& operator=(Style&& other) = default;

			~Style() = default;

			std::string ToString() const;
		};

		enum class DefaultStyles
		{
			msPop = 0,
			msRock = 1,
			msRap = 2,
		};
	}
}

