#include <cassert>
#include <string>
#include <sstream>
#include "../OstreamVisitor.h"

using philwill::OstreamVisitor;

template <typename CharT>
int applyTest() {
  CharT const array[] = {CharT('H'), CharT('e'), CharT('l'), CharT('l'),
                         CharT('o')};
  philwill::Span<CharT const*> const span(&array[0], &array[5]);
  std::basic_string<CharT> const expected{&array[0], &array[5]};
  std::basic_ostringstream<CharT> actual;
  auto accumulator = OstreamVisitor(actual);

  accumulator(span);
  assert(expected == actual.str() && "Expected and actual should match");
  return 0;
}

template <typename CharT>
int doTest() {
  return applyTest<CharT>();
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}