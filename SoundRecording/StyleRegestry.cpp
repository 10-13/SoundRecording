#include "StyleRegestry.h"

namespace Music
{

	namespace Styles
	{
		std::vector<StyleTemplate> StyleRegestry::user_styles_;

		const StyleTemplate& StyleRegestry::GetByIndex(size_t index)
		{
			if (index < DefaultStyleTemplates.size())
			{
				return DefaultStyleTemplates[index];
			}
			return user_styles_[index - DefaultStyleTemplates.size()];
		}

		bool StyleRegestry::IsInBounds(size_t index)
		{
			return index < DefaultStyleTemplates.size() + user_styles_.size();
		}

		const std::string& StyleRegestry::GetStyleNameByIndex(size_t index)
		{
			if (!IsInBounds(index))
			{
				throw std::out_of_range("Trying access incorect style index");
			}
			return GetByIndex(index).Name;
		}

		const std::string& StyleRegestry::GetStyleDescriptionByIndex(size_t index)
		{
			if (!IsInBounds(index))
			{
				throw std::out_of_range("Trying access incorect style index");
			}
			return GetByIndex(index).Description;
		}

		void StyleRegestry::AddUserStyle(std::string Name, std::string Description)
		{
			user_styles_.emplace_back(StyleTemplate{ Name, Description });
		}

		std::vector<StyleTemplate>& StyleRegestry::UserStylesList()
		{
			return user_styles_;
		}

		size_t StyleRegestry::ConatainsStyleWithName(std::string Name)
		{
			for (size_t index = 0; index < user_styles_.size() + DefaultStyleTemplates.size(); index++)
			{
				if (GetByIndex(index).Name == Name)
				{
					return index;
				}
			}
			return -1;
		}
	}
}