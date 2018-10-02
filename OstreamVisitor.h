#pragma once
#include <ostream>
#include "Span.h"

namespace philwill {

template <typename CharT, typename CharTraits>
struct OstreamVisitor {
  using ostream_type = std::basic_ostream<CharT, CharTraits>;

  explicit OstreamVisitor(ostream_type& ostream) : ostream_(ostream) {}

  void operator()(Span<CharT const*> range) {
    ostream_.write(range.begin(), range.size());
  }

 private:
  ostream_type& ostream_;
};

extern template struct OstreamVisitor<
    typename std::ostream::char_type, typename std::ostream::traits_type>;
extern template struct OstreamVisitor<
    typename std::wostream::char_type, typename std::wostream::traits_type>;
}  // namespace philwill
