#include <benchmark/benchmark.h>
#include <iostream>
#include <string>
#include <logger/logger.hpp>

static void BM_MAX(benchmark::State& state){
  logiciel::logger::Logger logger("test", ".");

  constexpr const char * msg = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  for(auto _ : state){
    logiciel::logger::LogWarning() << msg;
  }

  (void)logger;
}

BENCHMARK(BM_MAX);

BENCHMARK_MAIN();
