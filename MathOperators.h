#pragma once

#include "FormattingFunction.h"

namespace philwill {
template <typename CharT, typename... Pieces1, typename... Pieces2>
constexpr FormattingFunction<CharT, Pieces1..., Pieces2...> operator+(
    FormattingFunction<CharT, Pieces1...> const&,
    FormattingFunction<CharT, Pieces2...> const&) {
  return {};
}
}  // namespace philwill