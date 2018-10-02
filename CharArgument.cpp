#include "CharArgument.h"

namespace philwill {
template struct CharArgument<char>;
template struct CharArgument<wchar_t>;
template struct CharArgument<char16_t>;
template struct CharArgument<char32_t>;
}  // namespace philwill