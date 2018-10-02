#pragma once
#include <array>
#include <utility>
#include "Span.h"

namespace philwill {

template <typename CharT, CharT... Digits>
struct TenDigitIntegralArgument {
  using char_type = CharT;
  static_assert(sizeof...(Digits) == 11,
                "Need 11 digits for decimal alphabet: 0-9 and -");

  constexpr TenDigitIntegralArgument(unsigned long long input)
      : buffer_(), used_(size(input)) {
    initBuffer(input);
  }

  constexpr TenDigitIntegralArgument(signed long long input)
      : buffer_(), used_(size(input)) {
    if (input >= 0) {
      initBuffer(static_cast<unsigned long long>(input));
      return;
    }
    signed long long integer = input;
    std::size_t index = used_;
    while (--index) {
      buffer_[index] = digits[-1 * (integer % 10LL)];
      integer /= 10LL;
    }
    buffer_[0] = digits[10];
  }

  constexpr TenDigitIntegralArgument(unsigned long integer)
      : TenDigitIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr TenDigitIntegralArgument(signed long integer)
      : TenDigitIntegralArgument(static_cast<signed long long>(integer)) {}

  constexpr TenDigitIntegralArgument(unsigned int integer)
      : TenDigitIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr TenDigitIntegralArgument(signed int integer)
      : TenDigitIntegralArgument(static_cast<signed long long>(integer)) {}

  constexpr TenDigitIntegralArgument(unsigned short integer)
      : TenDigitIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr TenDigitIntegralArgument(signed short integer)
      : TenDigitIntegralArgument(static_cast<signed long long>(integer)) {}

  constexpr TenDigitIntegralArgument(unsigned char integer)
      : TenDigitIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr TenDigitIntegralArgument(signed char integer)
      : TenDigitIntegralArgument(static_cast<signed long long>(integer)) {}

  template <typename Visitor>
  constexpr auto accept(Visitor&& visitor) const {
    return std::forward<Visitor>(visitor)(
        Span<CharT const*>(buffer_.data(), buffer_.data() + used_));
  }

  constexpr std::size_t size() const { return used_; }

 private:
  constexpr void initBuffer(const unsigned long long input) {
    unsigned long long integer = input;
    std::size_t index = used_;
    while (index) {
      --index;
      buffer_[index] = digits[integer % 10ULL];
      integer /= 10ULL;
    }
  }

  constexpr static std::size_t size(unsigned long long input) {
    std::size_t count = 1;
    unsigned long long integer = input;
    while (integer > 9) {
      ++count;
      integer /= 10;
    }
    return count;
  }

  constexpr static std::size_t size(signed long long input) {
    if (input >= 0) {
      return size(static_cast<unsigned long long>(input));
    }
    std::size_t count = 2;
    long long integer = input;
    while (integer < -9) {
      ++count;
      integer /= 10;
    }
    return count;
  }

  static constexpr CharT digits[11] = {Digits...};
  std::array<CharT, 1 + static_cast<std::size_t>(1+sizeof(unsigned long long) * 8 * 0.31)> buffer_;
  size_t used_;
};

template <typename CharT>
using DecimalIntegralArgument =
    TenDigitIntegralArgument<CharT, CharT('0'), CharT('1'), CharT('2'),
                             CharT('3'), CharT('4'), CharT('5'), CharT('6'),
                             CharT('7'), CharT('8'), CharT('9'), CharT('-')>;

extern template struct TenDigitIntegralArgument<char, '0', '1', '2', '3', '4',
                                                '5', '6', '7', '8', '9', '-'>;
extern template struct TenDigitIntegralArgument<
    wchar_t, L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'-'>;
extern template struct TenDigitIntegralArgument<
    char16_t, u'0', u'1', u'2', u'3', u'4', u'5', u'6', u'7', u'8', u'9', u'-'>;
extern template struct TenDigitIntegralArgument<
    char32_t, U'0', U'1', U'2', U'3', U'4', U'5', U'6', U'7', U'8', U'9', U'-'>;

}  // namespace philwill
