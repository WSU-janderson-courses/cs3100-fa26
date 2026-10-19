# Hash Table Practice

For both exercises, use a hash table with capacity 8 and the hash function

```text
h(k) = k % 8
```

Insert the following keys in order:

```text
10, 18, 26, 7, 15, 23
```

For these problems, duplicate keys are disallowed.

---

## Question 1: Separate Chaining

This hash table resolves collisions using **separate chaining**.

When inserting a key into a nonempty bucket, add the new key to the **front** of the chain.


### A. Insert the keys

Insert all six keys in the given order. Draw the final contents of every bucket.

| Bucket | Chain |
| -----: | :---- |
|      0 |       |
|      1 |       |
|      2 |       |
|      3 |       |
|      4 |       |
|      5 |       |
|      6 |       |
|      7 |       |

### B. Trace a successful search

Trace the search for key `15`.

1. Which bucket is searched?
2. Which keys are examined, and in what order?
3. How many key comparisons are performed?

### C. Trace an unsuccessful search

Trace the search for key `31`.

1. Which bucket is searched?
2. Which keys are examined, and in what order?
3. How many key comparisons are performed?
4. What does the search return?

### D. Remove a key

Remove key `18` from the table.

Draw the affected chain after the removal.

### E. Insert another key

After removing `18`, insert key `34`.

Draw the affected chain after the insertion.

### F. Load factor

After removing `18` and inserting `34`, calculate the table's load factor.

```text
load factor = number of stored keys / number of buckets
```

---

## Question 2: Linear Probing

This hash table resolves collisions using **linear probing**.

Each table position can be in one of three states:

* **Normal:** The position currently contains a key.
* **ESS — Empty Since Start:** The position has never contained a key.
* **EAR — Empty After Removal:** The position previously contained a key that was removed.

Use the following rules:

* Begin probing at index `h(k)`.
* If the position is occupied by a different key, examine the next position.
* Wrap from index 7 back to index 0.
* A search stops when it finds the key or reaches an `ESS` position.
* A search continues past an `EAR` position.
* An insertion may reuse an `EAR` position.

### A. Insert the keys

Insert all six keys in the given order.

For each key, record its starting index and final index.

| Key | Starting index | Final index |
| --: | -------------: | ----------: |
|  10 |                |             |
|  18 |                |             |
|  26 |                |             |
|   7 |                |             |
|  15 |                |             |
|  23 |                |             |

Draw the final table.

| Index | Contents |
| ----: | :------- |
|     0 |          |
|     1 |          |
|     2 |          |
|     3 |          |
|     4 |          |
|     5 |          |
|     6 |          |
|     7 |          |

Use `ESS` for positions that have never contained a key.

### B. Remove a key

Remove key `18`.

Draw the table after the removal.

Use the following labels where appropriate:

* the stored key for an occupied position
* `EAR` for a position emptied by removal
* `ESS` for a position that has never contained a key

### C. Search after a removal

After removing `18`, trace the search for key `26`.

1. What is the starting index?
2. What indices are examined, and in what order?
3. How many probes are performed?
4. Why must the search continue after encountering an `EAR` position?

### D. Reuse an EAR position

After removing `18`, insert key `34`.

1. What is the starting index?
2. What indices are examined?
3. At what index is `34` stored?
4. Draw the resulting table.

### E. Trace an unsuccessful search

After inserting `34`, trace the search for key `31`.

1. What is the starting index?
2. What indices are examined, and in what order?
3. How many probes are performed?
4. At which index does the search stop?
5. Why does the search stop at that position?
6. What does the search return?

### F. Incorrect removal

Suppose removing `18` changed its position to `ESS` instead of `EAR`.

Explain why a later search for key `26` would produce an incorrect result.

---

## Question 3: Compare the Collision Strategies

Answer each question in one or two sentences.

1. Which collision strategy stores multiple keys in the same bucket?
2. Which collision strategy stores every key directly in the table's array?
3. Which collision strategy requires a distinction between `ESS` and `EAR`?
4. Which collision strategy can have a load factor greater than 1?
5. Compare the work required to search for key `31` in the two completed tables.

---

# Solutions

## Question 1: Separate Chaining

The hash values are:

| Key | `h(k)` |
| --: | -----: |
|  10 |      2 |
|  18 |      2 |
|  26 |      2 |
|   7 |      7 |
|  15 |      7 |
|  23 |      7 |

Because new keys are inserted at the front of each chain, the final table is:

| Bucket | Chain            |
| -----: | :--------------- |
|      0 | empty            |
|      1 | empty            |
|      2 | `26 -> 18 -> 10` |
|      3 | empty            |
|      4 | empty            |
|      5 | empty            |
|      6 | empty            |
|      7 | `23 -> 15 -> 7`  |

### B. Search for `15`

The hash value is:

```text
h(15) = 15 % 8 = 7
```

* Bucket searched: 7
* Keys examined: `23`, then `15`
* Key comparisons: 2
* Result: found

### C. Search for `31`

The hash value is:

```text
h(31) = 31 % 8 = 7
```

* Bucket searched: 7
* Keys examined: `23`, `15`, `7`
* Key comparisons: 3
* Result: not found

### D. Remove `18`

Bucket 2 originally contains:

```text
26 -> 18 -> 10
```

After removing `18`, bucket 2 contains:

```text
26 -> 10
```

### E. Insert `34`

The hash value is:

```text
h(34) = 34 % 8 = 2
```

