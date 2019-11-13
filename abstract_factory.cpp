#include <string>

namespace patterns {
	class Frame {};

	class Wheel {};
	
	class BicycleFrame : public Frame {};

	class BicycleWheel : public Wheel {};

	class CarFrame : public Frame {};

	class CarWheel : public Wheel {};

	class BaseTransportFactory {
	public:
		virtual Frame* create_frame() = 0;
		virtual Wheel* create_wheel() = 0;
	};

	class CarFactory : public BaseTransportFactory {
	public:
		virtual CarFrame* create_frame() {
			return new CarFrame();
		}
		virtual CarWheel* create_wheel() {
			return new CarWheel();
		}
	};

	class BicycleFactory : public BaseTransportFactory {
	public:
		virtual BicycleFrame* create_frame() {
			return new BicycleFrame();
		}
		virtual BicycleWheel* create_wheel() {
			return new BicycleWheel();
		}
	};

	void test_abstract_factory() {
		CarFactory *car = new CarFactory();
		Frame* frame = car->create_frame();
		Wheel* wheel = car->create_wheel();
	}
}