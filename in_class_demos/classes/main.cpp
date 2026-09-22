/**
 * @file main.cpp
 * @brief
 */
#include <iostream>

#include "IntArrayList.h" // never include .cpp file

/**
 * Print the contents of the list. `list` is passed by value, meaning
 * all its members are copies of the original list. In this case, because
 * `list` allocates its array using `new`, we wrote the copy constructor
 * for IntArrayList, which is called when we pass `list` into print_list()
 * @param list the list to be printed
 */
void print_list(IntArrayList list) {
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.get(i);
        if (i < list.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Classes and Objects Demos" << std::endl << std::endl;

    {
        // `list` is a local variable to `main()` and all of its members are stored on the stack
        IntArrayList list = IntArrayList(20);

        // add some elements to the list
        for (int i = 0; i < 5; i++) {
            list.add((i) * 3);
            std::cout << "list size: " << list.size() << std::endl;
            std::cout << "list capacity: " << list.capacity() << std::endl << std::endl;
        }

        // add another element
        list.add(99);

        // output what is at position (index) 4 in the list
        std::cout << "position 4: " << list.get(4) << std::endl;

        print_list(list); // passing `list` to `print_list()` makes a copy with the copy constructor

        IntArrayList list2;
        list2.add(99);
        list2.add(98);
        print_list(list2);

        list2 = list; // assigning list to list2 uses the assignment operator
        print_list(list2);
    }

    std::cout << "Done" << std::endl;
    return 0;
}

