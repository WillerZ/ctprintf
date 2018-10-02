#include <cassert>
#include <string>
#include "../StringAccumulatingVisitor.h"

using philwill::StringAccumulatingVisitor;

template <typename CharT>
int reserveTest() {
  std::basic_string<CharT> output;
  auto accumulator = StringAccumulatingVisitor(output);
  accumulator.reserve(40);
  auto capacity = output.capacity();
  assert(capacity >= 40 && "capacity() must be at least 40");
  for (size_t i = 0; i <= capacity; ++i) {
    output.push_back(CharT('x'));
  }
  accumulator.reserve(40);
  assert((output.capacity() - output.size()) >= 40 && "free capacity must be at least 40");
  return 0;
}

template <typename CharT>
int applyTest() {
  CharT const array[] = {CharT('H'), CharT('e'), CharT('l'), CharT('l'),
                         CharT('o')};
  philwill::Span<CharT const*> const span(&array[0], &array[5]);
  std::basic_string<CharT> const expected{&array[0], &array[5]};
  std::basic_string<CharT> actual;
  auto accumulator = StringAccumulatingVisitor(actual);

  accumulator(span);
  assert(expected == actual && "Expected and actual should match");
  return 0;
}

template <typename CharT>
int doTest() {
  return reserveTest<CharT>() + applyTest<CharT>();
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}