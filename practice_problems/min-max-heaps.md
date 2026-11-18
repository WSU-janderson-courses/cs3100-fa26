# Heap Practice

## Conventions

For these problems:

- A heap is stored as a **complete binary tree**.
- Array representations use **0-based indexing**.
- For a node at index `i`:
  - Parent index: `(i - 1) / 2` using integer division
  - Left-child index: `2i + 1`
  - Right-child index: `2i + 2`
- A **max-heap** requires every parent to be greater than or equal to its children.
- A **min-heap** requires every parent to be less than or equal to its children.
- Unless stated otherwise, all values are distinct.
- When removing the root:
  1. Move the final array element to the root.
  2. Remove the final array position.
  3. Percolate the new root down.
- When percolating down in a max-heap, compare with the **larger child**.
- When percolating down in a min-heap, compare with the **smaller child**.

Show the array after each swap when a problem asks you to show your work.

---

# Practice Problems

## Heap Properties and Array Representation

### 1. Classifying Heaps

For each array, state whether it represents a:

- max-heap,
- min-heap, or
- neither.

#### a.

```text
[90, 70, 80, 20, 65, 75, 40]
```

#### b.

```text
[4, 8, 6, 12, 10, 9, 7]
```

#### c.

```text
[50, 30, 45, 10, 35, 40, 20]
```

#### d.

```text
[3, 5, 4, 9, 8, 7, 6]
```

### 2. Tree to Array

Write the array representation of the following tree. Then state whether it is a valid max-heap.

```text
             84
          /      \
        61        73
       /  \      /  \
     20   44   55   68
    / \
   5  12
```


### 3. Array to Tree

Draw the complete binary tree represented by:

```text
[2, 6, 4, 13, 9, 8, 7, 21, 18]
```

Is it a valid min-heap? Explain briefly.

### 4. Parent and Child Indices

Consider a heap containing 12 elements.

#### a. For the node at index `5`, give the index of its:

- parent,
- left child, and
- right child.

State whether each child index is valid.

#### b. Which indices contain leaves?

#### c. What is the index of the final non-leaf node?


### 5. What Can Be Determined?

Answer each question.

#### a. Where is the largest value in a max-heap?

#### b. Where is the smallest value in a min-heap?

#### c. In a max-heap with more than one node, where must a smallest value occur?

#### d. In a min-heap with more than one node, where must a largest value occur?

#### e. Does a heap provide enough information to determine whether a particular value is in the left subtree or right subtree?

---

## Max-Heap Operations

### 6. Insert into a Max-Heap

The following array represents a max-heap:

```text
[42, 19, 35, 7, 12, 28, 31]
```

Insert `50`.

Show:

1. the array immediately after appending `50`,
2. the array after every swap, and
3. the final max-heap.

### 7. Build a Max-Heap by Repeated Insertion

Begin with an empty max-heap and insert the following values in order:

```text
25, 14, 32, 8, 20, 40, 5
```

Write the array after each insertion is complete.

### 8. Remove from a Max-Heap

The following array represents a max-heap:

```text
[96, 72, 88, 41, 65, 80, 75, 12, 30, 50, 60]
```

#### a. Remove the maximum value once.

Show:

- the value removed,
- the array after replacing the root with the final element, and
- the array after every swap.

#### b. Remove the maximum value a second time from the resulting heap.

Again show the intermediate arrays.

---

## Min-Heap Operations

### 9. Insert into a Min-Heap

The following array represents a min-heap:

```text
[4, 9, 7, 15, 12, 11, 10, 20, 18]
```

Insert `2`.

Show:

1. the array immediately after appending `2`,
2. the array after every swap, and
3. the final min-heap.

### 10. Build a Min-Heap by Repeated Insertion

Begin with an empty min-heap and insert the following values in order:

```text
18, 9, 25, 4, 12, 20, 2
```

Write the array after each insertion is complete.

### 11. Remove from a Min-Heap

The following array represents a min-heap:

