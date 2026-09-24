/**
 * @file IntArrayList.cpp
 * @brief Definition of IntArrayList methods
 *
 * The implementation of IntArrayList involves manually maintaining the underlying array
 * in which the list elements are stored. A list might look like:
 *
 * (7, 34, 9, 45, 87, 3, 2, 8, 5)
 *
 * Internally, the IntArrayList member variables for that same list might look like:
 *
 * data: [7, 34, 9, 45, 87, 3, 2, 8, 5, 0, 0, 0, 0, 0, 0, 0]
 * count: 9
 * capacity: 16
 *
 * As the list grows, the new element is stored in data[count], and count is incremented. When count == capacity,
 * the list currently rejects the new element.
 */

#include "IntArrayList.h"

#include <iostream>
#include <ostream>

// Definitions of IntArrayList methods


/**
 * Default constructor
 * If we don't give any parameters, our list starts with an array
 * capable of storing `INITIAL_CAPACITY` number of elements
 */
IntArrayList::IntArrayList() {
    //std::cout << "IntArrayList constructor" << std::endl;
    data = new int[INITIAL_CAPACITY];
    array_capacity = INITIAL_CAPACITY;
}

/**
 * Parameterized constructor
 * We can create a list and give it an initial capacity to have the
 * list begin with something other than the default
 * @param initialCapacity the initial capacity of the list, used to allocate the array memory
 */
IntArrayList::IntArrayList(int initialCapacity) {
    //std::cout << "IntArrayList parameterized" << std::endl;
    data = new int[initialCapacity];
    array_capacity = initialCapacity;
}

/**
 * Copy constructor
 * The copy constructor is called when a brand new object is created, and it
 * needs to be a copy of a different object, in this case `orig`.
 * Because `data` is a pointer to memory allocated on the heap, we can't just
 * copy the pointer. Both lists would then be pointing to the same array. Instead,
 * we need to allocate for a new array for `this` list, and copy the elements from
 * `orig.data` into `this->data`
 *
 * @param orig the original list being copied into `this` list
 */
IntArrayList::IntArrayList(const IntArrayList &orig) {
    // `this` is a brand new IntArrayList
    // to copy from `orig` we first want to allocate
    // for a new array, and copy other the count and capacity
    this->data = new int[orig.array_capacity];

    this->array_capacity = orig.array_capacity;
    this->count = orig.count;

    // copy from orig into `this`
    for (int i = 0; i < orig.count; i++) {
        this->data[i] = orig.data[i];
    }
}

/**
 * Assignment operator
 * The assignment operator gets called when there is an existing list that is being replaced with
 * a different list. For example, if we have `list1` and `list2`, and both lists have elements, if
 * we did:
 *
 * list1 = list2;
 *
 * The asssignment operator gets called, and we need to copy the elements from `list2` into `list`. In the
 * assignment operator, `list11` is `this` and `list2` is `orig`.
 *
 * The assignment operator is very similar to the copy constructor, except because `this` list may
 * already have an array pointed to by `data`, we first need to deallocate that memory before creating
 * a new array. What would happen if we didn't?
 *
 * @param orig The original list being copied into `this` list
 * @return *this, which is simply `this` list
 */
IntArrayList &IntArrayList::operator=(const IntArrayList &orig) {
    if (this != &orig) {
        // `this` list needs to release its own array so we can
        // create a new one that can store orig.array_capacity
        delete[] this->data;

        this->array_capacity = orig.array_capacity;
        this->count = orig.count;

        // allocate the new array
        this->data = new int[orig.array_capacity];

        // copy from orig into `this`
        for (int i = 0; i < orig.count; i++) {
            this->data[i] = orig.data[i];
        }
    }

    return *this;
}

/**
 * Destructor (Deconstructor)
 *
 * The destructor is called whenever an object goes out of scope. Once an object goes
 * out of scope, any memory it may have been pointing to that was originally allocated
 * using `new` will no longer be accessible. That could cause a memory leak, so we need
 * to deallocate that memory, which tells the OS we are done using the memory we previously
 * asked for.
 */
IntArrayList::~IntArrayList() {
    // std::cout << "~IntArrayList()" << std::endl;

    // For the IntArrayList, we just need to deallocate the array pointed to by `data`
    // If a pointer is pointing to only one of an object, meaning we didn't use `[]` when
    // allocating with `new`, we can just say:
    //
    // delete object;
    //
    // Saying `delete[]` indicates there may be more than one object, and the OS will
    // know how many objects need to be released
    delete[] data;
}

/**
 * Pushes a new element to the end of the list. If the list is at capacity, the list is not altered.
 * After a successful add(), the count is incremented to represent the new size of the list.
 *
 * For your consideration: what would we need to do in order for add() to always
 * add a new value to the end of the list?
 *
 * @param value The element to be added to the end of the list.
 */
void IntArrayList::add(int value) {
    if (count >= this->array_capacity) {
        std::cerr << "IntArrayList::add out of bounds" << std::endl;
        return;
    }
    this->data[count] = value;
    this->count++;
}

/**
 * Retrieve the element at the given position in the list
 * Currently, get() allows out-of-bounds access, so the user should check the position is
 * valid (less than size()) before calling get().
 *
 * For your consideration: if I wanted `get()` to handle out-of-bounds list
 * accesses, what are some ways to do that? C++ has exceptions, but it
 * also has `std::optional`, which if you're curious you can look into.
 *
 * @param position The position in the list to retrieve an element
 * @return The element at the given position in the list
 */
int IntArrayList::get(int position) const {
    return this->data[position];
}

/**
 * Retrieve the number of elements currently in the list.
 *
 * @return the `count` or number of elements in the list
 */
int IntArrayList::size() const {
    return this->count;
}

/**
 * Retrieve the total capacity of the `data` array
 *
 * @return The capacity of the `data` array, or how many elements the
 * list could possible store
 */
int IntArrayList::capacity() const {
    return this->array_capacity;
}

/**
 * Output the contents of the list, if we want to output to the console
 * we can pass `std::cout`.
 *
 * Note: it's easy to get confused and use `std::cout` in a print method
 * like this, but we want to use `os` instead, as that will output
 * to whatever `std::ostream` that is passed in.
 *
 * @param os the `ostream` the list is output to
 */
void IntArrayList::print_list(std::ostream& os) const {
    for (int i = 0; i < this->count; i++) {
        os << this->data[i];
        if (i < this->count - 1) {
            os << ", ";
        }
    }
    os << std::endl;
}
