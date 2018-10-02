#pragma once

#include <string>
#include "Formatted.h"
#include "GetLengthVisitor.h"
#include "StringAccumulatingVisitor.h"

namespace philwill {
template <typename CharT, typename CharTraits, typename Allocator,
          typename... Args>
std::basic_string<CharT, CharTraits, Allocator>& operator<<(
    std::basic_string<CharT, CharTraits, Allocator>& out,
    Formatted<CharT, Args...> const& formatted) {
  StringAccumulatingVisitor<CharT, CharTraits, Allocator> stringAccumulator{
      out};
  GetLengthVisitor<CharT> lengthGetter;
  formatted.accept(lengthGetter);
  stringAccumulator.reserve(lengthGetter.getLength());
  formatted.accept(stringAccumulator);
  return out;
}
}  // namespace philwill