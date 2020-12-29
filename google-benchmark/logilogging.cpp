#include <benchmark/benchmark.h>
#include <iostream>
#include <memory>
#include <string>
#include <logging/logger.h>
#include <logging/config.h>

void ConfigureLogger() {
  auto sink = std::make_shared<LogiLogging::AsyncWaitFreeProcessor>(std::make_shared<LogiLogging::TextLayout>());

  sink->appenders().push_back(std::make_shared<LogiLogging::RollingFileAppender>(".", LogiLogging::TimeRollingPolicy::SECOND, "${UtcDateTime}.log", true));

  LogiLogging::Config::ConfigLogger("example", sink);

  LogiLogging::Config::Startup();
}

  
static void BM_MAX(benchmark::State& state){
  ConfigureLogger();
  LogiLogging::Logger logger("example");

  constexpr const char *msg =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  for(auto _ : state){
    logger.Debug(msg);
  }

}

BENCHMARK(BM_MAX);

BENCHMARK_MAIN();