Because insertion occurs at the front, bucket 2 becomes:

```text
34 -> 26 -> 10
```

### F. Load factor

There are six keys stored in eight buckets.

```text
load factor = 6 / 8 = 0.75
```

---

## Question 2: Linear Probing

### A. Insertions

#### Insert `10`

```text
h(10) = 10 % 8 = 2
```

Index 2 is `ESS`, so `10` is stored at index 2.

#### Insert `18`

```text
h(18) = 18 % 8 = 2
```

* Index 2 contains `10`.
* Index 3 is `ESS`.

Therefore, `18` is stored at index 3.

#### Insert `26`

```text
h(26) = 26 % 8 = 2
```

* Index 2 contains `10`.
* Index 3 contains `18`.
* Index 4 is `ESS`.

Therefore, `26` is stored at index 4.

#### Insert `7`

```text
h(7) = 7 % 8 = 7
```

Index 7 is `ESS`, so `7` is stored at index 7.

#### Insert `15`

```text
h(15) = 15 % 8 = 7
```

* Index 7 contains `7`.
* Probing wraps to index 0.
* Index 0 is `ESS`.

Therefore, `15` is stored at index 0.

#### Insert `23`

```text
h(23) = 23 % 8 = 7
```

* Index 7 contains `7`.
* Index 0 contains `15`.
* Index 1 is `ESS`.

Therefore, `23` is stored at index 1.

The completed insertion table is:

| Key | Starting index | Final index |
| --: | -------------: | ----------: |
|  10 |              2 |           2 |
|  18 |              2 |           3 |
|  26 |              2 |           4 |
|   7 |              7 |           7 |
|  15 |              7 |           0 |
|  23 |              7 |           1 |

The final hash table is:

| Index | Contents |
| ----: | :------- |
|     0 | 15       |
|     1 | 23       |
|     2 | 10       |
|     3 | 18       |
|     4 | 26       |
|     5 | ESS      |
|     6 | ESS      |
|     7 | 7        |

### B. Remove `18`

The search for `18` begins at index 2.

* Index 2 contains `10`.
* Index 3 contains `18`.

After `18` is removed, index 3 becomes `EAR`.

| Index | Contents |
| ----: | :------- |
|     0 | 15       |
|     1 | 23       |
|     2 | 10       |
|     3 | EAR      |
|     4 | 26       |
|     5 | ESS      |
|     6 | ESS      |
|     7 | 7        |

### C. Search for `26`

The hash value is:

```text
h(26) = 26 % 8 = 2
```

The probe sequence is:

```text
2, 3, 4
```

* Index 2 contains `10`, so the search continues.
* Index 3 is `EAR`, so the search continues.
* Index 4 contains `26`, so the search succeeds.

Answers:

1. Starting index: 2
2. Indices examined: `2, 3, 4`
3. Probes performed: 3
4. The search must continue past `EAR` because a key may have passed through that position during insertion and been stored later in the probe sequence.

### D. Insert `34`



Because duplicates are disallowed, insertion cannot stop immediately when it reaches the `EAR` at index 3. It must **remember index 3 as the first reusable position** and continue until it finds either:

- `34`, meaning the insertion is rejected as a duplicate, or
- an `ESS`, proving that `34` is not already in the table.

The hash value for `34` is:

```text
h(34) = 34 % 8 = 2
```

The probe sequence is:

```text
2, 3, 4, 5
```

* Index 2 contains `10`.
* Index 3 is `EAR`; remember index 3 but continue
* Index 4 contains `26`
* Index 5 is `ESS`; therefore `34` is not already present
* Insert `34` into the remembered `EAR` positino at index 3.

The resulting table is:

| Index | Contents |
| ----: | :------- |
|     0 | 15       |
|     1 | 23       |
|     2 | 10       |
|     3 | 34       |
|     4 | 26       |
|     5 | ESS      |
|     6 | ESS      |
|     7 | 7        |

### E. Search for `31`

The hash value is:

```text
h(31) = 31 % 8 = 7
```

The probe sequence is:

```text
7, 0, 1, 2, 3, 4, 5
```

* Index 7 contains `7`.
* Index 0 contains `15`.
* Index 1 contains `23`.
* Index 2 contains `10`.
* Index 3 contains `34`.
* Index 4 contains `26`.
* Index 5 is `ESS`.

Answers:

1. Starting index: 7
2. Indices examined: `7, 0, 1, 2, 3, 4, 5`
3. Probes performed: 7
4. The search stops at index 5.
5. It stops because index 5 is `ESS`. No key following this probe sequence could have been inserted beyond an `ESS` position.
6. Result: not found

### F. Incorrect removal

If index 3 were changed to `ESS` after removing `18`, a search for `26` would proceed as follows:

* Index 2 contains `10`.
* Index 3 is incorrectly marked `ESS`.
* The search stops and reports that `26` is not present.

This result is incorrect because `26` is stored at index 4.

The position must be marked `EAR` so that searches continue through the probe sequence.

---

## Question 3: Comparison

1. **Separate chaining** stores multiple keys in the same bucket.

2. **Linear probing** stores every key directly in the table's array.

3. **Linear probing** requires a distinction between `ESS` and `EAR`.

4. **Separate chaining** can have a load factor greater than 1 because a bucket can contain more than one key.

5. Searching for `31` with separate chaining requires three key comparisons. Searching for `31` with linear probing requires seven probes before reaching an `ESS` position.
