# Google Test And Debugging Writeup

## Things I Thought To Test
1. swap() actually swaps two values and how this behaves in a larger array
2. min_index_of_array() returns the actual min of array
3. make_sorted() behaves as expected when given both an empty array and multiple elements that are the same


## Bugs

### Bug 1

### Location

``src/sorting.cpp ``

Lines: 29-38

```c++
int* copy_array(int* ar, int len) {
  /**
  * Return a copy of the array
  * @param ar: The array to copy
  * @param len: The length of the array to copy
  * @return: A copy of ar
  */
  int* copy = ar;
  return copy;
}

```

### How the bug was located

When trying to compile the project, an error occurred pointing to an unused parameter in the copy_array() function - sidenote: this is not the intended way to find this bug - I just found it this way.

### Description

This code currently just returns another pointer to the same array - not a copy as it claims. This means that the argument ``int* ar`` and the return value ``copy`` both point to the same address in memory (not exactly a copy)

### Fix 

The code now creates a dynamically sized copy with ``len`` elements of integers (the cast was so the IDE would stop yelling at me). The code then copies each index of `ar[i]` into ``copy[i]``
 
```c++
int* copy_array(int* ar, int len) {
  /**
  * Return a copy of the array
  * @param ar: The array to copy
  * @param len: The length of the array to copy
  * @return: A copy of ar
  */
  int* copy = (int*)calloc(len, sizeof(int));
  for (int i = 0; i < len; ++i) {
    copy[i] = ar[i];
  }
  return copy;
}
```

### Bug 2

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```