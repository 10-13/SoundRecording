#include <iostream>
#include <sstream>
#include "Composition.h"
#include "StyleFactory.h"
#include "CompositionBuilder.h"

using namespace Music;
using namespace Music::Categorization;
using namespace Music::PlayerCore;
using namespace Music::Serialization;
using namespace Music::Styles;
using namespace Music::Styles::Factory;

int main()
{
	auto res = CompositionBuilder().SetName("Rock Town").AddStyle(CreateDefaultStyle(DefaultStyles::msRock)).AddAuthor("Timmy Trumpet").SetLength(0, 3, 45).Resault();
	std::stringstream ss;
	res.ToStream(ss);
	ss.seekp(0, 0);
	std::cout << ss.str() << std::endl;
	Composition b;
	b.FromStream(ss);
	std::cout << b.ToString();
}