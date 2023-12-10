#pragma once
#include <vector>
#include <string>
#include <stdexcept>

namespace Music
{
	namespace Styles
	{
		struct StyleTemplate
		{
			std::string Name;
			std::string Description;
		};

		const std::vector<StyleTemplate> DefaultStyleTemplates{
				{"Pop",""},
				{"Rock",""},
				{"Rap",""} };

		

		static class StyleRegestry
		{
		private:
			static std::vector<StyleTemplate> user_styles_;

			static const StyleTemplate& GetByIndex(size_t index);

			static bool IsInBounds(size_t index);

		public:		
			static const std::string& GetStyleNameByIndex(size_t index);

			static const std::string& GetStyleDescriptionByIndex(size_t index);

			static void AddUserStyle(std::string Name, std::string Description);

			static std::vector<StyleTemplate>& UserStylesList();

			static size_t ConatainsStyleWithName(std::string Name);
		};
	}
}


