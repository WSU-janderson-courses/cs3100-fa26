//
//
//

#include "mini_bst.h"

bool mini_bst::insert(BSTNode*& root, BSTNode* newNode) {
    // base case 1: root is null

    // base case 2: duplicate
    return false;

    // result = recursive left/right

    // update height

    // return result
}

BSTNode* mini_bst::search(BSTNode* root, const KeyType& key) {
    return nullptr;
}

void mini_bst::keys(BSTNode* root, std::vector<KeyType>& result) {

}

// Recursion practice
std::size_t mini_bst::size(BSTNode* root) {
    return 0;
}

void mini_bst::clear(BSTNode*& root) {
    // post order traversal
}

// AVL preparation
int mini_bst::node_height(BSTNode* node) {
    // either return node->height or -1
    return 0;
}

void mini_bst::update_height(BSTNode* node) {
    // use node_height to get height of node's left and right subtree
    // update node's stored height = max(lh, rh) + 1
}
int mini_bst::balance_factor(BSTNode* node) {
    // use node_height to get height of node's left and right subtree
    // return balance of node
    return 0;
}

BSTNode* mini_bst::remove(BSTNode*& root, const KeyType& key) {
    if (root) {
        BSTNode* removeResult = nullptr;

        // find the node to remove
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

