#include "StringArgument.h"

namespace philwill {
template struct StringArgument<char>;
template struct StringArgument<wchar_t>;
template struct StringArgument<char16_t>;
template struct StringArgument<char32_t>;
}  // namespace philwill
