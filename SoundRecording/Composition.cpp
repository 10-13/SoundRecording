#include "Composition.h"

namespace Music
{
	void Composition::ToStream(std::ostream& out) const
	{
		NamedObject::ToStream(out);
		out << '\n';
		length_.ToStream(out);
		out << '\n';
		out << styles_.size() << ' ';
		for (auto& a : styles_)
		{
			out << (&a) << '\n';
		}
	}

	void Composition::FromStream(std::istream& in)
	{
		NamedObject::FromStream(in);
		this->length_.FromStream(in);
		size_t ssz = 0;
		in >> ssz;
		while (ssz-- > 0)
		{
			Style tmp(0);
			tmp.FromStream(in);
			styles_.emplace_back(std::move(tmp));
		}
	}

	std::vector<Style> Composition::Styles()
	{
		return styles_;
	}

	std::string Composition::ToString() const
	{
		std::string res = NamedObject::ToString() + "(" + TimedObject::ToString() + ")\n[ ";
		for (auto& i : styles_)
		{
			res += i.GetName() + ", ";
		}
		res += "]";
		return res;
	}
}