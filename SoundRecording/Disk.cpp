#include "Disk.h"

namespace Music
{
	size_t Disk::StyleHash::operator()(const Style& obj) const noexcept
	{
		return obj.Hash();
	}

	void Disk::ToStream(std::ostream& out) const
	{
		out << Compositions.size() << '\n';
		for (auto& i : Compositions)
		{
			i.ToStream(out);
			out << "\n";
		}
	}
	void Disk::FromStream(std::istream& in)
	{
		size_t sz = 0;
		in >> sz;
		std::string a;
		std::getline(in, a);
		while (sz-- != 0)
		{
			Compositions.push_back({});
			Compositions.back().FromStream(in);
		}
	}

	std::vector<Style> Disk::Styles() const
	{
		std::unordered_set<Style, StyleHash> set;
		for (auto& cmp : Compositions)
		{
			for (auto& style : cmp.Styles())
			{
				set.insert(style);
			}
		}
		return std::vector<Style>(set.begin(), set.end());
	}

	TimeSpan Disk::Length() const
	{
		TimeSpan res(0);
		for (auto& cmp : Compositions)
		{
			res = res + cmp.Length();
		}
		return res;
	}
}

