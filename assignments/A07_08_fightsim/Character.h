/**
 * @file Character.h
 * @brief Class declaration for Character
 *
 * @author james
 * @date 10/6/2026
 */
#pragma once

#include <string>

// A Character represents one combatant in the simulation. Its data is private,
// so code outside the class must interact with it through the public methods.
class Character {
public:
    // There is intentionally no default constructor. Every Character must be
    // create with a name, role, and compete set of combat statistics.
    Character(std::string name,
              std::string role,
              int hitPoints,
              int attackBonus,
              int bonusDamage,
              int armorClass);

    // Writing to a supplied stream allows the function to work with
    // std::cout, a file stream, or a string string used by a test.
    void print(std::ostream& os) const;

    // The reference allows this function to change the original defending
    // Character. The trailing `const` means the attacker is not changed
    void attack(Character& otherCharacter) const;

    // Reduce this character's health, stopping at zero
    void damage(int damageDone);

    // Accessor methods provide read-only access to selected private data
    int getHealth() const;
    std::string getName() const;
    std::string getRole() const;
    std::string getNameTheRole() const;

private:
    std::string name;
    std::string role;
    int hitPoints{0};
    int attackBonus{0};
    int bonusDamage{0};
    int armorClass{0};

    // Shared formatting helper used for both attack and damage rolls
    void print_attack(std::ostream& os, const std::string& type, int v1, int v2, int result) const;
};
