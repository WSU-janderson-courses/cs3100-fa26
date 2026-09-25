## Linked List Pointer Practice

Consider this code:

```cpp
class Node {
public:
    int data;
    Node* next = nullptr;
};

int main() {
    Node* listHead = new Node;
    listHead->data = 10;

    Node* tail = listHead;

    for (int i = 20; i <= 50; i += 10) {
        Node* newNode = new Node;
        newNode->data = i;

        tail->next = newNode;
        tail = newNode;
    }

    Node* current = listHead;
    Node* previous = nullptr;

    for (int i = 0; i < 2; i++) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    current->next = listHead;
    listHead = current;
}
```

### Practice 1: Stack vs Heap

For each variable or object below, say whether it is stored on the stack or heap.

| Item                                            | Stack or Heap? |
| ----------------------------------------------- | -------------- |
| `listHead`                                      |                |
| the first `Node` object created with `new Node` |                |
| `tail`                                          |                |
| `newNode`                                       |                |
| the node whose `data` is `30`                   |                |
| `current`                                       |                |
| `previous`                                      |                |

---

### Practice 2: Trace the First Loop

Complete the table showing the list after each iteration of the first `for` loop.

Before the loop begins:

```text
listHead -> 10
```

| Iteration | Value of `i` | List after the iteration |
| --------- | -----------: | ------------------------ |
| 1         |           20 |                          |
| 2         |           30 |                          |
| 3         |           40 |                          |
| 4         |           50 |                          |

---

### Practice 3: Trace `current` and `previous`

After the first loop completes, the list is:

```text
listHead -> 10 -> 20 -> 30 -> 40 -> 50
```

Complete the table for the second loop.

```cpp
Node* current = listHead;
Node* previous = nullptr;

for (int i = 0; i < 2; i++) {
    previous = current;
    current = current->next;
}
```

| Moment            | `previous` points to | `current` points to |
| ----------------- | -------------------- | ------------------- |
| Before the loop   |                      |                     |
| After iteration 1 |                      |                     |
| After iteration 2 |                      |                     |

---

### Practice 4: Draw the List After Each Pointer Statement

Start with this list:

```text
listHead -> 10 -> 20 -> 30 -> 40 -> 50
```

After the second loop:

```text
previous points to 20
current points to 30
```

Draw the list after this line:

```cpp
previous->next = current->next;
```

Then draw the list after this line:

```cpp
current->next = listHead;
```

Then draw the final list after this line:

```cpp
listHead = current;
```

---

### Practice 5: Explain in Words

In your own words, explain what the final three pointer statements do.

```cpp
previous->next = current->next;
current->next = listHead;
listHead = current;
```

Your explanation should mention:

* which node is removed from its original position
* whether any new nodes are created
* whether any node data values are changed
* what value is at the head of the list at the end
