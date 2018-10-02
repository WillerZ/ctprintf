cmake_minimum_required(VERSION 3.12)
project(CTPRINTF)

add_library(Span "")
target_sources(Span
    PRIVATE
        Span.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/Span.h)

add_library(CharArgument "")
target_sources(CharArgument
    PRIVATE
        CharArgument.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/CharArgument.h)
target_link_libraries(CharArgument INTERFACE Span)

add_library(StringArgument "")
target_sources(StringArgument
    PRIVATE
        StringArgument.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/StringArgument.h)
target_link_libraries(StringArgument INTERFACE Span)

add_library(DecimalIntegralArgument "")
target_sources(DecimalIntegralArgument
    PRIVATE
        DecimalIntegralArgument.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/DecimalIntegralArgument.h)
target_link_libraries(DecimalIntegralArgument INTERFACE Span)

add_library(HexIntegralArgument "")
target_sources(HexIntegralArgument
    PRIVATE
        HexIntegralArgument.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/HexIntegralArgument.h)
target_link_libraries(HexIntegralArgument INTERFACE Span)

add_library(StringAccumulatingVisitor "")
target_sources(StringAccumulatingVisitor
    PRIVATE
        StringAccumulatingVisitor.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/StringAccumulatingVisitor.h)
target_link_libraries(StringAccumulatingVisitor INTERFACE Span)

add_library(OstreamVisitor "")
target_sources(OstreamVisitor
    PRIVATE
        OstreamVisitor.cpp
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/OstreamVisitor.h)
target_link_libraries(OstreamVisitor INTERFACE Span)

add_library(Formatted INTERFACE)
target_sources(Formatted
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/Formatted.h)
target_link_libraries(Formatted INTERFACE
    InlineLiteralString
    StringArgument
    DecimalIntegralArgument
    HexIntegralArgument
    CharArgument
    )

add_library(FormattingFunction INTERFACE)
target_sources(FormattingFunction
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/FormattingFunction.h)
target_link_libraries(FormattingFunction INTERFACE Formatted)

add_library(GetLengthVisitor INTERFACE)
target_sources(GetLengthVisitor
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/GetLengthVisitor.h)
target_link_libraries(GetLengthVisitor INTERFACE Span)

add_library(InlineLiteralString INTERFACE)
target_sources(InlineLiteralString
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/InlineLiteralString.h)
target_link_libraries(InlineLiteralString INTERFACE StringArgument)

add_library(MathOperators INTERFACE)
target_sources(MathOperators
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/MathOperators.h)
target_link_libraries(MathOperators INTERFACE FormattingFunction)

add_library(Ostream INTERFACE)
target_sources(Ostream
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/Ostream.h)
target_link_libraries(Ostream INTERFACE OstreamVisitor)

add_library(Parser INTERFACE)
target_sources(Parser
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/Parser.h)
target_link_libraries(Parser INTERFACE
    CharArgument
    DecimalIntegralArgument
    FormattingFunction
    HexIntegralArgument
    InlineLiteralString
    StringArgument
    )


add_library(String INTERFACE)
target_sources(String
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/String.h)
target_link_libraries(String INTERFACE
    Formatted
    GetLengthVisitor
    StringAccumulatingVisitor
    )

add_library(GNULiteral INTERFACE)
target_sources(GNULiteral
    INTERFACE
        ${CTPRINTF_SOURCE_DIR}/GNULiteral.h)

set_target_properties(
        Span
        CharArgument
        StringArgument
        DecimalIntegralArgument
        HexIntegralArgument
        StringAccumulatingVisitor
        OstreamVisitor
    PROPERTIES
        CXX_EXTENSIONS OFF
        CXX_STANDARD 17)

add_subdirectory(examples)

enable_testing()
add_subdirectory(tests)