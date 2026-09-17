//
// Created by drink on 9/16/2026.
//

#include "IntArrayList.h"

// definitions

void IntArrayList::add(int value) {
    this->data[count] = value;
    this->count++;
}