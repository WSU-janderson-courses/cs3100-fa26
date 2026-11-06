# A11 - Binary Search Tree 

## Overview

In this assignment, you will implement several helper functions for a binary search tree. This assignment is designed as preparation for the AVL Tree Map project.

The main goal is not just to build a basic BST. The main goal is to practice maintaining height information inside each node.

In an AVL tree, every node needs to know the height of its subtree so that the tree can detect when a rotation is needed. However, checking the height of a subtree by recursively walking through every node would make insertion too slow.

For this assignment, each node stores its own height:

```cpp
using KeyType = std::string;

struct BSTNode {
    KeyType key{};
    BSTNode* left{};
    BSTNode* right{};
    int height{};

    explicit BSTNode(const KeyType& key)
       : key(key) {}
};
```

Your functions must keep the `height` field correct as the tree changes.

## Important Height Rule

The height of a node is stored in the node.

You should not compute the height of a subtree by recursively walking through the subtree every time you need the height.

Use this convention:

```cpp
node_height(nullptr) == -1
node_height(leaf node) == 0
```

For a non-null node, the height is:

```cpp
1 + max(height of left child, height of right child)
```

Because each child already stores its own height, updating one node’s height should be constant time.

For example:

```cpp
void update_height(BSTNode* node);
```

should update only the height of `node`. It should not recursively update the entire subtree.

## Node-Level Functions

This assignment does not use a full BST class. Instead, the functions work directly with `BSTNode*` pointers.

For example, instead of writing:

```cpp
tree.insert("cat");
```

you will call a function like:

```cpp
insert(root, new BSTNode("cat"));
```

This is intentional. The AVL Tree Map project will use similar recursive helper functions internally.

## Memory Ownership

Most functions in this assignment do not allocate or deallocate memory.

The `insert` function receives a pointer to a node that was already created with `new`.

If insertion succeeds, the tree takes ownership of that node.

If insertion fails because the key is already in the tree, the tree is not modified, and the tree does not take ownership of `newNode`. The caller is responsible for deleting it.

Example:

```cpp
BSTNode* node = new BSTNode("cat");

if (!insert(root, node)) {
    delete node;
}
```

The `clear` function is responsible for deleting all nodes in a tree. If you use the provided `remove` function, it detaches a node and returns a pointer to it. The caller is responsible for deleting the returned node.

Example:

```cpp
BSTNode* removed = remove(root, "cat");

if (removed != nullptr) {
    delete removed;
}
```

## Required Functions

The function signatures in your code **must** match the starter header exactly. You may add functions if you like, but your submission will be graded based on the given functions implementing the following operations.

### `insert`

```cpp
bool insert(BSTNode*& root, BSTNode* newNode);
```

Insert `newNode` into the binary search tree rooted at `root`.

If `root` is `nullptr`, then `newNode` becomes the root of the tree.

If the tree already contains `newNode->key`, do not insert the node and return `false`.

If `insert` returns `false`, the tree did not take ownership of `newNode`. The caller **must delete** `newNode` to avoid a memory leak.

`insert` should **not** create a new node. It should link the provided `newNode` into the tree if the key is not already present.

You may assume `newNode->left` and `newNode->right` are `nullptr`. 

Ensure when you call `insert`, you pass a pointer to a node that has no children and its height is `0`.

If insertion succeeds, return `true`.

After insertion, all nodes along the path from the inserted node back to the root must have correct heights.

You should update heights as the recursive calls return.

The general pattern is:

```cpp
insert into the left or right subtree
if insertion happened, update this node's height
return whether insertion happened
```

This pattern will be important in the AVL Tree Map project, where the next step after updating height will be checking the balance factor and possibly rotating.

### `search`

```cpp
BSTNode* search(BSTNode* root, const KeyType& key);
```

Search for `key` in the BST rooted at `root`.

Return a pointer to the node containing the key.

If the key is not found, return `nullptr`.

This function should use the BST ordering property. It should not do a full traversal of the whole tree unless necessary.

### `keys`

```cpp
void keys(const BSTNode* root, std::vector<KeyType>& result);
```

Add all keys from the tree to the provided vector in sorted order.

This function should use an in-order traversal:

```cpp
left subtree
current node
right subtree
```

The function should not clear the vector before adding keys. It should append keys to the vector that was passed in.

### `size`

```cpp
std::size_t size(const BSTNode* root);
```

Return the number of nodes in the tree rooted at `root`.

This function may be recursive.

This is different from the later AVL Tree Map project, where the class will store the number of nodes so that `size()` can run in constant time.

### `node_height`

```cpp
int node_height(const BSTNode* node);
```

