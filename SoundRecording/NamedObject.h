#pragma once
#include "TextableObject.h"
#include "BasedComparer.h"
#include "Serializeble.h"
#include <string>
#include <vector>

namespace Music
{
	namespace Categorization
	{
		class NamedObject : public TextableObject, public Music::Serialization::Serializeble
		{
		protected:
			std::string name_;
			std::string description_;
			std::vector<std::string> authors_;

			NamedObject(std::string name, std::string description, std::vector<std::string> authors);
			NamedObject() {};

		public:
			std::string Name() const;
			std::string Description() const;
			std::vector<std::string> Authors() const;

			void ToStream(std::ostream& out) const override;
			void FromStream(std::istream& in) override;

			std::string ToString() const override;

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