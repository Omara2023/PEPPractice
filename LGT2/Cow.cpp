#include "Cow.h"

int main() {
    // Create a Cow object
    Cow myCow("Bessie", 4, "Holstein");

    // Display cow information
    myCow.displayInfo();

    // Update cow details
    myCow.setAge(5);
    myCow.setName("Daisy");

    // Display updated information
    myCow.displayInfo();

    return 0;
}
