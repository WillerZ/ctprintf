#pragma once

#include <utility>
#include "CharArgument.h"
#include "DecimalIntegralArgument.h"
#include "HexIntegralArgument.h"
#include "InlineLiteralString.h"
#include "StringArgument.h"

namespace philwill {
template <typename CharT, typename... Pieces>
struct Formatted;

template <typename CharT>
struct Formatted<CharT> {
  constexpr Formatted() = default;
  template <typename Visitor>
  constexpr void accept(Visitor&& visitor) const {}
};

template <typename CharT, CharT... Characters, typename... Pieces>
struct Formatted<CharT, InlineLiteralString<CharT, Characters...>, Pieces...>
    : Formatted<CharT, Pieces...> {
 private:
  using Base = Formatted<CharT, Pieces...>;

 private:
  InlineLiteralString<CharT, Characters...> piece_;

 public:
  using Base::Base;
  template <typename Visitor>
  constexpr void accept(Visitor&& visitor) const {
    piece_.accept(std::forward<Visitor>(visitor));
    this->Base::accept(std::forward<Visitor>(visitor));
  }
};

template <typename CharT, typename... Pieces>
struct Formatted<CharT, StringArgument<CharT>, Pieces...>
    : Formatted<CharT, Pieces...> {
 private:
  using Base = Formatted<CharT, Pieces...>;

 private:
  StringArgument<CharT> piece_;

 public:
  template <typename CharTraits, typename... Args>
  constexpr Formatted(std::basic_string_view<CharT, CharTraits> string,
                      Args&&... args)
      : Base(std::forward<Args>(args)...), piece_(string) {}

  template <typename... Args>
  constexpr Formatted(CharT const* string, Args&&... args)
      : Formatted(std::basic_string_view<CharT>(string),
                  std::forward<Args>(args)...) {}

  template <typename Visitor>
  constexpr void accept(Visitor&& visitor) const {
    piece_.accept(std::forward<Visitor>(visitor));
    this->Base::accept(std::forward<Visitor>(visitor));
  }
};

template <typename CharT, typename... Pieces>
struct Formatted<CharT, DecimalIntegralArgument<CharT>, Pieces...>
    : Formatted<CharT, Pieces...> {
 private:
  using Base = Formatted<CharT, Pieces...>;

 private:
  DecimalIntegralArgument<CharT> piece_;

 public:
  template <typename Arg, typename... Args>
  constexpr Formatted(Arg&& number, Args&&... args)
      : Base(std::forward<Args>(args)...), piece_(std::forward<Arg>(number)) {}
  template <typename Visitor>
  constexpr void accept(Visitor&& visitor) const {
    piece_.accept(std::forward<Visitor>(visitor));
    this->Base::accept(std::forward<Visitor>(visitor));
  }
};

template <typename CharT, typename... Pieces>
struct Formatted<CharT, CharArgument<CharT>, Pieces...>
    : Formatted<CharT, Pieces...> {
 private:
  using Base = Formatted<CharT, Pieces...>;

 private:
  CharArgument<CharT> piece_;

 public:
  template <typename CType, typename... Args>
  constexpr Formatted(CType&& Character, Args&&... args)
      : Base(std::forward<Args>(args)...),
        piece_(std::forward<CType>(Character)) {}
  template <typename Visitor>
  constexpr void accept(Visitor&& visitor) const {
    piece_.accept(std::forward<Visitor>(visitor));
    this->Base::accept(std::forward<Visitor>(visitor));
  }
};

template <typename CharT, CharT... Digits, typename... Pieces>
struct Formatted<CharT, HexIntegralArgument<CharT, Digits...>, Pieces...>
    : Formatted<CharT, Pieces...> {
 private:
  using Base = Formatted<CharT, Pieces...>;

 private:
  HexIntegralArgument<CharT, Digits...> piece_;

 public:
  template <typename Arg, typename... Args>
  constexpr Formatted(Arg&& number, Args&&... args)
      : Base(std::forward<Args>(args)...), piece_(std::forward<Arg>(number)) {}
  template <typename Visitor>
  constexpr void accept(Visitor&& visitor) const {
    piece_.accept(std::forward<Visitor>(visitor));
    this->Base::accept(std::forward<Visitor>(visitor));
  }
};
}  // namespace philwill