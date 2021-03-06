// Builder Design Patter 1
// 
// 

//	20-Jul-2018	Aman Kesarwani	Initial Creation

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace html {

	struct TagObject {
		string m_name;
		string m_text;
		vector<TagObject> children;
		vector<pair<string, string>> properties;


		friend ostream& operator<<(ostream& os, const TagObject& tag) {
		
			os << "<" << tag.m_name;

			for (const auto& att : tag.properties) {
				os << " " << att.first << "=\"" << att.second << "\"";
			}

			if (tag.children.size() == 0 && tag.m_text.length() == 0) {
				os << "/>" << endl;
			}

			else {
				os << ">" << endl;

				if (tag.m_text.length()) {
					os << tag.m_text << endl;
				}

				for (const auto& child : tag.children) {
					os << child;
				}
			}

			return os;
		}

	protected:

		TagObject(const string name, const string text) : m_name{ name }, m_text{ text }
		{}

		TagObject(const string name, const vector<TagObject> children) : m_name{ name }, children{ children } {}
	};

	struct P : TagObject {
		explicit P(const string& text): TagObject("p", text) {}

		P(initializer_list<TagObject> children) : TagObject("p", children) {}

	};

	struct IMG : TagObject {

		explicit IMG(const string& url) : TagObject{ "img", "" } {
			properties.emplace_back(make_pair("src", url));
		}

	};
}
int main()
{
	using namespace html;


	cout <<

		P{
			IMG {"http://facebook.com/fb.png"}
	}
	<< endl;
    return 0;
}

