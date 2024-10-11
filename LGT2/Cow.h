#ifndef COW_H
#define COW_H

#include <string>

class Cow {
private:
    std::string name;
    int age;
    std::string breed;

public:
    // Constructor
    Cow(const std::string& cowName, int cowAge, const std::string& cowBreed);

    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getBreed() const;

    // Setters
    void setName(const std::string& cowName);
    void setAge(int cowAge);
    void setBreed(const std::string& cowBreed);

    // Display information about the cow
    void displayInfo() const;
};

#endif
