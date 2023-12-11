#include "Style.h"
#include "StyleRegestry.h"

namespace Music
{
	namespace Styles
	{
		Style::Style(size_t index) : indexing_(index) {}

		const std::string& Style::GetName() const
		{
			return StyleRegestry::GetStyleNameByIndex(indexing_);
		}

		const std::string& Style::GetDescription() const
		{
			return StyleRegestry::GetStyleDescriptionByIndex(indexing_);
		}

		std::string Style::ToString() const
		{
			return GetName();
		}

		void Style::ToStream(std::ostream& out) const
		{
			out << GetName() << '\n' << GetDescription();
		}

		void Style::FromStream(std::istream& in)
		{
			std::string n, d;
			std::getline(in, n);
			std::getline(in, d);
			if (StyleRegestry::ConatainsStyleWithName(n) == -1)
			{
				StyleRegestry::AddUserStyle(n, d);
			}
			this->indexing_ = StyleRegestry::ConatainsStyleWithName(n);
		}
	}
}