# Simple Java Lexer

A lightweight, efficient, and customizable Java lexical analyzer implemented in C++. This lexer processes Java source code and breaks it down into tokens such as keywords, identifiers, literals, operators, comments, and symbols.

**Note:** This project was developed for **educational purposes** as part of the **Compiler Design** course at **Amirkabir University of Technology (AUT)**.

## Features

- **Java Keywords**: Detects all Java keywords (e.g., `class`, `if`, `while`).
- **Identifiers**: Handles valid Java identifiers, including annotations (e.g., `@Override`).
- **Operators and Symbols**: Recognizes Java operators (`+`, `&&`, `=`) and symbols (`;`, `{`, `}`).
- **Literals**: Supports string, character, numeric (decimal, hexadecimal, binary), and boolean literals.
- **Comments**: Detects single-line (`//`) and multi-line (`/* */`) comments.
- **Whitespace Handling**: Tracks and emits whitespace tokens when required.


## Usage

### Tokenizing Java Source Code

Use the `tokenize` function to analyze a Java source file:

```cpp
#include <iostream>
#include "lexer.h"

int main() {
    std::string sourceCode = R"(
        public class Main {
            public static void main(String[] args) {
                // Hello there!
                System.out.println("Hello, World!");
            }
        }
    )";

    auto tokens = tokenize(sourceCode);

    for (const auto& token : tokens) {
        if (token.type != TokenType::WHITESPACE)
            std::cout << token << std::endl;
    }

    return 0;
}
```

### Output Example

The program will output tokens like:
```cpp
Token{Type: KEYWORD, Position: 1:1, Lexeme: 'public'}
Token{Type: KEYWORD, Position: 1:8, Lexeme: 'class'}
Token{Type: IDENTIFIER, Position: 1:14, Lexeme: 'Main'}
Token{Type: SYMBOL, Position: 1:19, Lexeme: '{'}
...
Token{Type: STRING, Position: 3:38, Lexeme: '"Hello, World!"'}
...
```

## Documentation

### Token Types

| Token Type        | Description                                              |
|-------------------|----------------------------------------------------------|
| `KEYWORD`         | Java keywords (e.g., `"class"`, `"if"`, `"while"`).      |
| `LINE_COMMENT`    | Single-line comments (e.g., `"// comment"`).             |
| `BLOCK_COMMENT`   | Multi-line comments (e.g., `"/* comment */"`).           |
| `STRING`          | String literals (e.g., `"\"hello\""`).                   |
| `CHAR`            | Character literals (e.g., `'\a'`).                      |
| `IDENTIFIER`      | Identifiers (e.g., variable or method names).            |
| `ANNOTATION`      | Java annotations (e.g., `"@Override"`).                  |
| `NUMBER`          | Numeric literals (e.g., `"123"`).                        |
| `HEX_NUMBER`      | Hexadecimal numbers (e.g., `"0x1A3F"`).                  |
| `BINARY_NUMBER`   | Binary numbers (e.g., `"0b1010"`).                       |
| `OPERATOR`        | Operators (e.g., `"+", "==", "&&"`).                     |
| `SYMBOL`          | Symbols (e.g., `";", "{", "}"`).                         |
| `WHITESPACE`       | Spaces, tabs, and newlines.                              |
| `UNKNOWN`          | Unrecognized or malformed tokens.                        |

## Acknowledgments

- Inspired by the process of lexical analysis in modern compilers.
- Java keyword list sourced from [Wikipedia](https://en.wikipedia.org/wiki/List_of_Java_keywords).
