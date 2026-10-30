# AVL Tree Practice 

## Conventions

For these problems:

* The height of an empty subtree is **-1**.
* The height of a leaf is **0**.
* The balance factor is calculated as:

```text
balance factor = height of left subtree - height of right subtree
```

* Duplicate keys are not inserted.

---

## AVL Tree Properties

### 1. True or false: every AVL tree satisfies the binary search tree ordering property

### 2. True or false: every binary search tree is also an AVL tree

### 3. Which balance factors are allowed for every node in an AVL tree

- `0` only
- `-1`, `0`, or `1`
- `-2`, `-1`, `0`, `1`, or `2`
- Any balance factor is allowed at a leaf

### 4. True or false: Before any rotations are performed, inserting a value into an AVL tree can cause more than one node on the path from the inserted value to the root to become unbalanced.

---

## AVL Insertions

For each question, begin with an empty AVL tree.

### 5. Insert the following values in order:  
```
4, 13, 22, 28, 31
```  
What is the value of the left child of `28`?


### 6. Insert the following values in order:  
```
50, 30, 20
```  
- What is the value of the root?
- What type of rotation is required?

### 7. Insert the following values in order

```
10, 30, 20
```

- What value becomes the root?
- What type of imbalance occurs?
- Which rotation or rotations are required?

### 8. Insert the following values in this order:

```
40, 20, 30
```

- What value becomes the root?
- What type of imbalance occurs?
- Which rotation or rotations are required?

### 9. Insert the following values in order:

```
10, 20, 30
```

- What value becomes the root?
- What type of rotation is required?

### 10. Insert the following values in order:

```
30, 10, 40, 5, 20, 35, 50, 2
```

After all insertions:

- What is the left child of the root?
- What is the height of the root?
- What is the balance factor of the root?

### 11. Insert the following values in order:

```
25, 10, 40, 5, 15, 30, 50, 35, 32
```  
After all insertions:

- What is the right child of `25`?
- What is the left child of `40`?
- What is the left child of `32`?
- What is the height of the root?

---

## Search Comparisons

Count one comparison each time the search value is compared with a value stored in the node.

### 12. A perfectly balanced binary search tree contains exactly `31` nodes. What is the greatest number of comparisons required to search for a value?

### 13. A perfectly balanced binary search tree contains exactly `255` nodes. What is the greatest number of comparisons required to search for a value?

### 14. The root of an AVL tree has height `6`. What is the greatest number of node comparisons that could be made during a search?

### 15. A binary search tree has a balance factor of `0` at every node. Its keys must be unique integers between `1` and `200`. What is the largest possible number of nodes in the tree?

### 16. For the tree in problem 15, what is the greatest possible number of comparisons during a search?

---

## Height and Balance  
For problems 17 - 21, consider this tree:  
```
              40
            /    \
          20      60
         /  \     /
       10   30   50
      /
     5
```

### 17. What is the height of node `10`?

### 18. What is the height of node `20`?

### 19. What is the height of the root?

### 20. What is the balance factor of the root?

### 21. Is this a valid AVL tree?

---

## Finding an Imbalance

For problems 22 - 25, consider this tree:

```
              50
            /    \
          30      70
         /
       20
      /
    10
```

### 22. What is the balance factor of node `20`?

### 23. What is the balance factor of node `30`?

### 24. Starting at the newly inserted `10` and moving toward the root, what is the first unbalanced node?

### 25. What rotation should be performed at that node?  
- Single left rotation
- Single right rotation
- Double left rotation (single right at hook then single left at problem)
- Double right rotation (single left at hook then single right at problem)

---

## Solutions

### AVL Tree Properties

1. **True**
2. **False**
3. `-1`, `0`, or `1`
4. **True**   
    Before rebalancing, more than one ancestor can become unbalanced. However, insertion only requires rebalancing at the first/deepest unbalanced ancestor. After that subtree is repaired, no additional rotations are required farther up the tree. 

### AVL Insertions

5. The completed tree is:  
    ```
            13
           /  \
          4    28
              /  \
             22  31
    ```  
    Left child of `28` is `22`

6. Completed tree:

    ```
          30
         /  \
       20    50
    ```
    - **Root: `30`**
    - **Rotation: right rotation at `50`**  

        This is a **left-left** imbalance  

        After insertion, before rotation:  

        ```
             50 (+2: problem)
            /
          30 (+1: hook)
          /
       20   
        ```
        The heavy child `30` leans in the **same** direction as `50`
        - `50` is left heavy
        - `30` is left heavy
        - Same **signs**
        - Use **single right rotation**

