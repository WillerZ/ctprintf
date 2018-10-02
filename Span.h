#pragma once
#include <utility>
#include <iterator>
#include <functional>

namespace philwill {
template <typename Iter>
struct Span {
  constexpr Span(Iter begin, Iter end) : begin_(begin), end_(end) {}
  template <typename Container>
  constexpr Span(Container&& container)
      : begin_(std::begin(container)), end_(std::end(container)) {}
  constexpr auto size() const { return end_ - begin_; }
  constexpr auto begin() { return begin_; }
  constexpr auto end() { return end_; }
  constexpr auto begin() const { return begin_; }
  constexpr auto end() const { return end_; }
  constexpr auto cbegin() const { return begin_; }
  constexpr auto cend() const { return end_; }

 private:
  Iter begin_;
  Iter end_;
};

template <typename Iter>
constexpr bool operator==(Span<Iter> const& lhs, Span<Iter> const& rhs) {
  auto lIter = lhs.begin();
  auto rIter = rhs.begin();
  auto const& equal = std::equal_to<>();
  while (lIter != lhs.end() && rIter != rhs.end()) {
    if (!equal(*lIter, *rIter)) {
      return false;
    }
    ++lIter; ++rIter;
  }
  if (lIter != lhs.end() || rIter != rhs.end()) {
    return false;
  }
  return true;
}

template <typename Iter>
constexpr bool operator!=(Span<Iter> const& lhs, Span<Iter> const& rhs) {
  return !operator==(lhs, rhs);
}

extern template struct Span <char const*>;
extern template struct Span <wchar_t const*>;
extern template struct Span <char16_t const*>;
extern template struct Span <char32_t const*>;
}  // namespace philwill