#include <cassert>
#include "../DecimalIntegralArgument.h"
#include "CommonTests.h"

using philwill::DecimalIntegralArgument;

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
DecimalIntegralArgument<CharT> argumentFrom(Int theInt) {
  return {theInt};
}

template <typename CharT>
int test0(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('0')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test1(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(1 == test.size() && "size() must be 1");
  bool matched = false;
  CharT expected[] = {CharT('1')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test_1(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(2 == test.size() && "size() must be 2");
  bool matched = false;
  CharT expected[] = {CharT('-'), CharT('1')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test127(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(3 == test.size() && "size() must be 3");
  bool matched = false;
  CharT expected[] = {CharT('1'), CharT('2'), CharT('7')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test_128(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(4 == test.size() && "size() must be 4");
  bool matched = false;
  CharT expected[] = {CharT('-'), CharT('1'), CharT('2'), CharT('8')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test255(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(3 == test.size() && "size() must be 3");
  bool matched = false;
  CharT expected[] = {CharT('2'), CharT('5'), CharT('5')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test32767(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(5 == test.size() && "size() must be 5");
  bool matched = false;
  CharT expected[] = {CharT('3'), CharT('2'), CharT('7'), CharT('6'),
                      CharT('7')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test_32768(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(6 == test.size() && "size() must be 6");
  bool matched = false;
  CharT expected[] = {CharT('-'), CharT('3'), CharT('2'),
                      CharT('7'), CharT('6'), CharT('8')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test65535(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(5 == test.size() && "size() must be 5");
  bool matched = false;
  CharT expected[] = {CharT('6'), CharT('5'), CharT('5'), CharT('3'),
                      CharT('5')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test2147483647(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(10 == test.size() && "size() must be 10");
  bool matched = false;
  CharT expected[] = {CharT('2'), CharT('1'), CharT('4'), CharT('7'),
                      CharT('4'), CharT('8'), CharT('3'), CharT('6'),
                      CharT('4'), CharT('7')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test_2147483648(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(11 == test.size() && "size() must be 11");
  bool matched = false;
  CharT expected[] = {CharT('-'), CharT('2'), CharT('1'), CharT('4'),
                      CharT('7'), CharT('4'), CharT('8'), CharT('3'),
                      CharT('6'), CharT('4'), CharT('8')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test4294967295(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(10 == test.size() && "size() must be 10");
  bool matched = false;
  CharT expected[] = {CharT('4'), CharT('2'), CharT('9'), CharT('4'),
                      CharT('9'), CharT('6'), CharT('7'), CharT('2'),
                      CharT('9'), CharT('5')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test9223372036854775807(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(19 == test.size() && "size() must be 19");
  bool matched = false;
  CharT expected[] = {CharT('9'), CharT('2'), CharT('2'), CharT('3'),
                      CharT('3'), CharT('7'), CharT('2'), CharT('0'),
                      CharT('3'), CharT('6'), CharT('8'), CharT('5'),
                      CharT('4'), CharT('7'), CharT('7'), CharT('5'),
                      CharT('8'), CharT('0'), CharT('7')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test_9223372036854775808(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(20 == test.size() && "size() must be 20");
  bool matched = false;
  CharT expected[] = {CharT('-'), CharT('9'), CharT('2'), CharT('2'),
                      CharT('3'), CharT('3'), CharT('7'), CharT('2'),
                      CharT('0'), CharT('3'), CharT('6'), CharT('8'),
                      CharT('5'), CharT('4'), CharT('7'), CharT('7'),
                      CharT('5'), CharT('8'), CharT('0'), CharT('8')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int test18446744073709551615(DecimalIntegralArgument<CharT> const& test) {
  philwill::tests::correctVisitorTest(test);
  assert(20 == test.size() && "size() must be 20");
  bool matched = false;
  CharT expected[] = {CharT('1'), CharT('8'), CharT('4'), CharT('4'),
                      CharT('6'), CharT('7'), CharT('4'), CharT('4'),
                      CharT('0'), CharT('7'), CharT('3'), CharT('7'),
                      CharT('0'), CharT('9'), CharT('5'), CharT('5'),
                      CharT('1'), CharT('6'), CharT('1'), CharT('5')};
  test.accept(VisitExpect<CharT>(matched, expected));
  return !matched;
}

template <typename CharT>
int doTest() {
  return test0(argumentFrom<CharT>(static_cast<unsigned char>(0))) +
         test0(argumentFrom<CharT>(static_cast<signed char>(0))) +
         test0(argumentFrom<CharT>(static_cast<unsigned short>(0))) +
         test0(argumentFrom<CharT>(static_cast<signed short>(0))) +
         test0(argumentFrom<CharT>(0U)) + test0(argumentFrom<CharT>(0)) +
         test0(argumentFrom<CharT>(0UL)) + test0(argumentFrom<CharT>(0L)) +
         test0(argumentFrom<CharT>(0ULL)) + test0(argumentFrom<CharT>(0LL)) +

         test1(argumentFrom<CharT>(static_cast<unsigned char>(1))) +
         test1(argumentFrom<CharT>(static_cast<signed char>(1))) +
         test1(argumentFrom<CharT>(static_cast<unsigned short>(1))) +
         test1(argumentFrom<CharT>(static_cast<signed short>(1))) +
         test1(argumentFrom<CharT>(1U)) + test1(argumentFrom<CharT>(1)) +
         test1(argumentFrom<CharT>(1UL)) + test1(argumentFrom<CharT>(1L)) +
         test1(argumentFrom<CharT>(1ULL)) + test1(argumentFrom<CharT>(1LL)) +

         test127(argumentFrom<CharT>(static_cast<unsigned char>(127))) +
         test127(argumentFrom<CharT>(static_cast<signed char>(127))) +
         test127(argumentFrom<CharT>(static_cast<unsigned short>(127))) +
         test127(argumentFrom<CharT>(static_cast<signed short>(127))) +
         test127(argumentFrom<CharT>(127U)) +
         test127(argumentFrom<CharT>(127)) +
         test127(argumentFrom<CharT>(127UL)) +
         test127(argumentFrom<CharT>(127L)) +
         test127(argumentFrom<CharT>(127ULL)) +
         test127(argumentFrom<CharT>(127LL)) +

         test255(argumentFrom<CharT>(static_cast<unsigned char>(255))) +
         test255(argumentFrom<CharT>(static_cast<unsigned short>(255))) +
         test255(argumentFrom<CharT>(static_cast<signed short>(255))) +
         test255(argumentFrom<CharT>(255U)) +
         test255(argumentFrom<CharT>(255)) +
         test255(argumentFrom<CharT>(255UL)) +
         test255(argumentFrom<CharT>(255L)) +
         test255(argumentFrom<CharT>(255ULL)) +
         test255(argumentFrom<CharT>(255LL)) +

         test32767(argumentFrom<CharT>(static_cast<unsigned short>(32767))) +
         test32767(argumentFrom<CharT>(static_cast<signed short>(32767))) +
         test32767(argumentFrom<CharT>(32767U)) +
         test32767(argumentFrom<CharT>(32767)) +
         test32767(argumentFrom<CharT>(32767UL)) +
         test32767(argumentFrom<CharT>(32767L)) +
         test32767(argumentFrom<CharT>(32767ULL)) +
         test32767(argumentFrom<CharT>(32767LL)) +

         test65535(argumentFrom<CharT>(static_cast<unsigned short>(65535))) +
         test65535(argumentFrom<CharT>(65535U)) +
         test65535(argumentFrom<CharT>(65535)) +
         test65535(argumentFrom<CharT>(65535UL)) +
         test65535(argumentFrom<CharT>(65535L)) +
         test65535(argumentFrom<CharT>(65535ULL)) +
         test65535(argumentFrom<CharT>(65535LL)) +

         test2147483647(argumentFrom<CharT>(2147483647U)) +
         test2147483647(argumentFrom<CharT>(2147483647)) +
         test2147483647(argumentFrom<CharT>(2147483647UL)) +
         test2147483647(argumentFrom<CharT>(2147483647L)) +
         test2147483647(argumentFrom<CharT>(2147483647ULL)) +
         test2147483647(argumentFrom<CharT>(2147483647LL)) +

         test4294967295(argumentFrom<CharT>(4294967295U)) +
         test4294967295(argumentFrom<CharT>(4294967295UL)) +
         test4294967295(argumentFrom<CharT>(4294967295L)) +
         test4294967295(argumentFrom<CharT>(4294967295ULL)) +
         test4294967295(argumentFrom<CharT>(4294967295L)) +

         test9223372036854775807(argumentFrom<CharT>(9223372036854775807UL)) +
         test9223372036854775807(argumentFrom<CharT>(9223372036854775807L)) +
         test9223372036854775807(argumentFrom<CharT>(9223372036854775807ULL)) +
         test9223372036854775807(argumentFrom<CharT>(9223372036854775807LL)) +

         test18446744073709551615(argumentFrom<CharT>(18446744073709551615UL)) +
         test18446744073709551615(
             argumentFrom<CharT>(18446744073709551615ULL)) +

         test_1(argumentFrom<CharT>(static_cast<signed char>(-1))) +
         test_1(argumentFrom<CharT>(static_cast<signed short>(-1))) +
         test_1(argumentFrom<CharT>(-1)) + test_1(argumentFrom<CharT>(-1L)) +
         test_1(argumentFrom<CharT>(-1LL)) +

         test_128(argumentFrom<CharT>(static_cast<signed char>(-128))) +
         test_128(argumentFrom<CharT>(static_cast<signed short>(-128))) +
         test_128(argumentFrom<CharT>(-128)) +
         test_128(argumentFrom<CharT>(-128L)) +
         test_128(argumentFrom<CharT>(-128LL)) +

         test_32768(argumentFrom<CharT>(static_cast<signed short>(-32768))) +
         test_32768(argumentFrom<CharT>(-32768)) +
         test_32768(argumentFrom<CharT>(-32768L)) +
         test_32768(argumentFrom<CharT>(-32768LL)) +

         test_2147483648(argumentFrom<CharT>(-2147483648)) +
         test_2147483648(argumentFrom<CharT>(-2147483648L)) +
         test_2147483648(argumentFrom<CharT>(-2147483648LL)) +

         test_9223372036854775808(
             argumentFrom<CharT>(-9223372036854775807L - 1L)) +
         test_9223372036854775808(
             argumentFrom<CharT>(-9223372036854775807LL - 1LL)) +

         0;
}

int main() {
  return doTest<char>() + doTest<wchar_t>() + doTest<char16_t>() +
         doTest<char32_t>();
}