#include "StringAccumulatingVisitor.h"

namespace philwill {
template struct StringAccumulatingVisitor<typename std::string::value_type,
                                          typename std::string::traits_type,
                                          typename std::string::allocator_type>;
template struct StringAccumulatingVisitor<
    typename std::wstring::value_type, typename std::wstring::traits_type,
    typename std::wstring::allocator_type>;
template struct StringAccumulatingVisitor<
    typename std::u16string::value_type, typename std::u16string::traits_type,
    typename std::u16string::allocator_type>;
template struct StringAccumulatingVisitor<
    typename std::u32string::value_type, typename std::u32string::traits_type,
    typename std::u32string::allocator_type>;
}  // namespace philwill