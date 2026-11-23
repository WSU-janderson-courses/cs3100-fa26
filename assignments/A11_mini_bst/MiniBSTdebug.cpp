/**
* @file MiniBSTdebug.cpp
* @brief
*
* @author james 
* @date  7/8/2026.
*/

#include <iostream>
#include "mini_bst.h"



int main() {
    BSTNode* root = new BSTNode("m");

    bool insert_test = mini_bst::insert(root, new BSTNode("g"));
    insert_test = mini_bst::insert(root, new BSTNode("r"));
    insert_test = mini_bst::insert(root, new BSTNode("b"));
    insert_test = mini_bst::insert(root, new BSTNode("a"));
    insert_test = mini_bst::insert(root, new BSTNode("j"));

    insert_test = mini_bst::insert(root, new BSTNode("b"));


    BSTNode* search_result = mini_bst::search(root, "j");
    search_result = mini_bst::search(root, "x");

    int height_test = mini_bst::node_height(root);
    height_test = mini_bst::node_height(root->left);
    height_test = mini_bst::node_height(root->right);

    int balance_test = mini_bst::balance_factor(root);
    balance_test = mini_bst::balance_factor(root->left);
    balance_test = mini_bst::balance_factor(root->right);

    std::vector<std::string> keys_test;
    mini_bst::keys(root, keys_test);

    mini_bst::print_tree_sideways(std::cout, root, 0);

    mini_bst::print_inorder(std::cout, root);

    int size_test = mini_bst::size(root);

    BSTNode* remove_result = mini_bst::remove(root, "g");

    if (remove_result) {
        delete remove_result;
    }
    mini_bst::print_tree_sideways(std::cout, root, 0);

    mini_bst::print_inorder(std::cout, root);

    mini_bst::clear(root);

    return 0;
}
