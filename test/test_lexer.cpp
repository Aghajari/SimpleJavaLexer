#include <iostream>
#include "assert_lexer.h"
#include "../include/lexer.h"

int main() {
    test_lexer();
    printf("-------\n");

    std::string source_code = R"(
        package test;
        import java;

        // Comment here
        public class Test {
            /* This is multiline
                Comment Here */

            @AnnotationTest
            public static void main(){
                double a = 3_1.1___________141_592_653;
                float b = 20.0f;
                int c = 0b1_______1;
                int d = 0xAF;
                if(a>8 && b > a) {
                    a = b * 2;
                }
                System.out.println("Hello\"World\"");
            }
        }
    )";

    auto tokens = tokenize(source_code);
    for (const auto &token: tokens) {
        if (token.type == TokenType::WHITESPACE) continue;

        std::cout << token << std::endl;
    }
    return 0;
}
