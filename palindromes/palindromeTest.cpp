#include <iostream>
#include "Palindrome.h"


int main() {
    std::string value = "66 65 65   66 ";
    Palindrome pal = Palindrome(value);
    std::cout << "The value of " << pal.getInput() << " is: " << pal.getConvertedText() << std::endl; // Added space before 'is'
    std::cout << "This " << (pal.isPalindrome() ? "is " : "isn't ") << "a palindrome." << std::endl;
}
