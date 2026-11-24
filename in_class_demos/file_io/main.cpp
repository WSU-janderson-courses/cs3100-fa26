//
// Created by drink on 11/23/2026.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "Record.h"

int main() {
    std::cout << "file_io" << std::endl;

    std::ifstream input_file("records.txt");

    std::vector<Record> records;

    if (input_file.good()) {
        while (!input_file.eof()) {
            Record record;

            input_file >> record;

            if (!record.id.empty()) {
                records.push_back(record);
            }
        }
    }

    std::ofstream output_file("records_out.txt");
    for (auto record : records) {
        output_file << record << std::endl;
    }

    return 0;
}
