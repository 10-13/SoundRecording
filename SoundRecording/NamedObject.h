#pragma once
#include "TextableObject.h"
#include "BasedComparer.h"
#include <string>
#include <vector>

namespace Music
{
	namespace Categorization
	{
		class NamedObject : public TextableObject
		{
		protected:
			std::string name_;
			std::string description_;
			std::vector<std::string> authors_;

			NamedObject(std::string name, std::string description, std::vector<std::string> authors)
				: name_(name),
				description_(description_),
				authors_(authors_) {}

		public:
			std::string ToString() const override
			{
				std::string r = name_ + " -";
				for (size_t i = 0; i < authors_.size(); i++)
				{
					r += (i == 0 ? " " : ", ") + authors_[i];
				}
				return r;
			}

			friend class NameBasedComparere;
			friend class DescriptionBasedComparere;
			friend class AuthorsBasedComparere;
		};

		class NameBasedComparere : public BasedComparer<NamedObject, std::string>
		{
		protected:
			FunctionInputType GetInput(ComparingPtrType a) const
			{
				return a->name_;
			}
		};

		class DescriptionBasedComparere : public BasedComparer<NamedObject, std::string>
		{
		protected:
			FunctionInputType GetInput(ComparingPtrType a) const
			{
				return a->description_;
			}
		};

		class AuthorsBasedComparere : public BasedComparer<NamedObject, std::vector<std::string>>
		{
		protected:
			FunctionInputType GetInput(ComparingPtrType a) const
			{
				return a->authors_;
			}
		};
	}
}