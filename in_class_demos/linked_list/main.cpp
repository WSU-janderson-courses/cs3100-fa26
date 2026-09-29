/**
 * Linked List Demo
 *
 * This file minimally demonstrates how to work with nodes in a linked list to add to the front and back of the list.
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

/**
 * Adds the value to the front of the list
 * The node pointed to by `head` is updated to point to the new first node
 *
 * @param head the head of a linked list, which after calling `push_front()` points
 * to the updated first node
 * @param value the value to add to the front of the list
 */
void push_front(Node*& head, int value) {
    // allocate for a new node
    Node* newFront = new Node;
    newFront->value = value;

    // make newFront->next to point to head
    newFront->next = head;

    // newFront is now the new head of the list
    head = newFront;
}

int main() {
    std::cout << "Linked List Demo" << std::endl;

    // head will point to the first node in our list, and each node will
    // point to the next node. If the list is empty, `head == nullptr`. If
    // there is one thing in the list, `head->next == nullptr`.
    Node* head = nullptr;

    // does our `push_front()` work if `head == nullptr` and the list is empty?
    push_front(head, 99);

    if (head == nullptr) {
        std::cout << "Linked List is empty" << std::endl;

        // start list
        head = new Node;

        head->value = 5;
        head->next = nullptr;
    } else {
        std::cout << "Linked List is not empty" << std::endl;
    }

    // push 10, 20, 30, 40, and 50 to the front of the list
    // afterwards, list should look like:
    // 50, 40, 30, 20, 10, ...
    push_front(head, 10);
    push_front(head, 20);
    push_front(head, 30);
    push_front(head, 40);
    push_front(head, 50);

    // now add to the end of the list
    Node* current = head;

    // traverse/iterate through the list until we reach the last node where `current->next == nullptr`
    // Will this work if we start with `head == nullptr`? If not, how can we fix it?
    while (current->next != nullptr) {
        current = current->next;
    }
    Node* newNode = new Node;
    newNode->value = 60;
    current->next = newNode;

    std::cout << "Done" << std::endl;
    return 0;
}