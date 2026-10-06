/**
 * @file main.cpp
 * @brief Main program for FightSim simulating combat between two Characters
 *
 * @author James
 * @date 10/6/2026
 */
#include "Character.h"

#include <iostream>

int main() {
    std::cout << "Welcome to FightSim!" << std::endl;

    // Character has no default constructor, so every object begins with all
    // six required pieces of data. User input is not required for this project
    Character character1("Uglar", "Barbarian", 80, 5, 5, 24);
    Character character2("Zimzizz", "Wizard", 40, 5, 15, 18);

    std::cout << "First Character\n"
            << "---------------\n";

    character1.print(std::cout);
    std::cout << std::endl;

    std::cout << "Second Character\n"
            << "----------------\n";
    character2.print(std::cout);
    std::cout << std::endl;

    // Both conditions are checked at the beginning of every round. The extra
    // check between attacks prevents a defeated character from taking a turn
    while (character1.getHealth() > 0 && character2.getHealth() > 0) {
        character1.attack(character2);
        std::cout << std::endl;

        if (character2.getHealth() > 0) {
            character2.attack(character1);
        }

        std::cout << std::endl;
    }

    // Because damage stops at zero and the defeated character cannot attack,
    // exactly one of these two conditions will be true when the loop ends
    if (character2.getHealth() == 0) {
        std::cout << character1.getNameTheRole() << " wins!" << std::endl;
    } else if (character1.getHealth() == 0) {
        std::cout << character2.getNameTheRole() << " wins!" << std::endl;
    } else {
        std::cout << "Somehow, Palpatine returned" << std::endl;
    }

    return 0;
}
