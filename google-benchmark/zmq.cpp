#include <benchmark/benchmark.h>
#include <iostream>
#include <string>
#include <zmq.h>
#include <zmq.hpp>

static void BM_MAX(benchmark::State& state){
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUSH);

    std::cout << "connecting" << std::endl;

    socket.connect("tcp://localhost:5556");

    constexpr const char * t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  for(auto _ : state){
    zmq::message_t msg(std::move(t),200);
    socket.send(msg, zmq::send_flags::dontwait);
  }
}

BENCHMARK(BM_MAX);

BENCHMARK_MAIN();
