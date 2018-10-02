#pragma once

#include <utility>
#include "Formatted.h"

namespace philwill {
template <typename CharT, typename... Pieces>
struct FormattingFunction {
  template <typename... Args>
  constexpr Formatted<CharT, Pieces...> operator()(Args&&... args) const {
    return {std::forward<Args>(args)...};
  }
};
}  // namespace philwill