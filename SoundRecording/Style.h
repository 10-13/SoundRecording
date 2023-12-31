#pragma once
#include "TextableObject.h"
#include "Serializeble.h"
#include <string>
#include <vector>

namespace Music
{
	namespace Styles
	{
		class Style : public Music::Categorization::TextableObject, public Music::Serialization::Serializeble
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

			void ToStream(std::ostream& out) const override;
			void FromStream(std::istream& in) override;

			size_t Hash() const;

			bool operator==(const Style& b) const;

			std::string ToString() const;
		};

		enum class DefaultStyles
		{
			msPop = 0,
			msRock = 1,
			msRap = 2,
			msNoise = 3,
			msJungle = 4,
			msGrunge = 5,
			msElectronic = 6,
			msPhonk = 7,
			msRave = 8,
		};
	}
}

