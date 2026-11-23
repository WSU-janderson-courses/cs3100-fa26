
#include <iostream>

#include "mini_bst.h"

bool mini_bst::insert(BSTNode*& root, BSTNode* newNode) {
    if (!root) {
        root = newNode;
        return true;
    }

    if (!newNode || newNode->key == root-> key) {
        return false;
    }

    bool inserted  = false;

    if (newNode->key < root-> key) {
        inserted = insert(root->left, newNode);
    } else if (newNode->key > root-> key) {
        inserted = insert(root->right, newNode);
    }

    if  (inserted) {
        update_height(root);
    }

    return inserted;
}

BSTNode* mini_bst::search(BSTNode* root, const KeyType& key) {
    if (!root) {
        return nullptr;
    }

    if (root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }
    if (key > root->key) {
        return search(root->right, key);
    }

    return nullptr;
}

void mini_bst::keys(BSTNode* root, std::vector<KeyType>& output) {
    if (root) {
        keys(root->left, output);
        output.push_back(root->key);
        keys(root->right, output);
    }
}

std::size_t mini_bst::size(BSTNode* root) {
    if (!root) {
        return 0;
    }

    return size(root->left) + size(root->right) + 1;
}

int mini_bst::node_height(BSTNode* node) {
    if (!node) {
        return -1;
    }

    return node->height;
}

void mini_bst::update_height(BSTNode* node) {
    if (!node) {return;}
    node->height = std::max(node_height(node->left), node_height(node->right)) + 1;
}

int mini_bst::balance_factor(BSTNode* node) {
    if (!node) {
        return 0;
    }
    return node_height(node->left) - node_height(node->right);
}

void mini_bst::clear(BSTNode*& root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}



BSTNode* mini_bst::remove(BSTNode*& root, const KeyType& key) {
    if (root) {
        BSTNode* removeResult = nullptr;

        // find the node to renmove
        if (root->key == key) {
            removeResult = remove_node(root);
        }  else if (key < root->key) {
            removeResult = remove(root->left, key);
        } else {
            removeResult = remove(root->right, key);
        }
        if (removeResult) {
            removeResult->left = nullptr;
            removeResult->right = nullptr;
        }
        update_height(root);
        return removeResult;
    }
    return nullptr;
}

BSTNode* mini_bst::remove_node(BSTNode*& node) {
    if (!node) {
        return nullptr;
    }

    BSTNode* toDelete = node;
    if (!node->left && !node->right) {
        // node is leaf can remove it
        node = nullptr;
    } else if (node->left && node->right) {
        // node has two children, need to swap with smallest in right subtree
        BSTNode* smallest_right_subtree = find_min(node->right);
        KeyType replacement_key = smallest_right_subtree->key;
        toDelete = remove(node, replacement_key);

        node->key = replacement_key;

    } else {
        // node isn't leaf, doesn't have 2 children, must have only one, swap with that one
        if (node->left) {
            node = node->left;
        } else {
            node = node->right;
        }
        update_height(node);
    }

    return toDelete;
}

BSTNode* mini_bst::find_min(BSTNode* root) {
    if (root && root->left) {
        return find_min(root->left);
    }
    return root;
}

void mini_bst::print_inorder(std::ostream& os, const BSTNode* root) {
    if (root) {
        print_inorder(os, root->left);
        os << root->key << " ";
        print_inorder(os, root->right);
    }
}

void mini_bst::print_tree_sideways(std::ostream& os, const BSTNode* current, int depth) {
    if (current) {
        print_tree_sideways(os, current->right, depth + 1);

        os << KeyType(depth * 4, ' ') << current->key << std::endl;

        print_tree_sideways(os, current->left, depth + 1);
    }
}