#include <cassert>
#include "../HexIntegralArgument.h"
#include "CommonTests.h"

using philwill::LowerHexIntegralArgument;

template <typename CharT>
struct VisitExpect {
  VisitExpect(bool& matched, philwill::Span<CharT const*> expected)
      : matched_(matched), expected_(expected) {}
  void operator()(philwill::Span<CharT const*> const& span) {
    assert(expected_ == span && "Span not what we expected");
    matched_ = true;
  }

 private:
  bool& matched_;
  philwill::Span<CharT const*> expected_;
};

template <typename CharT, typename Int>
LowerHexIntegralArgument<CharT> argumentFrom(Int theInt) {
  return {theInt};
}

template <typename CharT>
int test0(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('0')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test1(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('1')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test2(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('2')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test3(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('3')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test4(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('4')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test5(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('5')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test6(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('6')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test7(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('7')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test8(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('8')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test9(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('9')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test10(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('a')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test11(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('b')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test12(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('c')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test13(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('d')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test14(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('e')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test15(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('f')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test16(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(2 == test.size() && "size() must be 2");
  bool matched = false;
  CharT expected[] = {CharT('1'), CharT('0')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test255(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(2 == test.size() && "size() must be 2");
  bool matched = false;
  CharT expected[] = {CharT('f'), CharT('f')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test65535(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(4 == test.size() && "size() must be 4");
  bool matched = false;
  CharT expected[] = {CharT('f'), CharT('f'), CharT('f'), CharT('f')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test4294967295(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(8 == test.size() && "size() must be 8");
  bool matched = false;
  CharT expected[] = {CharT('f'), CharT('f'), CharT('f'), CharT('f'),
                      CharT('f'), CharT('f'), CharT('f'), CharT('f')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test18446744073709551615(LowerHexIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(16 == test.size() && "size() must be 16");
  bool matched = false;
  CharT expected[] = {CharT('f'), CharT('f'), CharT('f'), CharT('f'),
                      CharT('f'), CharT('f'), CharT('f'), CharT('f'),
                      CharT('f'), CharT('f'), CharT('f'), CharT('f'),
                      CharT('f'), CharT('f'), CharT('f'), CharT('f')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int doTest() {
  return test0(argumentFrom<CharT>(static_cast<unsigned char>(0))) +
         test0(argumentFrom<CharT>(static_cast<unsigned short>(0))) +
         test0(argumentFrom<CharT>(0U)) +
         test0(argumentFrom<CharT>(0UL)) +
         test0(argumentFrom<CharT>(0ULL)) +

         test1(argumentFrom<CharT>(static_cast<unsigned char>(1))) +
         test1(argumentFrom<CharT>(static_cast<unsigned short>(1))) +
         test1(argumentFrom<CharT>(1U)) +
         test1(argumentFrom<CharT>(1UL)) +
         test1(argumentFrom<CharT>(1ULL)) +

         test2(argumentFrom<CharT>(static_cast<unsigned char>(2))) +
         test2(argumentFrom<CharT>(static_cast<unsigned short>(2))) +
         test2(argumentFrom<CharT>(2U)) +
         test2(argumentFrom<CharT>(2UL)) +
         test2(argumentFrom<CharT>(2ULL)) +

         test3(argumentFrom<CharT>(static_cast<unsigned char>(3))) +
         test3(argumentFrom<CharT>(static_cast<unsigned short>(3))) +
         test3(argumentFrom<CharT>(3U)) +
         test3(argumentFrom<CharT>(3UL)) +
         test3(argumentFrom<CharT>(3ULL)) +

         test4(argumentFrom<CharT>(static_cast<unsigned char>(4))) +
         test4(argumentFrom<CharT>(static_cast<unsigned short>(4))) +
         test4(argumentFrom<CharT>(4U)) +
         test4(argumentFrom<CharT>(4UL)) +
         test4(argumentFrom<CharT>(4ULL)) +

         test5(argumentFrom<CharT>(static_cast<unsigned char>(5))) +
         test5(argumentFrom<CharT>(static_cast<unsigned short>(5))) +
         test5(argumentFrom<CharT>(5U)) +
         test5(argumentFrom<CharT>(5UL)) +
         test5(argumentFrom<CharT>(5ULL)) +

         test6(argumentFrom<CharT>(static_cast<unsigned char>(6))) +
         test6(argumentFrom<CharT>(static_cast<unsigned short>(6))) +
         test6(argumentFrom<CharT>(6U)) +
         test6(argumentFrom<CharT>(6UL)) +
         test6(argumentFrom<CharT>(6ULL)) +

         test7(argumentFrom<CharT>(static_cast<unsigned char>(7))) +
         test7(argumentFrom<CharT>(static_cast<unsigned short>(7))) +
         test7(argumentFrom<CharT>(7U)) +
         test7(argumentFrom<CharT>(7UL)) +
         test7(argumentFrom<CharT>(7ULL)) +

         test8(argumentFrom<CharT>(static_cast<unsigned char>(8))) +
         test8(argumentFrom<CharT>(static_cast<unsigned short>(8))) +
         test8(argumentFrom<CharT>(8U)) +
         test8(argumentFrom<CharT>(8UL)) +
         test8(argumentFrom<CharT>(8ULL)) +

         test9(argumentFrom<CharT>(static_cast<unsigned char>(9))) +
         test9(argumentFrom<CharT>(static_cast<unsigned short>(9))) +
         test9(argumentFrom<CharT>(9U)) +
         test9(argumentFrom<CharT>(9UL)) +
         test9(argumentFrom<CharT>(9ULL)) +

         test10(argumentFrom<CharT>(static_cast<unsigned char>(10))) +
         test10(argumentFrom<CharT>(static_cast<unsigned short>(10))) +
         test10(argumentFrom<CharT>(10U)) +
         test10(argumentFrom<CharT>(10UL)) +
         test10(argumentFrom<CharT>(10ULL)) +

         test11(argumentFrom<CharT>(static_cast<unsigned char>(11))) +
         test11(argumentFrom<CharT>(static_cast<unsigned short>(11))) +
         test11(argumentFrom<CharT>(11U)) +
         test11(argumentFrom<CharT>(11UL)) +
         test11(argumentFrom<CharT>(11ULL)) +

         test12(argumentFrom<CharT>(static_cast<unsigned char>(12))) +
         test12(argumentFrom<CharT>(static_cast<unsigned short>(12))) +
         test12(argumentFrom<CharT>(12U)) +
         test12(argumentFrom<CharT>(12UL)) +
         test12(argumentFrom<CharT>(12ULL)) +

         test13(argumentFrom<CharT>(static_cast<unsigned char>(13))) +
         test13(argumentFrom<CharT>(static_cast<unsigned short>(13))) +
         test13(argumentFrom<CharT>(13U)) +
         test13(argumentFrom<CharT>(13UL)) +
         test13(argumentFrom<CharT>(13ULL)) +

         test14(argumentFrom<CharT>(static_cast<unsigned char>(14))) +
         test14(argumentFrom<CharT>(static_cast<unsigned short>(14))) +
         test14(argumentFrom<CharT>(14U)) +
         test14(argumentFrom<CharT>(14UL)) +
         test14(argumentFrom<CharT>(14ULL)) +

         test15(argumentFrom<CharT>(static_cast<unsigned char>(15))) +
         test15(argumentFrom<CharT>(static_cast<unsigned short>(15))) +
         test15(argumentFrom<CharT>(15U)) +
         test15(argumentFrom<CharT>(15UL)) +
         test15(argumentFrom<CharT>(15ULL)) +

         test16(argumentFrom<CharT>(static_cast<unsigned char>(16))) +
         test16(argumentFrom<CharT>(static_cast<unsigned short>(16))) +
         test16(argumentFrom<CharT>(16U)) +
         test16(argumentFrom<CharT>(16UL)) +
         test16(argumentFrom<CharT>(16ULL)) +

         test255(argumentFrom<CharT>(static_cast<unsigned char>(255))) +
         test255(argumentFrom<CharT>(static_cast<unsigned short>(255))) +
         test255(argumentFrom<CharT>(255U)) +
         test255(argumentFrom<CharT>(255UL)) +
         test255(argumentFrom<CharT>(255ULL)) +

         test65535(argumentFrom<CharT>(static_cast<unsigned short>(65535))) +
         test65535(argumentFrom<CharT>(65535U)) +
         test65535(argumentFrom<CharT>(65535UL)) +
         test65535(argumentFrom<CharT>(65535ULL)) +

         test4294967295(argumentFrom<CharT>(4294967295U)) +
         test4294967295(argumentFrom<CharT>(4294967295UL)) +
         test4294967295(argumentFrom<CharT>(4294967295ULL)) +

         test18446744073709551615(argumentFrom<CharT>(18446744073709551615UL)) +
         test18446744073709551615(
             argumentFrom<CharT>(18446744073709551615ULL)) +

         0;
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}