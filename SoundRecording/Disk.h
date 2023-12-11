#pragma once
#include "Composition.h"
#include <unordered_set>

namespace Music
{
	class Disk : public Music::Categorization::NamedObject, public Music::Serialization::Serializeble
	{
	private:
		struct StyleHash
		{
			size_t operator()(const Style& obj) const noexcept
			{
				return obj.Hash();
			}
		};
	public:
		std::vector<Composition> Compositions;

		Disk() = default;

		void ToStream(std::ostream& out) const override
		{
			out << Compositions.size() << '\n';
			for (auto& i : Compositions)
			{
				i.ToStream(out);
				out << "\n";
			}
		}
		void FromStream(std::istream& in) override
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

		std::vector<Style> Styles() const
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

		TimeSpan Length() const
		{
			TimeSpan res(0);
			for (auto& cmp : Compositions)
			{
				res = res + cmp.Length();
			}
			return res;
		}
	};
}

