#include <iostream>
#include "doubly_linked_list.h"

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    push_front(head, tail, new Node{"A", nullptr});
    push_back(head, tail, new Node{"B", nullptr});
    push_back(head, tail, new Node{"C", nullptr});
    push_back(head, tail, new Node{"D", nullptr});

    while (head && tail) {
        Node* removed = pop_back(head, tail);
        std::cout << removed->value << std::endl;
        delete removed;
    }
    std::cout << std::endl;

    push_front(head, tail, new Node{"A", nullptr});
    push_back(head, tail, new Node{"B", nullptr});
    push_back(head, tail, new Node{"C", nullptr});
    push_back(head, tail, new Node{"D", nullptr});

    while (head && tail) {
        Node* removed = pop_front(head, tail);
        std::cout << removed->value << std::endl;
        delete removed;
    }
    std::cout << std::endl;

    push_front(head, tail, new Node{"A", nullptr});
    push_back(head, tail, new Node{"B", nullptr});
    push_back(head, tail, new Node{"C", nullptr});
    push_back(head, tail, new Node{"D", nullptr});

    // check if we can iterate through all the nodes
    for (size_t i = 0; i < 10; i++) {
        Node* test_get = get_node_at(head, i);
        if (test_get) {
            std::cout << test_get->value << std::endl;
        } else {
            std::cout << "nullptr: " << i << std::endl;
        }
    } {
        // test changing the value in the node
        Node* test_get_modify = get_node_at(head, 1);
        test_get_modify->value = "Z";
    }

    // check if we can iterate through all the nodes
    for (size_t i = 0; i < 10; i++) {
        Node* test_get = get_node_at(head, i);
        if (test_get) {
            std::cout << test_get->value << std::endl;
        } else {
            std::cout << "nullptr: " << i << std::endl;
        }
    }


    clear(head, tail);

    std::cout << "done" << std::endl;

    clear(head, tail);
}
