add_executable(SpanTest SpanTest.cpp)
target_link_libraries(SpanTest
    Span)

add_executable(CharArgumentTest CharArgumentTest.cpp)
target_link_libraries(CharArgumentTest
    CharArgument)

add_executable(StringArgumentTest StringArgumentTest.cpp)
target_link_libraries(StringArgumentTest
    StringArgument)

add_executable(DecimalIntegralArgumentTest DecimalIntegralArgumentTest.cpp)
target_link_libraries(DecimalIntegralArgumentTest
    DecimalIntegralArgument)

add_executable(LowerHexIntegralArgumentTest LowerHexIntegralArgumentTest.cpp)
target_link_libraries(LowerHexIntegralArgumentTest
    HexIntegralArgument)

add_executable(UpperHexIntegralArgumentTest UpperHexIntegralArgumentTest.cpp)
target_link_libraries(UpperHexIntegralArgumentTest
    HexIntegralArgument)

add_executable(StringAccumulatingVisitorTest StringAccumulatingVisitorTest.cpp)
target_link_libraries(StringAccumulatingVisitorTest
    StringAccumulatingVisitor)

add_executable(OstreamVisitorTest OstreamVisitorTest.cpp)
target_link_libraries(OstreamVisitorTest
    OstreamVisitor)

set_target_properties(
        SpanTest
        CharArgumentTest
        StringArgumentTest
        DecimalIntegralArgumentTest
        LowerHexIntegralArgumentTest
        UpperHexIntegralArgumentTest
        StringAccumulatingVisitorTest
        OstreamVisitorTest
    PROPERTIES
        CXX_EXTENSIONS OFF
        CXX_STANDARD 17)

add_test(NAME SpanTest COMMAND SpanTest)
add_test(NAME CharArgumentTest COMMAND CharArgumentTest)
add_test(NAME StringArgumentTest COMMAND StringArgumentTest)
add_test(NAME DecimalIntegralArgumentTest COMMAND DecimalIntegralArgumentTest)
add_test(NAME LowerHexIntegralArgumentTest COMMAND LowerHexIntegralArgumentTest)
add_test(NAME UpperHexIntegralArgumentTest COMMAND UpperHexIntegralArgumentTest)
add_test(NAME StringAccumulatingVisitorTest COMMAND StringAccumulatingVisitorTest)
add_test(NAME OstreamVisitorTest COMMAND OstreamVisitorTest)