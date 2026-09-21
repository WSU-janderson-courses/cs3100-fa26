/**
 * @file main.cpp
 * @brief
 */
#include <iostream>

#include "IntArrayList.h" // never include .cpp file


int main() {
    std::cout << "Classes and Objects Demos" << std::endl << std::endl;

    {
        IntArrayList list = IntArrayList(12); // value

        for (int i = 0; i < 10; i++) {
            list.add((i) * 3);
            std::cout << "list size: " << list.size() << std::endl;
            std::cout << "list capacity: " << list.capacity() << std::endl << std::endl;
        }

        list.add(99);

        std::cout << "position 4: " << list.get(4) << std::endl;

    }

    std::cout << "Done" << std::endl;
    return 0;
}

