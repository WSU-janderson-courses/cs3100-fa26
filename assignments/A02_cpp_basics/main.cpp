/**
 * @file main.cpp
 * @brief Solution for coding assignment "C++ Basics"
 */

#include <iostream>
#include <string> // because we use std::string, we should include the header for it

// 6. Functions
bool is_even(int value) {
    // check if value is even
    if (value % 2 == 0) {
        return true;
    }

    // if value isn't even, the only other option is it is odd
    return false;
}

// 1. Create main()
int main() {
// 2. Output
    std::cout << "A02: C++ Basics" << std::endl << std::endl;

// 3. Variables
    int value = 5;
    double height = 3.14;
    std::string name = "James"; // string is from the C++ standard library, so we need std:: before it

    std::cout << "value = " << value << std::endl;
    std::cout << "height = " << height << std::endl;
    std::cout << "name = " << name << std::endl;

    std::cout << std::endl;

// 4. Conditionals
    bool result = is_even(value);

    std::cout << std::boolalpha; // this isn't necessary, but it lets us print bool as `true` and `false`
                                // instead of `1` and `0`
    std::cout << value << " is even: " << result << std::endl << std::endl;

// 5. Loops
    // this is just one way to print 1..value
    for (int i = 0; i < value; i++) {
        std::cout << i + 1 << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