```text
[3, 8, 5, 14, 11, 9, 7, 20, 17, 13]
```

#### a. Remove the minimum value once.

Show:

- the value removed,
- the array after replacing the root with the final element, and
- the array after every swap.

#### b. Remove the minimum value a second time from the resulting heap.

Again show the intermediate arrays.

---

## Heap Construction

The index of the last non-leaf node is:

```
(n / 2) - 1
```

### 12. Build a Max-Heap using Heapify

Use the heapify algorithm on:

```text
[7, 14, 3, 18, 1, 9, 11, 6, 4, 2]
```

Begin at the final non-leaf node and work backward toward the root. 

rounded down.

Show the array after processing each non-leaf index.


### 13. Build a Min-Heap Using Heapify

Use the heapify algorithm on:

```text
[19, 7, 16, 3, 11, 8, 14, 2, 5, 10]
```

Begin at the final non-leaf node and work backward toward the root.

Show the array after processing each non-leaf index.

---

## Heap Applications and Complexity

### 14. Heap Sort

Use a max-heap to sort the following values into ascending order:

```text
12, 5, 18, 7, 3, 14, 9
```

#### a. Give the max-heap produced by heapify.

#### b. List the values in the order they are removed from the max-heap.

#### c. Give the final values in ascending order.

### 15. Operation Complexity

Give the worst-case time complexity of each operation for a heap containing `n` elements:

#### a. Read the maximum value from a max-heap without removing it.

#### b. Read the minimum value from a min-heap without removing it.

#### c. Insert one value.

#### d. Remove the root.

#### e. Build a heap using Heapify from an unsorted array.

#### f. Search for an arbitrary value.

#### g. Heap sort.

### 16. Choosing a Data Structure

For each situation, state whether a binary heap is a good choice and explain briefly.

#### a. A program repeatedly needs to remove the task with the highest priority.

#### b. A program needs to print all stored values in sorted order many times without modifying the structure.

#### c. A program needs fast access to the smallest value but does not need fast access to the largest value.

#### d. A program needs to search quickly for arbitrary employee ID numbers.

#### e. A program repeatedly inserts events and removes the event with the earliest scheduled time.

---

# Solutions
## 1. Classifying Heaps

### a. **Max-heap.**

```text
[90, 70, 80, 20, 65, 75, 40]
```

Every parent is greater than both of its children.

### b. **Min-heap.**

```text
[4, 8, 6, 12, 10, 9, 7]
```

Every parent is less than both of its children.

### c. **Neither.**

```text
[50, 30, 45, 10, 35, 40, 20]
```

It is not a max-heap because `30` has a child, `35`, that is larger than it. It is not a min-heap because the root, `50`, is larger than its children.

### d.

```text
[3, 5, 4, 9, 8, 7, 6]
```

**Min-heap.**

Every parent is less than both of its children.

---

## 2. Tree to Array

```text
[84, 61, 73, 20, 44, 55, 68, 5, 12]
```

It is a valid max-heap.

---

## 3. Array to Tree

```text
             2
          /     \
         6       4
       /  \     / \
     13    9   8   7
    / \
   21 18
```

It is a valid min-heap because every parent is less than its children.

---

## 4. Parent and Child Indices

### a. For `i = 5`:

- Parent: `(5 - 1) / 2 = 2`
- Left child: `2(5) + 1 = 11`
- Right child: `2(5) + 2 = 12`

Index `11` is valid in a 12-element heap. Index `12` is not valid because the valid indices are `0` through `11`.

### b. For `n = 12`, the leaves begin at index `n / 2 = 6`.

```text
6, 7, 8, 9, 10, 11
```

### c. The final non-leaf node is at:

```text
(n / 2) - 1 = 5
```

---

## 5. What Can Be Determined?

### a. The largest value in a max-heap is at the root.

### b. The smallest value in a min-heap is at the root.

### c. A smallest value in a max-heap must occur at a leaf.

