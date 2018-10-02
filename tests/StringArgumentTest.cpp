#include <cassert>
#include "../StringArgument.h"
#include "CommonTests.h"

using philwill::StringArgument;
using namespace std::literals;

template <typename CharT>
struct HelloVisitor {
  HelloVisitor(bool& matched) : matched_(matched) {}
  void operator()(philwill::Span<CharT const*> const& span) {
    assert(5 == span.size() && "Span size() must be 5");
    assert(CharT('H') == span.begin()[0] && "Span content must be \"Hello\"");
    assert(CharT('e') == span.begin()[1] && "Span content must be \"Hello\"");
    assert(CharT('l') == span.begin()[2] && "Span content must be \"Hello\"");
    assert(CharT('l') == span.begin()[3] && "Span content must be \"Hello\"");
    assert(CharT('o') == span.begin()[4] && "Span content must be \"Hello\"");
    matched_ = true;
  }

 private:
  bool& matched_;
};

template <typename CharT>
StringArgument<CharT> argumentFromCStringLiteral();

template <typename CharT>
StringArgument<CharT> argumentFromStringViewLiteral();

template <typename CharT>
int helloTest(StringArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(5 == test.size() && "size() must be 5");
  bool matched = false;
  test.accept(HelloVisitor<CharT>(matched));
  return !matched;
}

template <typename CharT>
int doTest() {
  return helloTest(argumentFromCStringLiteral<CharT>()) + helloTest(argumentFromStringViewLiteral<CharT>());
}

template <>
StringArgument<char> argumentFromCStringLiteral<char>() {
  return {"Hello"};
}

template <>
StringArgument<wchar_t> argumentFromCStringLiteral<wchar_t>() {
  return {L"Hello"};
}

template <>
StringArgument<char16_t> argumentFromCStringLiteral<char16_t>() {
  return {u"Hello"};
}

template <>
StringArgument<char32_t> argumentFromCStringLiteral<char32_t>() {
  return {U"Hello"};
}

template <>
StringArgument<char> argumentFromStringViewLiteral<char>() {
  return {"Hello"sv};
}

template <>
StringArgument<wchar_t> argumentFromStringViewLiteral<wchar_t>() {
  return {L"Hello"sv};
}

template <>
StringArgument<char16_t> argumentFromStringViewLiteral<char16_t>() {
  return {u"Hello"sv};
}

template <>
StringArgument<char32_t> argumentFromStringViewLiteral<char32_t>() {
  return {U"Hello"sv};
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}