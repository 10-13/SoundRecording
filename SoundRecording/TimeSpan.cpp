#include "TimeSpan.h"

namespace Music
{
	namespace Categorization
	{
		TimeSpan::TimeSpan(size_t ms) : milliseconds_(ms) {}

		size_t TimeSpan::RawMilliseconds() const noexcept
		{
			return milliseconds_;
		}

		size_t TimeSpan::RawSeconds() const noexcept
		{
			return milliseconds_ / 1000;
		}

		size_t TimeSpan::RawMinutes() const noexcept
		{
			return Seconds() / 60;
		}

		size_t TimeSpan::RawHours() const noexcept
		{
			return Minutes() / 60;
		}

		size_t TimeSpan::Milliseconds() const noexcept
		{
			return RawMilliseconds() % 1000;
		}

		size_t TimeSpan::Seconds() const noexcept
		{
			return RawSeconds() % 60;
		}

		size_t TimeSpan::Minutes() const noexcept
		{
			return RawMinutes() % 60;
		}

		size_t TimeSpan::Hours() const noexcept
		{
			return RawHours();
		}

		TimeSpan TimeSpan::operator+(const TimeSpan& b) const
		{
			return TimeSpan(milliseconds_ + b.milliseconds_);
		}

		TimeSpan TimeSpan::operator-(const TimeSpan& b) const
		{
			return TimeSpan(milliseconds_ - b.milliseconds_);
		}

		TimeSpan TimeSpan::operator*(size_t b) const
		{
			return TimeSpan(milliseconds_ * b);
		}

		TimeSpan TimeSpan::operator/(size_t b) const
		{
			return TimeSpan(milliseconds_ * b);
		}

		std::string TimeSpan::ToString() const
		{
			return std::to_string(Hours()) + ":" + std::to_string(Minutes()) + ":" + std::to_string(Seconds());
		}
	}
}

