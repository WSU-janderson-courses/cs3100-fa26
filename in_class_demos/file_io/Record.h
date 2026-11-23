#pragma once

#include <iosfwd>
#include <string>

// The four fields are fixed so that the provided file format, CLI,
// and instructor tests all use the same record schema.
struct Record {
    std::string id;       // Unique, nonempty map key
    std::string name;     // NPC name
    std::string category; // NPC class or role
    int value = 0;        // NPC level
};

// Provided: serialize/parse the four fields as
// "id" "name" "category" integer
// std::quoted supports spaces and escaped quotation marks in strings.
std::ostream& operator<<(std::ostream& output, const Record& record);
std::istream& operator>>(std::istream& input, Record& record);
