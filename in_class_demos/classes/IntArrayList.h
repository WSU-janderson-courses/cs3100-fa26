/**
 * @file IntArrayList.h
 * @brief Declaration of the IntArrayList class
 *
 * An IntArrayList is a smaller version of an ArrayList from Java. It is also similar to a std::vector from C++.
 *
 * Currently, once the list grows to capacity, no more items can be added to the end of the list. However, this
 * can be made possible with additional methods/code
 *
 * @author James
 * @date 9-22-2026
 *
 */
#ifndef CS3100_FA26_INTARRAYLIST_H
#define CS3100_FA26_INTARRAYLIST_H

#include <ostream>

// declaration
class IntArrayList {
public:
    static const int INITIAL_CAPACITY = 10;

    // default constructor
    IntArrayList();

    // parameterized constructor
    IntArrayList(int initialCapacity);

    // copy constructor
    IntArrayList(const IntArrayList& orig);

    // assignment operator
    IntArrayList& operator=(const IntArrayList& orig);

    // destructor/deconstructor
    ~IntArrayList();

    // add to the end of the list
    void add(int value);

    // get an element at position
    int get(int position) const;

    // number of elements in the list
    int size() const;

    // capacity of the array
    int capacity() const;

    // output the contents of the list
    void print_list(std::ostream& os) const;

private:

    int* data = nullptr;
    int count = 0;
    int array_capacity = 0;

};

#endif //CS3100_FA26_INTARRAYLIST_H
