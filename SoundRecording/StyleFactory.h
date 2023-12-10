#pragma once
#include "Style.h"
#include "StyleRegestry.h"

namespace Music
{
	namespace Styles
	{
		namespace Factory
		{
			Style CreateUserStyle(std::string Name, std::string Description = "")
			{
				size_t style = StyleRegestry::ConatainsStyleWithName(Name);
				if (style == -1)
				{
					StyleRegestry::AddUserStyle(Name, Description);
				}
				return Style(StyleRegestry::ConatainsStyleWithName(Name));
			}

			Style CreateDefaultStyle(Music::Styles::DefaultStyles style)
			{
				return Style(static_cast<size_t>(style));
			}
		}
	}
}