add_executable(LiteralDemo LiteralDemo.cpp)
target_link_libraries(LiteralDemo
    GNULiteral
    MathOperators
    Ostream
    String)

add_executable(WLiteralDemo WLiteralDemo.cpp)
target_link_libraries(WLiteralDemo
    GNULiteral
    MathOperators
    Ostream
    String)

add_executable(RuntimeBenchmarks RuntimeBenchmarks.cpp)
target_link_libraries(RuntimeBenchmarks
    DecimalIntegralArgument
    GNULiteral
    Ostream)

add_executable(StaticBenchmarks StaticBenchmarks.cpp)
target_link_libraries(StaticBenchmarks
    DecimalIntegralArgument
    GNULiteral
    Ostream)

set_target_properties(
        LiteralDemo
        WLiteralDemo
        RuntimeBenchmarks
        StaticBenchmarks
    PROPERTIES
        CXX_EXTENSIONS ON
        CXX_STANDARD 17)

add_executable(ParserDemo ParserDemo.cpp)
target_link_libraries(ParserDemo
    Parser
    MathOperators
    Ostream
    String)

set_target_properties(
        ParserDemo
    PROPERTIES
        CXX_EXTENSIONS OFF
        CXX_STANDARD 17)
