#define NONIUS RUNNER
#include "nonius/nonius.h++"
#include "nonius/main.h++"

NONIUS_BENCHMARK("std::max(10,5)", []{
		return std::max(10,5);
})
