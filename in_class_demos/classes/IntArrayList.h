//
// Created by drink on 9/16/2026.
//

#ifndef CS3100_FA26_INTARRAYLIST_H
#define CS3100_FA26_INTARRAYLIST_H


// declaration
class IntArrayList {
public:
    static const int INITIAL_CAPACITY = 10;

    IntArrayList(); // default

    IntArrayList(int initialCapacity);

    void add(int value);

    int get(int position) const;

    int size() const;
    int capacity() const;

private:

    int* data = nullptr;
    int count = 0;
    int array_capacity = 0;

};

#endif //CS3100_FA26_INTARRAYLIST_H
