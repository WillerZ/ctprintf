#pragma once
#include "Span.h"

namespace philwill {

template <typename CharT>
struct GetLengthVisitor {
  void operator()(Span<CharT const*> range) {
    length_ += range.size();
  }

  size_t getLength() const { return length_; }

 private:
  size_t length_{0};
};

}  // namespace philwill
