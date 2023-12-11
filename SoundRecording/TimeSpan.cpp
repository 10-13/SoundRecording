#include "TimeSpan.h"

namespace Music
{
	namespace Categorization
	{
		TimeSpan::TimeSpan(size_t ms) : milliseconds_(ms) {}

		TimeSpan::TimeSpan(size_t hours, size_t minutes, size_t seconds) : milliseconds_((hours * 3600 + minutes * 60 + seconds) * 1000) {}

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
			return RawSeconds() / 60;
		}

		size_t TimeSpan::RawHours() const noexcept
		{
			return RawMinutes() / 60;
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
			size_t h = Hours(), m = Minutes(), s = Seconds();
			return std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);
		}

		void TimeSpan::ToStream(std::ostream& out) const
		{
			out << milliseconds_;
		}

		void TimeSpan::FromStream(std::istream& in)
		{
			in >> milliseconds_;
		}
	}
}

