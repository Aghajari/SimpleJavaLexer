cmake_minimum_required(VERSION 3.23)
project(SimpleJavaLexer)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        SimpleJavaLexer
        test/test_lexer.cpp
        include/token.h
        src/lexer.cpp
        include/lexer.h
        src/token_matcher.cpp
        include/token_matcher.h
        src/number_helper.cpp
        include/number_helper.h
)
