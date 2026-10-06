/**
 * @file Character.cpp
 * @brief Class definitions for Character
 */
#include "Character.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>

Character::Character(std::string name,
                     std::string role,
                     int hitPoints,
                     int attackBonus,
                     int bonusDamage,
                     int armorClass)
// A member initializer list constructs each data member with its starting
// value before the constructor body begins
    : name(name),
      role(role),
      hitPoints(hitPoints),
      attackBonus(attackBonus),
      bonusDamage(bonusDamage),
      armorClass(armorClass) {
}

// os << firstName << " " << lastName << " " <<...
void Character::print(std::ostream &os) const {
    // Use `os` rather than `std::cout` so the caller chooses the destination
    os << this->getNameTheRole() << std::endl;
    os << "Hit Points:   " << this->getHealth() << std::endl;
    os << "Attack Bonus: " << this->attackBonus << std::endl;
    os << "Damage Bonus: " << this->bonusDamage << std::endl;
    os << "Armor Class:  " << this->armorClass << std::endl;
}

// Helper function for printing out attack details
void Character::print_attack(std::ostream &os, const std::string &type, int v1, int v2, int result) const {
    os << type << " roll: "
            << v1 << " + " << v2
            << " = " << result;
}

void Character::attack(Character &otherCharacter) const {
    std::cout << this->getNameTheRole() << " attacks "
            << otherCharacter.getNameTheRole() << std::endl;

    // These objects are initialized only once and reused on every attack.
    // The generator maintains the pseudorandom sequence, while each
    // distribution maps generated values to the range for one of the die
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> d_20_distribution(1, 20);
    static std::uniform_int_distribution<int> d_10_distribution(1, 10);

    const int d_20 = d_20_distribution(gen);
    const int total_attack_roll = this->attackBonus + d_20;

    print_attack(std::cout, "Attack", d_20, this->attackBonus, total_attack_roll);

    // A Character member function may access private data belonging to any
    // Character object, not only the object on which the method was called
    if (total_attack_roll < otherCharacter.armorClass) {
        std::cout << " MISS!" << std::endl;
        return;
    }

    std::cout << " HIT!" << std::endl;

    // Damage is only rolled after an attack hits.
    const int d_10 = d_10_distribution(gen);
    const int total_damage_roll = d_10 + this->bonusDamage;

    print_attack(std::cout, "Damage", d_10, this->bonusDamage, total_damage_roll);
    std::cout << std::endl;

    // `otherCharacter` is a reference, so this changes the original defender.
    otherCharacter.damage(total_damage_roll);

    std::cout << otherCharacter.getName() << " has "
            << otherCharacter.getHealth() << " hit points remaining" << std::endl;
}

void Character::damage(int damageDone) {
    const int new_hitpoints = this->hitPoints - damageDone;

    // The conditional expression prevents health from becoming negative
    this->hitPoints = new_hitpoints < 0 ? 0 : new_hitpoints;
}

int Character::getHealth() const {
    return this->hitPoints;
}

std::string Character::getName() const {
    return this->name;
}

std::string Character::getRole() const {
    return this->role;
}

// OPTIONAL: you can use this to get the character's name/role all in one
// e.g. if the name is Uglar and the role is Warrior, this could return
// "Uglar the Warrior"
std::string Character::getNameTheRole() const {
    std::stringstream result;
    result << this->getName() << " the " << this->getRole();
    return result.str();
}
