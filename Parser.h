#pragma once

#include "CharArgument.h"
#include "DecimalIntegralArgument.h"
#include "FormattingFunction.h"
#include "HexIntegralArgument.h"
#include "InlineLiteralString.h"
#include "StringArgument.h"

#include <cstddef>
#include <utility>

namespace philwill {
namespace parser_detail {
struct expect_any {};
struct expect_format {};
struct string_format {};
struct decimal_format {};
struct upper_hex_format {};
struct lower_hex_format {};
struct char_format {};
template <typename...>
struct Sequence {};

template <typename CharT>
struct Parser {
  template <CharT>
  struct literal {};

  template <typename, typename, CharT...>
  struct parse {};

  template <typename, typename>
  struct compact {};

  constexpr static CharT FORMAT_BEGIN{'%'};
  constexpr static CharT FORMAT_STRING{'s'};
  constexpr static CharT FORMAT_DECIMAL{'d'};
  constexpr static CharT FORMAT_CHAR{'c'};
  constexpr static CharT FORMAT_UPPER_HEX{'X'};
  constexpr static CharT FORMAT_LOWER_HEX{'x'};

  template <typename... List>
  struct parse<expect_any, Sequence<List...>> {
    using type = typename compact<Sequence<List...>, Sequence<>>::type;
  };

  template <CharT... Characters, typename... List>
  struct parse<expect_any, Sequence<List...>, FORMAT_BEGIN, Characters...> {
    using type =
        typename parse<expect_format, Sequence<List...>, Characters...>::type;
  };

  template <CharT Character, CharT... Characters, typename... List>
  struct parse<expect_any, Sequence<List...>, Character, Characters...> {
    using type =
        typename parse<expect_any, Sequence<literal<Character>, List...>,
                       Characters...>::type;
  };

  template <CharT... Characters, typename... List>
  struct parse<expect_format, Sequence<List...>, FORMAT_STRING, Characters...> {
    using type = typename parse<expect_any, Sequence<string_format, List...>,
                                Characters...>::type;
  };

  template <CharT... Characters, typename... List>
  struct parse<expect_format, Sequence<List...>, FORMAT_DECIMAL,
               Characters...> {
    using type = typename parse<expect_any, Sequence<decimal_format, List...>,
                                Characters...>::type;
  };

  template <CharT... Characters, typename... List>
  struct parse<expect_format, Sequence<List...>, FORMAT_CHAR, Characters...> {
    using type = typename parse<expect_any, Sequence<char_format, List...>,
                                Characters...>::type;
  };

  template <CharT... Characters, typename... List>
  struct parse<expect_format, Sequence<List...>, FORMAT_UPPER_HEX,
               Characters...> {
    using type = typename parse<expect_any, Sequence<upper_hex_format, List...>,
                                Characters...>::type;
  };

  template <CharT... Characters, typename... List>
  struct parse<expect_format, Sequence<List...>, FORMAT_LOWER_HEX,
               Characters...> {
    using type = typename parse<expect_any, Sequence<lower_hex_format, List...>,
                                Characters...>::type;
  };

  template <typename... List2>
  struct compact<Sequence<>, Sequence<List2...>> {
    using type = FormattingFunction<CharT, List2...>;
  };

  template <typename... List, CharT Character, CharT... Characters,
            typename... List2>
  struct compact<
      Sequence<literal<Character>, List...>,
      Sequence<InlineLiteralString<CharT, Characters...>, List2...>> {
    using type = typename compact<
        Sequence<List...>,
        Sequence<InlineLiteralString<CharT, Character, Characters...>,
                 List2...>>::type;
  };

  template <typename... List, typename... List2>
  struct compact<Sequence<decimal_format, List...>, Sequence<List2...>> {
    using type = typename compact<
        Sequence<List...>,
        Sequence<DecimalIntegralArgument<CharT>, List2...>>::type;
  };

  template <typename... List, typename... List2>
  struct compact<Sequence<lower_hex_format, List...>, Sequence<List2...>> {
    using type = typename compact<
        Sequence<List...>,
        Sequence<LowerHexIntegralArgument<CharT>, List2...>>::type;
  };

  template <typename... List, typename... List2>
  struct compact<Sequence<upper_hex_format, List...>, Sequence<List2...>> {
    using type = typename compact<
        Sequence<List...>,
        Sequence<UpperHexIntegralArgument<CharT>, List2...>>::type;
  };

  template <typename... List, typename... List2>
  struct compact<Sequence<char_format, List...>, Sequence<List2...>> {
    using type = typename compact<Sequence<List...>,
                                  Sequence<CharArgument<CharT>, List2...>>::type;
  };

  template <typename... List, typename... List2>
  struct compact<Sequence<string_format, List...>, Sequence<List2...>> {
    using type =
        typename compact<Sequence<List...>,
                         Sequence<StringArgument<CharT>, List2...>>::type;
  };

  template <CharT Character, typename... List, typename... List2>
  struct compact<Sequence<Parser::literal<Character>, List...>,
                 Sequence<List2...>> {
    using type = typename compact<
        Sequence<List...>,
        Sequence<InlineLiteralString<CharT, Character>, List2...>>::type;
  };
};
}  // namespace parser_detail

template <typename CharT, CharT... Characters>
using parsed = typename parser_detail::Parser<CharT>::template parse<
    parser_detail::expect_any, parser_detail::Sequence<>, Characters...>::type;
}  // namespace philwill