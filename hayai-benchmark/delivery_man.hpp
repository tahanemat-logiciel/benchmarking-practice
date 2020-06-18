#include <cstddef>
#include <iostream>

#ifndef __DELIVERY_MAN
#define __DELIVERY_MAN

class DeliveryMan
{
public:

	void DeliverPackage(std::size_t distance){
		std::size_t largeNumber = 10000u * distance / _speed;
		volatile std::size_t targetNumber;
		while (largeNumber--)
			targetNumber = largeNumber;

	}

	DeliveryMan(std::size_t speed)
		: _speed(speed)
	{
	}

private:
	std::size_t _speed;

};
#endif