### d. A largest value in a min-heap must occur at a leaf.

### e. No. A heap orders parents relative to children, but it does not impose binary-search-tree ordering between the left and right subtrees.

---

## 6. Insert into a Max-Heap

Starting heap:

```text
[42, 19, 35, 7, 12, 28, 31]
```

Append `50`:

```text
[42, 19, 35, 7, 12, 28, 31, 50]
```

Swap `50` with `7`:

```text
[42, 19, 35, 50, 12, 28, 31, 7]
```

Swap `50` with `19`:

```text
[42, 50, 35, 19, 12, 28, 31, 7]
```

Swap `50` with `42`:

```text
[50, 42, 35, 19, 12, 28, 31, 7]
```

Final heap:

```text
[50, 42, 35, 19, 12, 28, 31, 7]
```

---

## 7. Build a Max-Heap by Repeated Insertion

After inserting `25`:

```text
[25]
```

After inserting `14`:

```text
[25, 14]
```

After inserting `32`:

```text
[32, 14, 25]
```

After inserting `8`:

```text
[32, 14, 25, 8]
```

After inserting `20`:

```text
[32, 20, 25, 8, 14]
```

After inserting `40`:

```text
[40, 20, 32, 8, 14, 25]
```

After inserting `5`:

```text
[40, 20, 32, 8, 14, 25, 5]
```

---

## 8. Remove from a Max-Heap

### a. First removal

Removed value:

```text
96
```

Move `60` to the root:

```text
[60, 72, 88, 41, 65, 80, 75, 12, 30, 50]
```

The larger child is `88`, so swap:

```text
[88, 72, 60, 41, 65, 80, 75, 12, 30, 50]
```

The larger child of `60` is `80`, so swap:

```text
[88, 72, 80, 41, 65, 60, 75, 12, 30, 50]
```

Final heap:

```text
[88, 72, 80, 41, 65, 60, 75, 12, 30, 50]
```

### b. Second removal

Removed value:

```text
88
```

Move `50` to the root:

```text
[50, 72, 80, 41, 65, 60, 75, 12, 30]
```

The larger child is `80`, so swap:

```text
[80, 72, 50, 41, 65, 60, 75, 12, 30]
```

The larger child of `50` is `75`, so swap:

```text
[80, 72, 75, 41, 65, 60, 50, 12, 30]
```

Final heap:

```text
[80, 72, 75, 41, 65, 60, 50, 12, 30]
```

---

## 9. Insert into a Min-Heap

Starting heap:

```text
[4, 9, 7, 15, 12, 11, 10, 20, 18]
```

Append `2`:

```text
[4, 9, 7, 15, 12, 11, 10, 20, 18, 2]
```

Swap `2` with `12`:

```text
[4, 9, 7, 15, 2, 11, 10, 20, 18, 12]
```

Swap `2` with `9`:

```text
[4, 2, 7, 15, 9, 11, 10, 20, 18, 12]
```

Swap `2` with `4`:

```text
[2, 4, 7, 15, 9, 11, 10, 20, 18, 12]
```

Final heap:

```text
[2, 4, 7, 15, 9, 11, 10, 20, 18, 12]
```

---

## 10. Build a Min-Heap by Repeated Insertion

After inserting `18`:

```text
[18]
```

After inserting `9`:

```text
[9, 18]
```

After inserting `25`:

```text
[9, 18, 25]
```

After inserting `4`:

```text
[4, 9, 25, 18]
```

After inserting `12`:

```text
[4, 9, 25, 18, 12]
```

After inserting `20`:

```text
[4, 9, 20, 18, 12, 25]
```

After inserting `2`:

```text
[2, 9, 4, 18, 12, 25, 20]
```

---

## 11. Remove from a Min-Heap

### a. First removal

Removed value:

```text
3
```

Move `13` to the root:

```text
[13, 8, 5, 14, 11, 9, 7, 20, 17]
```

The smaller child is `5`, so swap:

