#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include "../GNULiteral.h"
#include "../Ostream.h"

using bm_clock = std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

namespace {
void ctBench(std::ofstream& out, size_t iterations) {
  using namespace philwill::literals;
  constexpr auto formatter = "This is iteration %d\n"_printf;
  for (size_t i = 0; i < iterations; ++i) {
    out << formatter(i);
  }
  out.flush();
}

void cppBench(std::ofstream& out, size_t iterations) {
  for (size_t i = 0; i < iterations; ++i) {
    out << "This is iteration " << i << "\n";
  }
  out.flush();
}

void cBench(std::FILE* out, size_t iterations) {
  for (size_t i = 0; i < iterations; ++i) {
    fprintf(out, "This is iteration %lu\n", i);
  }
  fflush(out);
}

struct Bench {
  explicit Bench(std::string what) : what_(std::move(what)) {}
  ~Bench() noexcept {
    try {
      auto end = bm_clock::now();
      std::cout << what_ << ": "
                << duration_cast<milliseconds>(end - begin_).count() << "ms\n";
    } catch (...) {
    }
  }

 private:
  std::string what_;
  bm_clock::time_point begin_{bm_clock::now()};
};
}  // namespace

int main(int argc, char* argv[]) {
  const size_t iterations = argc > 1 ? std::stoul(argv[1]) : 100000;
  std::ofstream cppFile;
  cppFile.open("/dev/null");
  {
    auto x = Bench("Compile time printf");
    ctBench(cppFile, iterations);
  }
  cppFile.close();
  cppFile.open("/dev/null");
  {
    auto x = Bench("C++ stream output");
    cppBench(cppFile, iterations);
  }
  cppFile.close();
  auto cFile = fopen("/dev/null", "w");
  {
    auto x = Bench("C fprintf");
    cBench(cFile, iterations);
  }
  fclose(cFile);
  return 0;
}

// $ examples/RuntimeBenchmarks 10000000
// Compile time printf: 3668ms
// C++ stream output: 3357ms
// C fprintf: 1676ms