Return the stored height of `node`.

If `node` is `nullptr`, return `-1`.

This function should not recursively calculate the height of a subtree.

### `update_height`

```cpp
void update_height(BSTNode* node);
```

Update the stored height of `node`.

If `node` is `nullptr`, do nothing.

This function should use the stored heights of the left and right children.

It should not recursively walk through the subtree.

Example usage:

```cpp
BSTNode* root = new BSTNode("m");
root->left = new BSTNode("g");

// at this point both:
// root->height == root->left->height == 0

update_height(root);

// after this:

root->height == 1
root->left->height = 0
```



### `balance_factor`

```cpp
int balance_factor(const BSTNode* node);
```

Return the balance factor of `node`.

Use this definition:

```cpp
balance factor = height(left subtree) - height(right subtree)
```

If `node` is `nullptr`, return `0`.

A positive balance factor means the left subtree is taller.

A negative balance factor means the right subtree is taller.

A balance factor of `0` means the two subtrees have the same height.

This assignment does not require rotations, but the AVL Tree Map project will use this value to decide when rotations are needed.

### `clear`

```cpp
void clear(BSTNode*& root);
```

Delete every node in the tree rooted at `root`.

After the function finishes, `root` should be set to `nullptr`.

Calling `clear` on an empty tree should be safe.

## Provided Helper Functions

The starter code includes these additional helper functions:

```cpp
BSTNode* remove(BSTNode*& root, const KeyType& key);
BSTNode* remove_node(BSTNode*& node);
BSTNode* find_min(BSTNode* root);
void print_inorder(std::ostream& os, const BSTNode* root);
void print_tree_sideways(std::ostream& os, const BSTNode* node, int depth);
```

The implementation for `remove()` has been given to you. You are not required to implement it, but you may want to test it, as you will be using a similar method to remove elements from the AVL Tree Map project.


The `print_inorder()` `print_tree_sideways()` functions are provided to help you visualize the tree while debugging.

## Example

If you insert the keys in this order:

```cpp
m, g, t, d, j, p, w
```

`print_inorder()` should print them out in alphabetical order:

```text
d g j m p t w
```

and `print_tree_sideways` should output the tree similar to:

```text
        w
    t
        p
m
        j
    g
        d
```

The root node `"m"` should have height `2`.

Each leaf node should have height `0`.

## Testing Expectations

You should test at least the following cases:

1. Searching an empty tree.
1. Inserting into an empty tree.
1. Searching for keys that exist.
1. Searching for keys that do not exist.
1. Inserting keys that go to the left and right subtrees.
1. Attempting to insert a duplicate key.
1. Verifying that `keys` returns keys in sorted order.
1. Verifying that `size` returns the correct number of nodes
1. Verifying that heights are correct after several insertions.
1. Verifying that `balance_factor` returns correct values.
1. Clearing a tree and checking that the root becomes `nullptr`.

You should especially test unbalanced insertion orders, such as:

```cpp
m, g, d, a
```

This tree will not rebalance itself, but the stored heights should still be correct.

## Important Notes

This is not an AVL tree yet.

Your tree is allowed to become unbalanced.

The purpose of this assignment is to prepare for AVL trees by practicing:

* recursive insertion
* modifying a subtree through `BSTNode*&`
* in-order traversal
* stored node heights
* balance factor calculation
* recursive cleanup

In the AVL Tree Map project, you will use the same basic recursive structure, but after insertion or removal you will also check balance factors and perform rotations.

| Description                                                                                                                                                                                                           |  Points |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------: |
| `insert()` correctly inserts nodes using BST ordering, modifies subtree pointers using `BSTNode*&`, rejects duplicate keys, follows the stated ownership rules, and returns the correct boolean result.               |       4 |
| `insert()` correctly updates stored heights along the path from the inserted node back to the root without recursively recomputing subtree heights                                                                    |       3 |
| `search()` correctly finds existing keys and returns `nullptr` for missing keys while using the BST ordering properly.                                                                                                |       2 |
| `keys()` correctly performs an in-order traversal and appends all keys to the provided vector in sorted order.                                                                                                        |       2 |
| `size()` correctly returns the number of nodes in the tree using recursion.                                                                                                                                           |       1 |
| `node_height()`, `update_height()`, and `balance_factor()` correctly use the stored height convention: `nullptr` has a height of `-1`, a leaf has height `0`, and balance factor is `height(left) - height(right)`    |       2 |
| `clear()` correctly deletes all nodes in the tree, sets the root pointer to `nullptr`, and safely handles an empty tree.                                                                                              |       1 |
| **Total**                                                                                                                                                                                                             |  **15** |
