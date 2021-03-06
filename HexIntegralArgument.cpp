#include "HexIntegralArgument.h"

namespace philwill {
template struct HexIntegralArgument<char, '0', '1', '2', '3', '4', '5', '6',
                                    '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
                                    'f'>;
template struct HexIntegralArgument<char, '0', '1', '2', '3', '4', '5', '6',
                                    '7', '8', '9', 'A', 'B', 'C', 'D', 'E',
                                    'F'>;
template struct HexIntegralArgument<wchar_t, L'0', L'1', L'2', L'3', L'4', L'5',
                                    L'6', L'7', L'8', L'9', L'a', L'b', L'c',
                                    L'd', L'e', L'f'>;
template struct HexIntegralArgument<wchar_t, L'0', L'1', L'2', L'3', L'4', L'5',
                                    L'6', L'7', L'8', L'9', L'A', L'B', L'C',
                                    L'D', L'E', L'F'>;
template struct HexIntegralArgument<char16_t, u'0', u'1', u'2', u'3', u'4',
                                    u'5', u'6', u'7', u'8', u'9', u'a', u'b',
                                    u'c', u'd', u'e', u'f'>;
template struct HexIntegralArgument<char16_t, u'0', u'1', u'2', u'3', u'4',
                                    u'5', u'6', u'7', u'8', u'9', u'A', u'B',
                                    u'C', u'D', u'E', u'F'>;
template struct HexIntegralArgument<char32_t, U'0', U'1', U'2', U'3', U'4',
                                    U'5', U'6', U'7', U'8', U'9', U'a', U'b',
                                    U'c', U'd', U'e', U'f'>;
template struct HexIntegralArgument<char32_t, U'0', U'1', U'2', U'3', U'4',
                                    U'5', U'6', U'7', U'8', U'9', U'A', U'B',
                                    U'C', U'D', U'E', U'F'>;
}  // namespace philwill