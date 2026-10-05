# Binary Search Practice Problem

Given list: 

| list        | 14  | 29  | 43  | 62  | 77  | 82  | 90  | 91  | 93  | 99  |
|:------------|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **`index`** | `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8` | `9` |

How many list elements will be checked to find the value 43 using **binary search**? For determining the median value, consider the first element at index 0 and calculate the indexes with:

$\lfloor \frac{high + low}{2} \rfloor$

Practice the binary search with various values that are both found in the list as well as not found.

*Questions to consider: would a binary search be possible if the values were in descending order? What about random order?*


## Binary Search Practice Problem Solution

Our target search value:  
`value = 43`

> For the calculations we do *integer math*, so we just drop the fraction.

**First iteration**  
The first iteration, we start with the entire list as the search space. So we set the high and low indexes to the lowest (`0`) and highest (`9`). 
The portion of the list we are searching looks like this:

| 14  | 29  | 43  | 62  | 77  | 82  | 90  | 91  | 93  | 99  |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8` | `9` |

```cpp
low  = 0  

high = 9
  
mid  = (9 + 0) / 2 
     = 4
   
list[4] => 77 > 43
```

| 14  | 29  | 43  | 62  |  77   | 82  | 90  | 91  | 93  | 99  |
|:---:|:---:|:---:|:---:|:-----:|:---:|:---:|:---:|:---:|:---:|
| `0` | `1` | `2` | `3` | **4** | `5` | `6` | `7` | `8` | `9` |

**Second Iteration**  
Because our key of `43` is *less than* the median value, we search to the *left* of `77`.  

The low index stays the same.  

We want to eliminate `77` and all values *greater than* (to the right of) `77`.  
To do that, we update the `high` index to the previous `mid` **minus 1**  

The portion of the list remaining to search looks like this:  

| 14  | 29  | 43  | 62  |
|:---:|:---:|:---:|:---:|
| `0` | `1` | `2` | `3` |

```cpp
low  = 0  

high = 4 - 1 
     = 3  

mid  = (3 + 0) / 2 
     = 1

list[1] ==> 29 < 43
```

| 14  |  29   | 43  | 62  | 
|:---:|:-----:|:---:|:---:|
| `0` | **1** | `2` | `3` |

**Third Iteration**  
`43` was greater than the previous median of `29`, so we search to the *right* of `29`.  

This time, we update `low`  eliminating `29` and everything *less than* (to the left of) `29`.  
To do that, we update the `low` index to the previous `mid` **plus 1**

The remaining portion of the list we need to search is now:

| 43  | 62  | 
|:---:|:---:|
| `2` | `3` |

```cpp
low = 1 + 1
    = 2
    
high = 3

mid = (3 + 2) / 2
    = 5 / 2
    = 2
```

|  43   | 62  | 
|:-----:|:---:|
| **2** | `3` |

**43 Found!**  
We found our target value of `43` in **3** iterations, and we checked **3** elements in the list.  
The search index sequence was:
```
4 ==> 1 ==> 2
```