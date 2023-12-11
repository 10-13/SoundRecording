#include <iostream>
#include <sstream>
#include "Composition.h"
#include "StyleFactory.h"
#include "CompositionBuilder.h"
#include "Disk.h"

using namespace Music;
using namespace Music::Categorization;
using namespace Music::PlayerCore;
using namespace Music::Serialization;
using namespace Music::Styles;
using namespace Music::Styles::Factory;

int main()
{
	auto res = CompositionBuilder().SetName("Rock Town").AddStyle(CreateDefaultStyle(DefaultStyles::msRock)).AddAuthor("Timmy Trumpet").SetLength(0, 3, 45).Resault();
	Disk disk;
	disk.Compositions.push_back(res);
	disk.Compositions.push_back(res);
	disk.Compositions.push_back(res);
	disk.ToStream(std::cout);
}