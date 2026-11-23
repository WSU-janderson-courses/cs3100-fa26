# CS 3100/5100 — Graph Practice

Show intermediate work for each trace. For DFS layers, put the root in layer 0 and each child one layer below its parent in the DFS tree.

## 1. BFS, DFS, and traversal trees

This undirected, unweighted graph is given as an adjacency list.

| Vertex | Neighbors |
| --- | --- |
| A | B, C |
| B | A, D, E |
| C | A, E, F |
| D | B, G |
| E | B, C, G |
| F | C, G |
| G | D, E, F |

1. Run BFS from A. Consider neighbors in the order listed and mark a vertex visited when it is enqueued. Record the queue, front to back, after processing each vertex. Give each vertex's distance and predecessor.
2. Use the BFS predecessor chain to recover a shortest path from A to G. Give a different path of the same length.
3. Run recursive DFS from A using the same neighbor order. Mark each vertex visited on entry. Give the discovery order, finish order, and DFS tree edges. Write out the vertices in each layer of the DFS tree.
4. Give the A-to-F path in each traversal tree. How many edges does each path use?

## 2. Directed edges and unreachable vertices

The outgoing adjacency lists are `P: Q, R`, `Q: S`, `R: S, T`, `S: P`, `T: —`, `U: R`, and `V: —`. A dash means the list is empty.

1. Run BFS from P. Give the discovery order and the distance to every vertex. Then run recursive DFS from P, considering neighbors in the order listed. Give the discovery order and write out the vertices in each layer of the DFS tree.
2. If BFS starts at U instead, give a shortest path to P. Explain why P cannot reach U even though U can reach P.
3. Build a DFS forest by scanning possible roots alphabetically and using the same visited set across all recursive calls. Give the roots and the vertices discovered in each tree. Write out the layers of each tree, starting at layer 0 for each root.
4. What is the worst-case running time to traverse an entire graph with adjacency lists? With an adjacency matrix? Explain what work each representation requires.

## 3. Dijkstra's algorithm 

Use the following undirected weighted edges. Start at A.

| Edge | Weight |
| --- | ---: |
| A–B | 5 |
| A–C | 1 |
| B–C | 2 |
| B–D | 3 |
| C–D | 8 |
| C–E | 10 |
| D–E | 2 |

1. Make a trace table with a column for the vertex selected and a distance/predecessor column for every vertex. Include the initialization row and one row after each selected vertex's edges have been processed.
2. Recover a minimum-weight path from A to E from the predecessors and give its total weight. Give a path with fewer edges and state its weight.

---

## Answer key

### 1. BFS, DFS, and traversal trees

| Processed | Queue afterward |
| --- | --- |
| A | B, C |
| B | C, D, E |
| C | D, E, F |
| D | E, F, G |
| E | F, G |
| F | G |
| G | empty |

| Vertex | Distance | Predecessor |
| --- | ---: | --- |
| A | 0 | — |
| B | 1 | A |
| C | 1 | A |
| D | 2 | B |
| E | 2 | B |
| F | 2 | C |
| G | 3 | D |

The predecessor chain gives A–B–D–G. A–C–F–G also has three edges. DFS discovers A, B, D, G, E, C, F and finishes F, C, E, G, D, B, A. Its tree edges are A–B, B–D, D–G, G–E, E–C, and C–F. The BFS tree path to F is A–C–F (2 edges). The DFS tree path is A–B–D–G–E–C–F (6 edges).

| DFS layer | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Vertices | A | B | D | G | E | C | F |

### 2. Directed edges and unreachable vertices

1. BFS discovers P, Q, R, S, T. Distances in that order are 0, 1, 1, 2, 2. U and V have distance ∞. DFS discovers P, Q, S, R, T. The DFS layers are {P} at layer 0, {Q, R} at layer 1, and {S, T} at layer 2.
2. U → R → S → P has length 3. No edge enters U.
3. The forest roots are P, U, V. The first tree contains P, Q, S, R, T in discovery order. The tree rooted at P has the layers shown in part 1. The other two trees each have only layer 0, containing {U} and {V}, respectively.
4. With adjacency lists, checking every vertex and scanning every list takes Θ(V + E). With a matrix, scanning a row of V entries for each vertex takes Θ(V²).

### 3. Dijkstra's algorithm

| Selected | A | B | C | D | E |
| --- | --- | --- | --- | --- | --- |
| Initialization | 0/— | ∞/— | ∞/— | ∞/— | ∞/— |
| A | 0/— | 5/A | 1/A | ∞/— | ∞/— |
| C | 0/— | 3/C | 1/A | 9/C | 11/C |
| B | 0/— | 3/C | 1/A | 6/B | 11/C |
| D | 0/— | 3/C | 1/A | 6/B | 8/D |
| E | 0/— | 3/C | 1/A | 6/B | 8/D |

The minimum-weight path is A–C–B–D–E with weight 8. A–C–E uses two edges and has weight 11.
