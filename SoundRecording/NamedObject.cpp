#include "NamedObject.h"

namespace Music
{
	namespace Categorization
	{
		NamedObject::NamedObject(std::string name, std::string description, std::vector<std::string> authors)
			: name_(name),
			description_(description_),
			authors_(authors_) {}

		std::string NamedObject::ToString() const
		{
			std::string r = name_ + " -";
			for (size_t i = 0; i < authors_.size(); i++)
			{
				r += (i == 0 ? " " : ", ") + authors_[i];
			}
			return r;
		}

		std::string NamedObject::Name()
		{
			return name_;
		}

		std::string NamedObject::Description()
		{
			return description_;
		}

		std::vector<std::string> NamedObject::Authors()
		{
			return authors_;
		}

		void NamedObject::ToStream(std::ostream& out) const
		{
			out << name_ << "\n" << description_ << "\n!==!\n";
			out << authors_.size() << '\n';
			for (auto i : authors_)
			{
				out << i << "\n";
			}
		}

		void NamedObject::FromStream(std::istream& in)
		{
			std::getline(in, name_);
			std::string buf;
			std::getline(in, buf);
			while (buf != "!==!")
			{
				description_ += buf + "\n";
				buf.clear();
				std::getline(in, buf);
			}
			description_.erase(description_.begin() + (description_.size() - 1));
			size_t sz = 0;
			in >> sz;
			buf.clear();
			std::getline(in, buf);
			while (sz-- > 0)
			{
				buf.clear();
				std::getline(in, buf);
				authors_.push_back(buf);
			}
		}
	}
}