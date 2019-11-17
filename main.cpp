#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "singleton.cpp"
#include "composite.cpp"
#include "template_method.cpp"
#include "abstract_factory.cpp"
#include "pool.cpp"


int sumOfDifferences(const std::vector<int>& arr) {
	if (arr.size() == 0) {
		return 0;
	}
	std::vector<int> list = arr;
	sort(list.begin(), list.end(), std::greater<int>());
	
	return list.front() - list.back();
}

class Accumul
{
public:
	static std::string accum(const std::string& s) {
		std::string origin = s;
		std::string result = "";
		for (std::string::size_type i = 0; i < origin.size(); ++i) {
			char a = tolower(origin[i]);
			std::string tmp(i + 1, a);
			tmp[0] = toupper(tmp[0]);
			if (i == 0) {
				result += tmp;
				continue;
			}
			result += '-' + tmp;
		}
		return result;
	}
};

int main()
{
	patterns::TestComposite *testComposite = new patterns::TestComposite;
	testComposite->test();
	patterns::CityJorney* c_jorney = new patterns::CityJorney;
	c_jorney->take_trip();
	patterns::BeachJorney* b_jorney = new patterns::BeachJorney;
	b_jorney->take_trip();
	patterns::test_abstract_factory();
    patterns::test_pool();
	return  0;
}

