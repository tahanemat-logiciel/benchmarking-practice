#include <hayai/hayai.hpp>
#include "delivery_man.hpp"

BENCHMARK(DeliveryMan, DeliverPackage, 10, 100){
	DeliveryMan().DeliverPackage();
}

