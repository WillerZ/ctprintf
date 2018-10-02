// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once
#include "StringArgument.h"

namespace philwill {

template <typename CharT, CharT... Characters>
struct InlineLiteralString : StringArgument<CharT> {
  using char_type = CharT;
  constexpr InlineLiteralString()
      : StringArgument<CharT>(
            std::basic_string_view<CharT>(buffer_, sizeof...(Characters))) {}

 private:
  constexpr static CharT buffer_[sizeof...(Characters)]{Characters...};
};

}  // namespace philwill
