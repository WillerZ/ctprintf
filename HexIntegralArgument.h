#pragma once
#include <array>
#include <utility>
#include "Span.h"

namespace philwill {

template <typename CharT, CharT... Digits>
struct HexIntegralArgument {
  using char_type = CharT;
  static_assert(sizeof...(Digits) == 16, "Need 16 digits for hex alphabet");
  constexpr HexIntegralArgument(unsigned long long input)
      : buffer_(), used_(size(input)) {
    unsigned long long integer = input;
    std::size_t index = used_;
    while (index) {
      --index;
      buffer_[index] = digits[integer % 0x10ULL];
      integer >>= 4;
    }
  }

  constexpr HexIntegralArgument(unsigned long integer)
      : HexIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr HexIntegralArgument(unsigned int integer)
      : HexIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr HexIntegralArgument(unsigned short integer)
      : HexIntegralArgument(static_cast<unsigned long long>(integer)) {}

  constexpr HexIntegralArgument(unsigned char integer)
      : HexIntegralArgument(static_cast<unsigned long long>(integer)) {}

  template <typename Visitor>
  constexpr auto accept(Visitor&& visitor) const {
    return std::forward<Visitor>(visitor)(
        Span<CharT const*>(buffer_.data(), buffer_.data() + used_));
  }

  constexpr std::size_t size() const { return used_; }

 private:
  constexpr static std::size_t size(unsigned long long input) {
    std::size_t count = 1;
    unsigned long long integer = input;
    while (integer > 0xf) {
      ++count;
      integer >>= 4;
    }
    return count;
  }

  static constexpr CharT digits[16] = {Digits...};
  std::array<CharT, sizeof(unsigned long long) * 2> buffer_;
  size_t used_;
};

template <typename CharT>
using LowerHexIntegralArgument =
    HexIntegralArgument<CharT, CharT('0'), CharT('1'), CharT('2'), CharT('3'),
                        CharT('4'), CharT('5'), CharT('6'), CharT('7'),
                        CharT('8'), CharT('9'), CharT('a'), CharT('b'),
                        CharT('c'), CharT('d'), CharT('e'), CharT('f')>;

template <typename CharT>
using UpperHexIntegralArgument =
    HexIntegralArgument<CharT, CharT('0'), CharT('1'), CharT('2'), CharT('3'),
                        CharT('4'), CharT('5'), CharT('6'), CharT('7'),
                        CharT('8'), CharT('9'), CharT('A'), CharT('B'),
                        CharT('C'), CharT('D'), CharT('E'), CharT('F')>;

extern template struct HexIntegralArgument<char, '0', '1', '2', '3', '4', '5',
                                           '6', '7', '8', '9', 'a', 'b', 'c',
                                           'd', 'e', 'f'>;
extern template struct HexIntegralArgument<char, '0', '1', '2', '3', '4', '5',
                                           '6', '7', '8', '9', 'A', 'B', 'C',
                                           'D', 'E', 'F'>;
extern template struct HexIntegralArgument<wchar_t, L'0', L'1', L'2', L'3',
                                           L'4', L'5', L'6', L'7', L'8', L'9',
                                           L'a', L'b', L'c', L'd', L'e', L'f'>;
extern template struct HexIntegralArgument<wchar_t, L'0', L'1', L'2', L'3',
                                           L'4', L'5', L'6', L'7', L'8', L'9',
                                           L'A', L'B', L'C', L'D', L'E', L'F'>;
extern template struct HexIntegralArgument<char16_t, u'0', u'1', u'2', u'3',
                                           u'4', u'5', u'6', u'7', u'8', u'9',
                                           u'a', u'b', u'c', u'd', u'e', u'f'>;
extern template struct HexIntegralArgument<char16_t, u'0', u'1', u'2', u'3',
                                           u'4', u'5', u'6', u'7', u'8', u'9',
                                           u'A', u'B', u'C', u'D', u'E', u'F'>;
extern template struct HexIntegralArgument<char32_t, U'0', U'1', U'2', U'3',
                                           U'4', U'5', U'6', U'7', U'8', U'9',
                                           U'a', U'b', U'c', U'd', U'e', U'f'>;
extern template struct HexIntegralArgument<char32_t, U'0', U'1', U'2', U'3',
                                           U'4', U'5', U'6', U'7', U'8', U'9',
                                           U'A', U'B', U'C', U'D', U'E', U'F'>;
}  // namespace philwill
