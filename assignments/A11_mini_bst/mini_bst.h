#pragma once
/**
 * @file mini_bst.h
 * @brief Header for BST functions that work at node-level
 *
* height(node) is stored in the node.
* It is not recomputed by recursively walking the subtree.
* After changing a child subtree, update this node's height.
 */

#include <vector>
#include <string>

using KeyType = std::string;

struct BSTNode {
    KeyType key{};
    BSTNode* left{};
    BSTNode* right{};
    int height{};

    explicit BSTNode(const KeyType& key)
        : key(key) {
    }
};

namespace mini_bst{

    /* To not over-complicate with object-oriented concepts just yet, these functions work
 * at the node-level.
 *
 * These functions are **not** responsible for allocating any memory.
 * The only function responsible for deallocating memory is `clear`
 */

    // Basic BST behavior //
    /**
 * Insert `newNode` into the BST with `root` as the root node
 * If `root` is nullptr, `newNode` becomes the root node
 *
 * If the tree contains newNode->key, the tree isn't modified and the function returns false
 *
 * Once complete, all nodes in the tree should have `height` set to the correct height
 *
 * @param root pointer to the root of a BST
 * @param newNode pointer to a node to be inserted
 * @return true if the key was inserted, false if the key was not inserted due to being a duplicate
 */
    bool insert(BSTNode *&root, BSTNode *newNode);

    BSTNode *search(BSTNode *root, const KeyType &key);

    void keys(BSTNode *root, std::vector<KeyType> &result);

    // Recursion practice
    std::size_t size(BSTNode *root);

    void clear(BSTNode *&root);

    // AVL preparation
    int node_height(BSTNode *node);

    void update_height(BSTNode *node);

    int balance_factor(BSTNode *node);


    BSTNode *remove(BSTNode *&root, const KeyType &key);

    BSTNode *remove_node(BSTNode *&node);

    BSTNode *find_min(BSTNode *root);

    void print_tree_sideways(std::ostream &os, const BSTNode *root, int depth);
}
