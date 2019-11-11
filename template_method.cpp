#include <string>
#include <vector>
#include <iostream>


namespace patterns {
	class Jorney {
	public:
		std::vector<std::string> thingsToDo;

		virtual std::string enjoy_vocation() = 0;

		std::string but_flight() {
			return "Buy a flight ticket";
		}

		std::string take_plane() {
			return "Taking the plane";
		}

		void take_trip() {
			this->thingsToDo.push_back(this->but_flight());
			this->thingsToDo.push_back(this->take_plane());
			this->thingsToDo.push_back(this->enjoy_vocation());
			for (int i = 0; i < this->thingsToDo.size(); i++) {
				std::cout << this->thingsToDo[i] << std::endl;
			}
		}
	};

	class CityJorney : public Jorney {
		std::string enjoy_vocation() {
			return "Go to the museum, see historical places";
		}
	};

	class BeachJorney : public Jorney {
		std::string enjoy_vocation() {
			return "Swim and take a sunbath";
		}
	};
}