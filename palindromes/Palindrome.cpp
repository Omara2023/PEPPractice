#include <stdexcept> 
#include "Palindrome.h"

Palindrome::Palindrome(const std::string& t) :
    input(t) {
        convertedText = conversion(t);
    }

std::string Palindrome::conversion(const std::string& t) {
    if (t.length() > 0) {
        std::string output;
        std::string trimmed = trim(t); 
        if (trimmed.empty()) { 
            throw std::invalid_argument("Need a string with actual numbers in it.");
        }

        int start = 0;
        int end = trimmed.find(' ');

        while (end != std::string::npos) {
            std::string segment = trimmed.substr(start, end - start);
            if (!segment.empty()) {
                output += intToAscii(segment); 
            }
            start = end + 1; 
            end = trimmed.find(' ', start); 
        }

        if (start < trimmed.length()) { 
            output += intToAscii(trimmed.substr(start));
        }

        return output; 
    }
    else {
        throw std::invalid_argument("Need a string with actual numbers in it.");
    }
}

std::string Palindrome::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return " ";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

std::string Palindrome::intToAscii(const std::string& asciiValueStr) {
    int asciiValue;
    asciiValue = std::stoi(asciiValueStr);

    if (asciiValue < 0 || asciiValue > 127) {
        throw std::out_of_range("Invalid ASCII value");
    }

    char asciiChar = static_cast<char>(asciiValue);
    return std::string(1, asciiChar);
}

const std::string& Palindrome::getInput() const {
    return this->input; 
}

const std::string& Palindrome::getConvertedText() const {
    return this->convertedText;
}

bool Palindrome::isPalindrome() {
    const std::string& str = this->convertedText;
    if (str.empty()) {
        return true;
    }
    else {
        int start = 0;
        int end = this->convertedText.length() - 1;

        while (start < end) {
            if (str.at(start) != str.at(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}