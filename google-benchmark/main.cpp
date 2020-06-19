#include <benchmark/benchmark.h>
#include <iostream>
#include <string>

static void BM_MAX(benchmark::State& state){
	for(auto _ : state)
		std::max(10,5);
}

BENCHMARK(BM_MAX);

BENCHMARK_MAIN();
