#include <iostream>
#include "StyleFactory.h"

using namespace Music::Styles;
using namespace Music::Styles::Factory;

int main()
{
	std::cout << CreateDefaultStyle(DefaultStyles::msRap).ToString();
}