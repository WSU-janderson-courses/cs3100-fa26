//
// Created by drink on 9/16/2026.
//

#include "IntArrayList.h"

#include <iostream>
#include <ostream>

// definitions
IntArrayList::IntArrayList() {
    //std::cout << "IntArrayList constructor" << std::endl;
    data = new int[INITIAL_CAPACITY];
    array_capacity = INITIAL_CAPACITY;
}

IntArrayList::IntArrayList(int initialCapacity) {
    //std::cout << "IntArrayList parameterized" << std::endl;
    data = new int[initialCapacity];
    array_capacity = initialCapacity;
}

void IntArrayList::add(int value) {
    if (count >= this->array_capacity) {
        std::cerr << "IntArrayList::add out of bounds" << std::endl;
        return;
    }
    this->data[count] = value;
    this->count++;
}

int IntArrayList::get(int position) const {
    return this->data[position];
}

int IntArrayList::size() const {
    return this->count;
}

int IntArrayList::capacity() const {
    return this->array_capacity;
}