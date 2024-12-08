#include "../include/number_helper.h"

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

bool isHexOrBinaryNumber(char c, bool binary) {
    if (binary) {
        return c == '0' || c == '1';
    } else {
        return isNumber(c) ||
               (c >= 'a' && c <= 'f') ||
               (c >= 'A' && c <= 'F');
    }
}

bool isNumberTypeIdentifier(char c, bool supportsLong) {
    return c == 'f' || c == 'F' ||
           c == 'd' || c == 'D' ||
           (supportsLong && (c == 'l' || c == 'L'));
}

bool isNumberStarter(char c, char next_c) {
    return isNumber(c) || (c == '.' && isNumber(next_c));
}

bool isNumberInRange(char c, bool isBinary, bool isHex) {
    if (isBinary || isHex) {
        return isHexOrBinaryNumber(c, isBinary);
    } else {
        return isNumber(c);
    }
}

bool isValidUnderscoreInNumber(const std::string &source, int index, bool isBinary, bool isHex) {
    if (source[index] != '_') {
        return false;
    }
    int prevIndex = index - 1;
    while (prevIndex >= 0) {
        if (source[prevIndex] == '_') {
            prevIndex--;
        } else if (isNumberInRange(source[prevIndex], isBinary, isHex)) {
            break;
        } else {
            return false;
        }
    }
    int nextIndex = index + 1;
    while (nextIndex < source.length()) {
        if (source[nextIndex] == '_') {
            nextIndex++;
        } else {
            return isNumberInRange(source[nextIndex], isBinary, isHex);
        }
    }
    return false;
}