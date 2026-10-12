# Function Complexity

## Exact Runtime Complexity

For the following segments of code, determine the *exact runtime* for each in terms of `n`. For the purposes of these problems, ignore any loop overhead and count how many times each line of code is executed.

### 1. Simple loop   

```c++
int count = 0;
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += i;
    count++;
}
```

### 2. Loop with a different starting point

Assume `n >= 5`

```cpp
int count = 0;
for (int i = 5; i < n; i++) {
    count++;
}
```

### 3. Loop that skips values

Assume `n` is a positive, even integer.

```cpp
int count = 0;
for (int i = 0; i < n; i += 2) {
    count++;
}
```

4. Nested loops

```cpp
int count = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        count++;
    }
}
```

5. Dependent nested loops

```cpp
int count = 0;
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        count++;
    }
}
```

6. Logarithmic loop

Assume `n` is a power of `2` and `n >= 2`
```cpp
int count = 0;
for (int i = 1; i < n; i *= 2) {
    count++;
}
```

After finding `T(n)` for the above problems, determine the `Big-O` for each.

---

## Asymptotic Notation

For each $T(N)$ on the left, select if it is in either

- $O(f(N))$
- $\Omega (f(N))$  
- $\Theta(f(N))$ 

 of the function $f(N)$ on the right.

| $T(N)$              | $O$ \| $\Omega$ \|  $\Theta$ | $f(N)$                |
|---------------------|------------------------------|-----------------------|
| $2N + 13$           |                              | $N^2$                 |
| $N^2 + 3$           |                              | $ 7N^2 $              |
| $N^3$               |                              | $8N^3 + 4N^2 - N - 2$ |
| $90 \log_2 N + 23 $ |                              | $10,000,000$          |
| $2^N$               |                              | $N^2$                 |

---

---

## Solutions

### Exact Runtime Complexity

#### 1. Simple loop

```cpp
int count = 0;
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += i;
    count++;
}
```

| Line | Executions |
|---|---:|
| `int count = 0;` | 1 |
| `int sum = 0;` | 1 |
| `for (...)` | $n$ |
| `sum += i;` | $n$ |
| `count++;` | $n$ |

$$
T(n)=1+1+n+n+n=\boxed{3n+2}
$$

**Big-O:** $O(n)$.

#### 2. Loop with a different starting point

Assume $n\ge 5$.

```cpp
int count = 0;
for (int i = 5; i < n; i++) {
    count++;
}
```

The loop runs for $i=5,6,\dots,n-1$, or $n-5$ iterations.

| Line | Executions |
|---|---:|
| `int count = 0;` | 1 |
| `for (...)` | $n-5$ |
| `count++;` | $n-5$ |

$$
T(n)=1+(n-5)+(n-5)=\boxed{2n-9}
$$

**Big-O:** $O(n)$.

#### 3. Loop that skips values

Assume $n$ is a positive, even integer.

```cpp
int count = 0;
for (int i = 0; i < n; i += 2) {
    count++;
}
```

The loop runs for $i=0,2,4,\dots,n-2$, or $n/2$ iterations.

| Line | Executions |
|---|---:|
| `int count = 0;` | 1 |
| `for (...)` | $n/2$ |
| `count++;` | $n/2$ |

$$
T(n)=1+\frac n2+\frac n2=\boxed{n+1}
$$

**Big-O:** $O(n)$.

#### 4. Nested loops

```cpp
int count = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        count++;
    }
}
```

The outer loop executes $n$ times. For each outer iteration, the inner loop executes $n$ times, for a total of $n^2$ inner iterations.

| Line | Executions |
|---|---:|
| `int count = 0;` | 1 |
| Outer `for` | $n$ |
| Inner `for` | $n^2$ |
| `count++;` | $n^2$ |

$$
T(n)=1+n+n^2+n^2=\boxed{2n^2+n+1}
$$

**Big-O:** $O(n^2)$.

#### 5. Dependent nested loops

```cpp
int count = 0;
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        count++;
    }
}
```

The inner loop performs fewer iterations as `i` increases:

| Outer iteration `i` | Inner iterations |
|---|---:|
| $0$ | $n$ |
| $1$ | $n-1$ |
| $2$ | $n-2$ |
| $\vdots$ | $\vdots$ |
| $n-1$ | $1$ |

Therefore, total inner iterations are

$$
n+(n-1)+\cdots+1=\frac{n(n+1)}2.
$$

| Line | Executions |
|---|---:|
| `int count = 0;` | 1 |
| Outer `for` | $n$ |
| Inner `for` | $\frac{n(n+1)}2$ |
| `count++;` | $\frac{n(n+1)}2$ |

$$
\begin{aligned}
T(n)&=1+n+\frac{n(n+1)}2+\frac{n(n+1)}2\\
&=1+n+n(n+1)\\
&=\boxed{n^2+2n+1}.
\end{aligned}
$$

**Big-O:** $O(n^2)$.

#### 6. Logarithmic loop

Assume $n$ is a power of 2 and $n\ge2$.

```cpp
int count = 0;
for (int i = 1; i < n; i *= 2) {
    count++;
}
```

The values of `i` are $1,2,4,8,\dots,n/2$. After $k$ iterations, `i` equals $2^k$. The loop stops when $2^k=n$, so $k=\log_2 n$.

| Line | Executions |
|---|---:|
| `int count = 0;` | 1 |
| `for (...)` | $\log_2 n$ |
| `count++;` | $\log_2 n$ |

$$
T(n)=1+\log_2 n+\log_2 n=\boxed{2\log_2 n+1}
$$

**Big-O:** $O(\log n)$.

---

#### Summary

| Problem | Exact $T(n)$ | Big-O |
|---|---|---|
| 1. Simple loop | $3n+2$ | $O(n)$ |
| 2. Different starting point | $2n-9$ | $O(n)$ |
| 3. Skipping values | $n+1$ | $O(n)$ |
| 4. Nested loops | $2n^2+n+1$ | $O(n^2)$ |
| 5. Dependent nested loops | $n^2+2n+1$ | $O(n^2)$ |
| 6. Logarithmic loop | $2\log_2 n+1$ | $O(\log n)$ |

### Asymptotic Notation

| $T(N)$              | $O$ \| $\Omega$ \|  $\Theta$ | $f(N)$                |
|---------------------|:----------------------------:|-----------------------|
| $2N + 13$           |             $O$              | $N^2$                 |
| $N^2 + 3$           |           $\Theta$           | $ 7N^2 $              |
| $N^3$               |           $\Theta$           | $8N^3 + 4N^2 - N - 2$ |
| $90 \log_2 N + 23 $ |           $\Omega$           | $10,000,000$          |
| $2^N$               |           $\Omega$           | $N^2$                 |