```text
[5, 8, 13, 14, 11, 9, 7, 20, 17]
```

The smaller child of `13` is `7`, so swap:

```text
[5, 8, 7, 14, 11, 9, 13, 20, 17]
```

Final heap:

```text
[5, 8, 7, 14, 11, 9, 13, 20, 17]
```

### b. Second removal

Removed value:

```text
5
```

Move `17` to the root:

```text
[17, 8, 7, 14, 11, 9, 13, 20]
```

The smaller child is `7`, so swap:

```text
[7, 8, 17, 14, 11, 9, 13, 20]
```

The smaller child of `17` is `9`, so swap:

```text
[7, 8, 9, 14, 11, 17, 13, 20]
```

Final heap:

```text
[7, 8, 9, 14, 11, 17, 13, 20]
```

---

## 12. Build a Max-Heap Using Heapify

Starting array:

```text
[7, 14, 3, 18, 1, 9, 11, 6, 4, 2]
```

The final non-leaf index is:

```text
(10 / 2) - 1 = 4
```

After processing index `4`:

```text
[7, 14, 3, 18, 2, 9, 11, 6, 4, 1]
```

After processing index `3`:

```text
[7, 14, 3, 18, 2, 9, 11, 6, 4, 1]
```

After processing index `2`:

```text
[7, 14, 11, 18, 2, 9, 3, 6, 4, 1]
```

After processing index `1`:

```text
[7, 18, 11, 14, 2, 9, 3, 6, 4, 1]
```

After processing index `0`:

```text
[18, 14, 11, 7, 2, 9, 3, 6, 4, 1]
```

Final max-heap:

```text
[18, 14, 11, 7, 2, 9, 3, 6, 4, 1]
```

---

## 13. Build a Min-Heap Using Heapify

Starting array:

```text
[19, 7, 16, 3, 11, 8, 14, 2, 5, 10]
```

The final non-leaf index is `4`.

After processing index `4`:

```text
[19, 7, 16, 3, 10, 8, 14, 2, 5, 11]
```

After processing index `3`:

```text
[19, 7, 16, 2, 10, 8, 14, 3, 5, 11]
```

After processing index `2`:

```text
[19, 7, 8, 2, 10, 16, 14, 3, 5, 11]
```

After processing index `1`:

```text
[19, 2, 8, 3, 10, 16, 14, 7, 5, 11]
```

After processing index `0`:

```text
[2, 3, 8, 5, 10, 16, 14, 7, 19, 11]
```

Final min-heap:

```text
[2, 3, 8, 5, 10, 16, 14, 7, 19, 11]
```

---

## 14. Heap Sort

### a. Max-heap from Heapify:

```text
[18, 7, 14, 5, 3, 12, 9]
```

### b.

Values are removed in descending order:

```text
18, 14, 12, 9, 7, 5, 3
```

### c.

Final ascending order:

```text
3, 5, 7, 9, 12, 14, 18
```

---

## 15. Operation Complexity

| Operation | Worst-Case Time |
|---|---:|
| Read max from a max-heap | `O(1)` |
| Read min from a min-heap | `O(1)` |
| Insert | `O(log n)` |
| Remove root | `O(log n)` |
| Bottom-up heap construction | `O(n)` |
| Search for an arbitrary value | `O(n)` |
| Heap sort | `O(n log n)` |

---

## 16. Choosing a Data Structure

### a. **Yes.** 
A max-heap supports reading the highest-priority task in `O(1)` and removing it in `O(log n)`.

### b. **Usually no.** 
A heap does not maintain all elements in sorted order. Repeatedly producing a sorted traversal would require extra work.

### c. **Yes.** 
A min-heap gives direct access to the smallest value.

### d. **Usually no.** 
Searching for an arbitrary value in a heap is `O(n)`. A hash table would usually be a better choice for exact ID lookup.

### e. **Yes.** 
A min-heap is a common implementation of an event priority queue. The earliest event is stored at the root.
