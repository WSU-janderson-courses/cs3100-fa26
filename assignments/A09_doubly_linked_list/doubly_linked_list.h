/**
* @file doubly_linked_list.h
* @brief
*
* @author
* @date
*/

#pragma once

#include <string>
#include <cstddef>

using ValueType = std::string;

class Node {
public:
    ValueType value{};
    Node* next{};
    Node* prev{};
};

// insertion
void push_front(Node*& head, Node*& tail, Node* newNode);
void push_back(Node*& head, Node*& tail, Node* newNode);

// removal
Node* pop_front(Node*& head, Node*& tail);
Node* pop_back(Node*& head, Node*& tail);

// access
Node* get_node_at(Node* head, std::size_t pos);

// cleanup
void clear(Node*& head, Node*& tail);
