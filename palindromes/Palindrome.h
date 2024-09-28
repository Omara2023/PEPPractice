#include <string>

class Palindrome {
    private:
        std::string input;
        std::string convertedText;

        std::string conversion(const std::string& t);
        std::string intToAscii(const std::string& asciiValueStr);
        std::string trim(const std::string& str);

    public:
        Palindrome(const std::string& t);
        const std::string& getInput() const;
        const std::string& getConvertedText() const;
        bool isPalindrome();
} ;
    
