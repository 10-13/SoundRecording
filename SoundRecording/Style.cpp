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
	}
}