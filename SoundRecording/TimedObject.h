#pragma once
#include "TimeSpan.h"
#include "BasedComparer.h"

namespace Music
{
	namespace Categorization
	{
		class TimedObject : public TextableObject
		{
		protected:
			TimeSpan length_;
			TimedObject(size_t millisecs) : length_(millisecs) {}
			TimedObject() : length_(0) {};

		public:
			std::string ToString() const
			{
				return length_.ToString();
			}

			TimeSpan Length()
			{
				return length_;
			}

			friend class TimeBasedComparer;
		};

		class TimeBasedComparer : public BasedComparer<TimedObject, TimeSpan>
		{
		protected:
			FunctionInputType GetInput(ComparingPtrType ptr) const
			{
				return ptr->length_;
			}
		};
	}
}