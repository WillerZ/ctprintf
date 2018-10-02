#pragma once
#include <utility>
#include <string_view>
#include "Span.h"

namespace philwill {

template <typename CharT>
struct StringArgument {
  using char_type = CharT;
  template<typename CharTraits>
  constexpr StringArgument(std::basic_string_view<CharT, CharTraits> string) : string_(string) {}

  constexpr StringArgument(CharT const* string) : StringArgument(std::basic_string_view<CharT>(string)) {}

  template <typename Visitor>
  constexpr auto accept(Visitor&& visitor) const {
    return std::forward<Visitor>(visitor)(string_);
  }
  constexpr std::size_t size() const { return string_.size(); }

 private:
  Span<CharT const*> string_;
};

extern template struct StringArgument<char>;
extern template struct StringArgument<wchar_t>;
extern template struct StringArgument<char16_t>;
extern template struct StringArgument<char32_t>;

}  // namespace philwill
