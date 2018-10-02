#pragma once
#include <utility>
#include "Span.h"

namespace philwill {

template <typename CharT>
struct CharArgument {
  using char_type = CharT;
  constexpr CharArgument(CharT character) : character_(character) {}

  template <typename Visitor>
  constexpr auto accept(Visitor&& visitor) const {
    return std::forward<Visitor>(visitor)(
        Span<CharT const*>(&character_, &character_ + 1));
  }

  constexpr std::size_t size() const { return std::size_t(1); }

 private:
  CharT character_;
};

extern template struct CharArgument<char>;
extern template struct CharArgument<wchar_t>;
extern template struct CharArgument<char16_t>;
extern template struct CharArgument<char32_t>;

}  // namespace philwill
