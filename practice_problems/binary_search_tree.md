# Binary Search Tree Practice Problems

## Assumptions

- All keys are **unique** integers
- Duplicate keys are not inserted
- One comparison means comparing the target key with one node's key
- For removal of a node with two children, use the **in-order successor**: the smallest key in the node's **right subtree**
- A **left-first in-order traversal** visits:

```
left subtree -> node -> right subtree
```

## Valid Binary Search Trees

### 1. Is **Tree A** a valid binary search tree?  
```
             50
           /    \
         30      75
        /  \    /  \
      20   40  60   90
          /    / \   /
         35   55 65 80
```  
If it is not valid, identify the key or keys that violate the BST ordering rules.

### 2. Is **Tree B** a valid BST?

```
             40
           /    \
         20      70
        /  \    /  \
      10   30  50   90
             \
              45
```

If it is not valid, explain why.

### 3. Is **Tree C** a valid BST?

```
             40
           /    \
         15      70
           \     /
           35   50
          /       \
         20        65
```

---

## BST Insert

Use **Tree A** for Questions 4 - 6

```
             50
           /    \
         30      75
        /  \    /  \
      20   40  60   90
          /    / \   /
         35   55 65 80
```

For each insertion:
- List the nodes examined
- State where the new node would be inserted

### 4. Insert `58`
### 5. Insert `85`
### 6. Insert `30`

## BST Search

Continue with **Tree A**, after having completed the insertions.

For each search, list the nodes in the order they would be examined. Include whether the search succeeds or fails.

### 7. Search for `35`
### 8. Search for `65`
### 9. Search for `70`
### 10. Search for `20`

---

## Number of Comparisons

Continue with **Tree A** from the **insert** section, after the insertions.

### 11. What is the largest number of comparisons required to find an existing key in the tree?

### 12. Which existing keys require that number of comparisons?

### 13. Give one key that is not in the tree but would require the maximum number of key comparisons before the search fails.

---

## Removing Keys

For the removal questions, start with a fresh copy of **Tree D**:

```
             40
           /    \
         20      60
        /  \    /  \
      10   30  50   70
          /  \        \
         25  35        80
```

Use the **in-order successor** when removing a node with two children.   
Draw the resulting tree after each removal.

### 14. Remove `10`
### 15. Remove `70`
### 16. Remove `20`
### 17. Remove `40`

---

## In-order Traversal

### 18. Give the **left-first in-order traversal** of this tree:

```
             50
           /    \
         30      75
        /  \    /  \
      20   40  60   90
          /    / \   /
         35   55 65 80
```

### 19. Give the **left-first in-order traversal** for this tree

```
             40
           /    \
         15      70
           \     /
           35   50
          /       \
         20        65
```

### 20. Starting with **Tree D**, remove `20` using the in-order successor. Then give the left-first in-order traversal of the resulting tree.

---

# Solutions

## Valid Binary Search Trees

1. **Valid**  
Every key in a node's left subtree is smaller than the node, and every key in its right subtree is larger

2. **Not valid**  
The key `45` is in the left subtree of `40`. Although `45` is correctly placed relative to its parent `30`, it violates the ordering requirement established by `40`

3. **Valid**  
- `20` is greater than `15` and less than `35`
- Every key in the left subtree of `40` is less than `40`
- Every key in the right subtree of `40` is greater than `40`

## BST Insert

4. Insert `58`  
Nodes examined:  
`50 -> 75 -> 60 -> 55`  
Decisions:  
`58 > 50`  
`58 < 75`  
`58 < 60`  
`58 > 55`  
Therefore, `58` becomes the **right child** of `55`  

    ```
            60
           /  \
         55    65
           \
            58
    ```

5. Insert `85`  
Nodes examined:  
`50 -> 75 -> 90 -> 80`  
Therefore, `85` becomes the **right child** of 80.  

    ```
           90
          /
         80
           \
            85
    ```

6. Insert `30`  
Nodes examined:  
`50 -> 30`  
The key `30` is already in the tree. Because duplicates are disallowed, nothing is inserted.

## BST Search

7. Search for `35`  
`50 -> 30 -> 40 -> 35`  
The search succeeds after **4 comparisons**

8. Search for `65`  
`50 -> 75 -> 60 -> 65`  
The search succeeds after **4 comparisons**

9. Search for `70`  
`50 -> 75 -> 60 -> 65`  
After examining `65`, the search moves to its right child, which is empty.  
The search fails after **4 key comparisons**

10. Search for `20`  
`50 -> 30 -> 20`  
The search succeeds after **3 comparisons**

## Number of Comparisons

11. The maximum is **4 comparisons**  
The deepest nodes are four levels from the root when the root counts as the first comparison

12. Existing keys requiring four comparisons:  
`35, 55, 65, 80`

13. One possible missing key requiring four comparisons is `58`.  
The search path would be:  
`50 -> 75 -> 60 -> 55`  
The search then moves to the empty right child of `55`  
Other answers are possible

## BST Remove

14. Remove `10`:  
`10` is a leaf, so it can simply be disconnected.  
    ```
                 40
               /    \
             20      60
               \    /  \
               30  50   70
              /  \        \
             25  35        80
    ```

15. Remove `70`  
`70` has one child, `80`. Its parent's pointer is changed to point directly to `80`.

    ```
                 40
               /    \
             20      60
            /  \    /  \
          10   30  50   80
              /  \
             25  35
    ```

16. Remove `20`  
`20` has two children. Its in-order successor is `25`, the smallest key in its right subtree.  
Replace `20` with `25`, and remove the original `25` node.  

    ```
                 40
               /    \
             25      60
            /  \    /  \
          10   30  50   70
                 \        \
                 35        80
    ```

17. Remove `40`  
`40` has two children. Its in-order successor is `50`, the smallest key in its right subtree.  
Replace `40` with `50`, and remove the original `50` node  
    ```
                 50
               /    \
             20      60
            /  \       \
          10   30       70
              /  \        \
             25  35        80
    ```

## In-order Traversal

18. `20, 30, 35, 40, 50, 65, 75, 80, 90`  
Because the tree is a valid BST, its in-order traversal produces the keys in increasing order.

19. `15, 20, 35, 40, 50, 65, 70`

20. After removing `20` using its in-order successor:  
    ```
                 40
               /    \
             25      60
            /  \    /  \
          10   30  50   70
                 \        \
                 35        80
    ```  
    The in-order traversal is:  
    `10, 25, 30, 35, 40, 50, 60, 70, 80`