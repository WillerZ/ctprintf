#include "DecimalIntegralArgument.h"

namespace philwill {
template struct TenDigitIntegralArgument<char, '0', '1', '2', '3', '4', '5',
                                         '6', '7', '8', '9', '-'>;
template struct TenDigitIntegralArgument<wchar_t, L'0', L'1', L'2', L'3', L'4',
                                         L'5', L'6', L'7', L'8', L'9', L'-'>;
template struct TenDigitIntegralArgument<char16_t, u'0', u'1', u'2', u'3', u'4',
                                         u'5', u'6', u'7', u'8', u'9', u'-'>;
template struct TenDigitIntegralArgument<char32_t, U'0', U'1', U'2', U'3', U'4',
                                         U'5', U'6', U'7', U'8', U'9', U'-'>;
}  // namespace philwill
