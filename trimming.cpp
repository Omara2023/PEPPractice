#include <iostream>
#include <string>

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return " ";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

int main() {
    std::string input = " 66 65 66";
    std::cout << input << "to: " << trim(input) << '.' << std::endl;
}