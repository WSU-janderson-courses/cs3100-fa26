/**
* @file doubly_linked_list.cpp
* @brief
*
* @author james 
* @date  7/31/2026.
*/

#include "doubly_linked_list.h"

// insertion
void push_front(Node*& head, Node*& tail, Node* newNode) {
    if (!head && !tail) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void push_back(Node*& head, Node*& tail, Node* newNode) {
    if (!head && !tail) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// removal
Node* pop_front(Node*& head, Node*& tail) {
    if (!head) {
        return nullptr;
    }

    Node* to_pop = head;

    head = head->next;
    to_pop->next = nullptr;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    return to_pop;
}

Node* pop_back(Node*& head, Node*& tail) {
    if (!tail) {
        return nullptr;
    }

    Node* to_pop = tail;

    tail = tail->prev;
    to_pop->prev = nullptr;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    return to_pop;
}

// Accessing nodes
Node* get_node_at(Node* head, size_t position) {
    if (!head) { return nullptr; }
    Node* current = head;
    for (size_t i = 0; i < position && current; i++) {
        current = current->next;
    }
    return current;
}


// cleanup
void clear(Node*& head, Node*& tail) {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        prev = current;
        current = current->next;
        delete prev;
    }
    head = nullptr;
    tail = nullptr;
}
