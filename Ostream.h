#pragma once

#include <ostream>
#include "Formatted.h"
#include "OstreamVisitor.h"

namespace philwill {
template <typename CharT, typename CharTraits, typename... Args>
std::basic_ostream<CharT, CharTraits>& operator<<(
    std::basic_ostream<CharT, CharTraits>& out,
    Formatted<CharT, Args...> const& formatted) {
  formatted.accept(OstreamVisitor<CharT, CharTraits>(out));
  return out;
}
}  // namespace philwill