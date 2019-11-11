#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "singleton.cpp"
#include "composite.cpp"


int sumOfDifferences(const std::vector<int>& arr) {
	//your code here
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
	return  0;
}

