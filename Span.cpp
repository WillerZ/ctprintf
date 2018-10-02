#include "Span.h"

namespace philwill {
template struct Span <char const*>;
template struct Span <wchar_t const*>;
template struct Span <char16_t const*>;
template struct Span <char32_t const*>;
}