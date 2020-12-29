#include <benchmark/benchmark.h>
#include <iostream>
#include <string>
#include <g3log/g3log.hpp>
#include <g3log/logworker.hpp>

// struct CustomSink {

// // Linux xterm color
// // http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
  // enum FG_Color {YELLOW = 33, RED = 31, GREEN=32, WHITE = 97};

  // FG_Color GetColor(const LEVELS level) const {
     // if (level.value == WARNING.value) { return YELLOW; }
     // if (level.value == DEBUG.value) { return GREEN; }
     // if (g3::internal::wasFatal(level)) { return RED; }

     // return WHITE;
  // }

  // void ReceiveLogMessage(g3::LogMessageMover logEntry) {
     // auto level = logEntry.get()._level;
     // auto color = GetColor(level);

     // std::cout << "\033[" << color << "m"
       // << logEntry.get().toString() << "\033[m" << std::endl;
  // }
// };

static void BM_MAX(benchmark::State& state){
  auto worker = g3::LogWorker::createLogWorker();
  auto defaultHandler = worker->addDefaultLogger("logi", ".");

  g3::initializeLogging(worker.get());

  for(auto _ : state){
    LOGF(WARNING, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  }

  // worker->addSink(std::make_unique<CustomSink>(), &CustomSink::ReceiveLogMessage);

}

BENCHMARK(BM_MAX);

BENCHMARK_MAIN();
