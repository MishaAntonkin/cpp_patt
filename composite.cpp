#include <string>
#include <vector>
#include <iostream>

namespace patterns {
	class IRanderableElement {
	public:
		virtual std::string render() = 0;
	};

	class Form: public IRanderableElement {
	private:
		std::vector<IRanderableElement * > elements;
	public:
		std::string render() {
			std::string elementsString = "";
			for (int i = 0; i < (int)this->elements.size(); i++) {
				elementsString += this->elements[i]->render();
			}
			return "<form>" + elementsString + "</form>";
		}

		void add_member(IRanderableElement *element) {
			this->elements.push_back(element);
		}
	};

	class Input : public IRanderableElement {
	public:
		std::string render() {
			return "<input type=\"text\">";
		}
	};
	class TestComposite {
	public:
		static void test() {
			std::string testString = "<form><input type=\"text\"></form>";
			Form *wrap = new Form();
			wrap->add_member(new Input);
			std::cout << "is composite correct?\n" << std::endl;
			std::cout << (bool)(wrap->render().compare(testString));
		}
	};
}