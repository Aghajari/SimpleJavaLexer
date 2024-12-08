#ifndef SIMPLEJAVALEXER_NUMBER_HELPER_H
#define SIMPLEJAVALEXER_NUMBER_HELPER_H

#include <iostream>

/**
 * Checks if a character is a decimal digit (0-9).
 * @param c - The character to check.
 * @return true if the character is a digit; false otherwise.
 */
bool isNumber(char c);

/**
 * Checks if a character is valid in a binary or hexadecimal number.
 * @param c - The character to check.
 * @param binary - true to check for binary digits (0 or 1), false for hexadecimal digits (0-9, a-f, A-F).
 * @return true if the character is valid for the specified number type; false otherwise.
 */
bool isHexOrBinaryNumber(char c, bool binary);

/**
 * Checks if a character is a valid type identifier for a number in Java.
 * Type identifiers include 'f', 'F', 'd', 'D', and optionally 'l', 'L' (for long numbers).
 * @param c - The character to check.
 * @param supportsLong - true if 'l' and 'L' should be considered valid identifiers.
 * @return true if the character is a valid number type identifier; false otherwise.
 */
bool isNumberTypeIdentifier(char c, bool supportsLong);

/**
 * Determines if two characters could start a number.
 * Examples:
 * - '1' or '3' are valid starters.
 * - '.' is valid only if the next character is a digit.
 * @param c - The current character.
 * @param next_c - The next character in the sequence.
 * @return true if the characters can start a number; false otherwise.
 */
bool isNumberStarter(char c, char next_c);

/**
 * Checks if a character is valid within the range of a binary, hexadecimal, or decimal number.
 * @param c - The character to check.
 * @param isBinary - true if checking for a binary number.
 * @param isHex - true if checking for a hexadecimal number.
 * @return true if the character is valid in the specified range; false otherwise.
 */
bool isNumberInRange(char c, bool isBinary, bool isHex);

/**
 * Validates the use of an underscore in a number.
 * In Java, underscores are allowed in numbers but cannot:
 * - Appear at the start or end of the number.
 * - Appear next to a decimal point.
 * - Be consecutive without digits in between.
 *
 * This function ensures that the underscore at the given index is valid in the context of the number.
 * @param source - The string containing the number.
 * @param index - The position of the underscore in the string.
 * @param isBinary - true if the number is binary.
 * @param isHex - true if the number is hexadecimal.
 * @return true if the underscore is valid in the number; false otherwise.
 */
bool isValidUnderscoreInNumber(const std::string &source, int index, bool isBinary, bool isHex);

#endif //SIMPLEJAVALEXER_NUMBER_HELPER_H
