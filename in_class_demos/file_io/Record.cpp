#include "Record.h"

#include <iomanip>
#include <istream>
#include <ostream>

std::ostream& operator<<(std::ostream& output, const Record& record) {
    return output << std::quoted(record.id) << ' '
                  << std::quoted(record.name) << ' '
                  << std::quoted(record.category) << ' '
                  << record.value;
}

std::istream& operator>>(std::istream& input, Record& record) {
    Record parsed;
    if (input >> std::quoted(parsed.id)
              >> std::quoted(parsed.name)
              >> std::quoted(parsed.category)
              >> parsed.value) {
        record = parsed;  // Do not modify record if extraction fails.
    }
    return input;
}
