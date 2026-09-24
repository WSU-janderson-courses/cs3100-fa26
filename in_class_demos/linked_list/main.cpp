/**
 */

#include <iostream>

// A Node is a segment of a linked list In this case, the list will store `int`
// and `next` will point to the next node in the list.
// For the last node in the list, `next == nullptr` to signal there are no more
// nodes/values in the list
class Node {
public:
    int value;
    Node* next;
};

int main() {
    std::cout << "Linked List Demo" << std::endl;

    // head will point to the first node in our list, and each node will
    // point to the next node. If the list is empty, `head == nullptr`. If
    // there is one thing in the list, `head->next == nullptr`.
    Node* head = nullptr;
}