#pragma once
#include "TextableObject.h"
#include "Serializeble.h"
#include <string>

namespace Music
{
	namespace Categorization
	{
		class TimeSpan : public TextableObject, public Music::Serialization::Serealizeble
		{
		private:
			size_t milliseconds_;
		public:
			TimeSpan(size_t ms);
			TimeSpan(size_t hours, size_t minutes, size_t seconds);

			TimeSpan(const TimeSpan& other) = default;
			TimeSpan(TimeSpan&& other) = default;

			TimeSpan& operator=(const TimeSpan& other) = default;
			TimeSpan& operator=(TimeSpan&& other) = default;

			size_t Milliseconds() const noexcept;
			size_t Seconds() const noexcept;
			size_t Minutes() const noexcept;
			size_t Hours() const noexcept;

			size_t RawMilliseconds() const noexcept;
			size_t RawSeconds() const noexcept;
			size_t RawMinutes() const noexcept;
			size_t RawHours() const noexcept;

			TimeSpan operator+(const TimeSpan& b) const;
			TimeSpan operator-(const TimeSpan& b) const;
			TimeSpan operator*(size_t b) const;
			TimeSpan operator/(size_t b) const;

			void ToStream(std::ostream& out) const;
			void FromStream(std::istream& in);

			std::string ToString() const;
		};
	}
}

