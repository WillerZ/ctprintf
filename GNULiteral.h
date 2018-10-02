#pragma once

#include "Parser.h"

namespace philwill {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wgnu-string-literal-operator-template"
inline namespace literals {
template <typename CharT, CharT... Characters>
[[gnu::flatten]] constexpr auto operator""_printf() {
  return parsed<CharT, Characters...>{};
}
#pragma GCC diagnostic pop
}  // namespace literals
}  // namespace philwill