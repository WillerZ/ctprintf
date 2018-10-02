#pragma once
#include <string>
#include "Span.h"

namespace philwill {

template <typename CharT, typename CharTraits, typename Allocator>
struct StringAccumulatingVisitor {
  using string_type = std::basic_string<CharT, CharTraits, Allocator>;

  explicit StringAccumulatingVisitor(string_type& string) : string_(string) {}

  void operator()(Span<CharT const*> range) {
    string_.append(range.begin(), range.size());
  }

  void reserve(size_t size) {
    string_.reserve(string_.size() + size);
  }

 private:
  string_type& string_;
};

extern template struct StringAccumulatingVisitor<
    typename std::string::value_type, typename std::string::traits_type,
    typename std::string::allocator_type>;
extern template struct StringAccumulatingVisitor<
    typename std::wstring::value_type, typename std::wstring::traits_type,
    typename std::wstring::allocator_type>;
extern template struct StringAccumulatingVisitor<
    typename std::u16string::value_type, typename std::u16string::traits_type,
    typename std::u16string::allocator_type>;
extern template struct StringAccumulatingVisitor<
    typename std::u32string::value_type, typename std::u32string::traits_type,
    typename std::u32string::allocator_type>;
}  // namespace philwill
