#include <cassert>
#include "CommonTests.h"
#include "../CharArgument.h"

using philwill::CharArgument;

template <typename CharT>
int doTest() {
  CharArgument<CharT> test(CharT('x'));
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  test.accept([&](auto const& Span) {
    assert(1 == Span.size() && "Span size() must be 1");
    assert(CharT('x') == *Span.begin() && "Span content must be 'x'");
    matched = true;
  });
  return !matched;
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}