#include "OstreamVisitor.h"

namespace philwill {
template struct OstreamVisitor<typename std::ostream::char_type,
                               typename std::ostream::traits_type>;
template struct OstreamVisitor<typename std::wostream::char_type,
                               typename std::wostream::traits_type>;
}  // namespace philwill
