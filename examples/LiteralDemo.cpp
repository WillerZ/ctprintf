#include <iostream>
#include <typeinfo>
#include "../GNULiteral.h"
#include "../MathOperators.h"
#include "../Ostream.h"
#include "../String.h"

using namespace philwill::literals;
int main() {
  constexpr auto hi = "Hello %s!\n"_printf;
  constexpr auto decimal_formatter = "Decimal: %d\n"_printf;
  constexpr auto lower_hex_formatter = "hex: %x\n"_printf;
  constexpr auto upper_hex_formatter = "HEX: %X\n"_printf;
  constexpr auto char_formatter = "char: '%c'\n"_printf;
  constexpr auto decimal_formatted =
      decimal_formatter(std::numeric_limits<signed long>::min());
  constexpr auto lower_hex_formatted =
      lower_hex_formatter(std::numeric_limits<unsigned long>::max());
  constexpr auto upper_hex_formatted =
      upper_hex_formatter(std::numeric_limits<unsigned long>::max());
  constexpr auto char_formatted = char_formatter('Z');
  constexpr auto hiworld = hi("world");
  std::string str;
  str << hiworld << decimal_formatted;
  std::cout.write(str.data(), str.size());

  std::cout
      << hiworld << decimal_formatted << lower_hex_formatted
      << upper_hex_formatted << char_formatted

      << decimal_formatter(std::numeric_limits<signed long long>::min())
      << decimal_formatter(std::numeric_limits<signed long>::min())
      << decimal_formatter(std::numeric_limits<signed int>::min())
      << decimal_formatter(std::numeric_limits<signed short>::min())
      << decimal_formatter(std::numeric_limits<signed char>::min())
      << decimal_formatter(0LL) << decimal_formatter(0L) << decimal_formatter(0)
      << decimal_formatter(static_cast<short>(0))
      << decimal_formatter(static_cast<signed char>(0))
      << decimal_formatter(std::numeric_limits<signed char>::max())
      << decimal_formatter(std::numeric_limits<signed short>::max())
      << decimal_formatter(std::numeric_limits<signed int>::max())
      << decimal_formatter(std::numeric_limits<signed long>::max())
      << decimal_formatter(std::numeric_limits<signed long long>::max())

      << decimal_formatter(std::numeric_limits<unsigned long long>::min())
      << decimal_formatter(std::numeric_limits<unsigned long>::min())
      << decimal_formatter(std::numeric_limits<unsigned int>::min())
      << decimal_formatter(std::numeric_limits<unsigned short>::min())
      << decimal_formatter(std::numeric_limits<unsigned char>::min())
      << decimal_formatter(std::numeric_limits<unsigned char>::max())
      << decimal_formatter(std::numeric_limits<unsigned short>::max())
      << decimal_formatter(std::numeric_limits<unsigned int>::max())
      << decimal_formatter(std::numeric_limits<unsigned long>::max())
      << decimal_formatter(std::numeric_limits<unsigned long long>::max())

      << decimal_formatter(1UL) << decimal_formatter(12UL)
      << decimal_formatter(123UL) << decimal_formatter(1234UL)
      << decimal_formatter(12345UL) << decimal_formatter(123456UL)
      << decimal_formatter(1234567UL) << decimal_formatter(12345678UL)
      << decimal_formatter(123456789UL) << decimal_formatter(1234567890UL)
      << decimal_formatter(12345678901UL) << decimal_formatter(123456789012UL)
      << decimal_formatter(1234567890123UL)
      << decimal_formatter(12345678901234UL)
      << decimal_formatter(123456789012345UL)
      << decimal_formatter(1234567890123456UL)
      << decimal_formatter(12345678901234567UL)
      << decimal_formatter(123456789012345678UL)
      << decimal_formatter(1234567890123456789UL)
      << decimal_formatter(12345678901234567890UL)

      << lower_hex_formatter(std::numeric_limits<unsigned long long>::min())
      << lower_hex_formatter(std::numeric_limits<unsigned long>::min())
      << lower_hex_formatter(std::numeric_limits<unsigned int>::min())
      << lower_hex_formatter(std::numeric_limits<unsigned short>::min())
      << lower_hex_formatter(std::numeric_limits<unsigned char>::min())
      << lower_hex_formatter(std::numeric_limits<unsigned char>::max())
      << lower_hex_formatter(std::numeric_limits<unsigned short>::max())
      << lower_hex_formatter(std::numeric_limits<unsigned int>::max())
      << lower_hex_formatter(std::numeric_limits<unsigned long>::max())
      << lower_hex_formatter(std::numeric_limits<unsigned long long>::max())
      << lower_hex_formatter(0x1U) << lower_hex_formatter(0x12U)
      << lower_hex_formatter(0x123U) << lower_hex_formatter(0x1234U)
      << lower_hex_formatter(0x12345U) << lower_hex_formatter(0x123456U)
      << lower_hex_formatter(0x1234567U) << lower_hex_formatter(0x12345678U)
      << lower_hex_formatter(0x123456789UL)
      << lower_hex_formatter(0x123456789aUL)
      << lower_hex_formatter(0x123456789abUL)
      << lower_hex_formatter(0x123456789abcUL)
      << lower_hex_formatter(0x123456789abcdUL)
      << lower_hex_formatter(0x123456789abcdeUL)
      << lower_hex_formatter(0x123456789abcdefUL)
      << lower_hex_formatter(0x123456789abcdef0UL)

      << upper_hex_formatter(std::numeric_limits<unsigned long long>::min())
      << upper_hex_formatter(std::numeric_limits<unsigned long>::min())
      << upper_hex_formatter(std::numeric_limits<unsigned int>::min())
      << upper_hex_formatter(std::numeric_limits<unsigned short>::min())
      << upper_hex_formatter(std::numeric_limits<unsigned char>::min())
      << upper_hex_formatter(std::numeric_limits<unsigned char>::max())
      << upper_hex_formatter(std::numeric_limits<unsigned short>::max())
      << upper_hex_formatter(std::numeric_limits<unsigned int>::max())
      << upper_hex_formatter(std::numeric_limits<unsigned long>::max())
      << upper_hex_formatter(std::numeric_limits<unsigned long long>::max());

  // Math operators section
  constexpr auto base = "%c%d%x%X%s"_printf;
  constexpr auto derived1 = base + base;
  constexpr auto expected1 = "%c%d%x%X%s%c%d%x%X%s"_printf;
  static_assert(std::is_same_v<decltype(derived1), decltype(expected1)>,
                "Addition failure (bad result)");
  // Verify that the set of formatting function types under operator+ is a
  // monoid:
  static_assert(
      std::is_same_v<
          std::decay_t<decltype(base)>,
          std::decay_t<decltype(base + philwill::FormattingFunction<char>())>>,
      "Addition failure (post identity)");
  static_assert(
      std::is_same_v<
          std::decay_t<decltype(base)>,
          std::decay_t<decltype(philwill::FormattingFunction<char>() + base)>>,
      "Addition failure (pre identity)");
  static_assert(
      std::is_same_v<decltype(("a"_printf + "b"_printf) + "c"_printf),
                     decltype("a"_printf + ("b"_printf + "c"_printf))>,
      "Addition failure (associativity)");
  return 0;
}