7. Completed tree:

    ```
          20
         /  \
       10    30
    ```
    - **Root: `20`**  
    - **right-left** imbalance

    After insertion, before rotation:

    ```
          10 (problem: -2)
            \
            30 (hook: +1)
            /
           20 
    ```
    The heavy child `30` leans in the **opposite** direction from `10`  
    - `10` is right heavy  
    - `30` is left heavy  
    - **Different** signs  
    - Use **double left rotation**:  
        - Single right rotation at hook `(30)`  
        - Single left rotation at problem `(10)`  

     After single right rotation at `30`:

    ```
            10 (problem)
              \
               20 (hook)
                 \
                  30
    ```

8. Completed tree:

    ```
         30
        /  \
      20    40
    ```

    - **Root: `30`**  
    - Imbalance: **left-right** 

    After insertion, before rotation:

    ```
                    40 (problem: +2)
                   /
                 20 (hook: -1)
                  \
                   30   
    ```

    The heavy child `20` leans in the **opposite** direction as `40`  
    - `40` is left heavy
    - `20` is right heavy
    - **Different** signs
    - Use **double right rotation**:
        - Single left rotation at hook `(20)`
        - Single right rotation at problem `(40)`

9. Completed tree:
    ```
         20
        /  \
      10    30
    ```

    - **Root: `20`**
    - Rotation: **single left rotation** at `10`

    After insertion, before rotation:

    ```
        10 (problem: -2)
          \
           20 (hook: -1)
             \
              30
    ```

10. Completed tree:
    ```
                  30
                /    \
              10      40
             /  \    /  \
            5   20  35  50
           /
          2
    ```
    - Left child of root: **`10`**
    - Height of root: **3**
    - Balance of root: **1**

11. Completed Tree:

    ```
               25
             /    \
           10      40
          /  \    /  \
         5   15  32   50
                /  \
               30  35
    ```

    - Right child of `25`: **`40`**
    - Left child of `40`: **`32`**
    - Left child of `32`: **`30`**
    - Height of root: **3**

    After insertion, before rotations:

    ```
               25
             /    \
           10      40
          /  \    /  \
         5   15  30   50
                   \
                   35
                  /
                 32 
    ```

    After inserting `32`:  
    - Problem: `30`  
    - Hook: `35`  
    - Problem balance: `-2` = left rotation (right heavy)
    - Hook balance: `+1` = **different** signs, double left rotation
        - Single right rotation at `35`
        - Single left rotation at `30`

    After single right rotation at `35`:

    ```
               25
             /    \
           10      40
          /  \    /  \
         5   15  30   50
                   \
                   32
                     \
                      35  
    ```

---

### Search Comparisons

12. `31` nodes = `5` levels  
    A perfect tree with **31 = 2<sup>5</sup> - 1** nodes has **5 levels**, so the greatest number of comparisons is **5**

13. `255` nodes = `8` levels
    A perfect tree with **31 = 2<sup>8</sup> - 1** nodes has **5 levels**, so the greatest number of comparisons is **8**

14. A tree with height `6` has seven levels: `0` through `6`

15. A tree with balance factor `0` at every node must contain a **perfect** number of nodes:

    ```
    1, 3, 7, 15, 31, 63, 127, 255, ...
    ```

    For a perfect tree with `L` levels, it will have **2<sup>L</sup> - 1** nodes

    `127` is the largest perfect-tree size that does not exceed `200`. A perfect tree with `255` nodes would require `255` distinct keys, but only `200` distinct integers are available (`1` - `200`)

16. A perfect tree containing `127` nodes has seven levels.

17. Node `10` has a **height of 1**. Node `10` has a child at height `0`, so  
    ```
    height(node10) = 1 + max(0, -1) = 1
    ```

18. Node `20` has a **height of 2**

19. The root has a **height of 3**

20. Balance of node `40` is **1**
    ```
    balance(node40) = height(node20) - height(node60)
                    = 2 - 1
                    = 1
    ```


21. **Yes**  
    The tree satisfies the binary search tree property, and every node has balance factor `-1`, `0`, or `1`

## Finding an Imbalance

22. Balance of node 20:
    ```
    balance(node20) = height(node10) - height(null)
                    = 0 - (-1)
                    = 1
    ```

23. Balance of node 30:
    ```
    balance(30) = height(node20) - height(null)
                = 1 - (-1)
                = 2
    ```

24. First/deepest unbalanced node is node `30`

25. Single right rotation

    The insertion occurred in the left subtree of the left child of `30`, so this is a **left-left** imbalance.

    - Problem: `30`
    - Hook: `20`
    - Problem balance: 2, right rotation
    - Hook balance: 1, **same** signs, single right rotation



