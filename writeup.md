# Google Test And Debugging Writeup

## Things I Thought To Test
1. swap() actually swaps two values and how this behaves in a larger array
2. min_index_of_array() returns the actual min of array
3. make_sorted() behaves as expected when given both an empty array and multiple elements that are the same


## Bugs

### Bug 1

### Location

``src/sorting.cpp ``

Lines: 36-38

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

``src/sorting.cpp ``

Lines: 68-72

```c++
void swap(int* a, int* b) {
  /**
 * Swap the values held in a and b.
 * @param a: The address of the first element to swap.
 * @param b: The address of the second element to swap.
 */

  int* temp = a;
  a = b;
  b = temp;
}
```

### How the bug was located

When doing simple tests on the function, the values were not being swapped.

### Description

The function only swaps the memory address of the pointers instead of what values they reference. For the test of simple inputs (single integers) - it would not swap the values.

### Fix

Have the pointers dereferenced in the function to change the information stored at each pointer to swap them around.

```c++
void swap(int* a, int* b) {
  /**
 * Swap the values held in a and b.
 * @param a: The address of the first element to swap.
 * @param b: The address of the second element to swap.
 */

  int temp = *a;
  *a = *b;
  *b = temp;
}
```

### Bug 3

### Location

``src/sortin.cpp``

Lines: 52-60

```c++
int min_index_of_array(int* ar, int len) {
  /**
 * Find the INDEX of the minimum value in ar. If there are multiple values that are
 * the minimum, return the index of the first minimum.
 * @param ar: The array to search through
 * @param len: the number of elements in ar
 * @return: The INDEX of the minimum value in ar
 */

  int min_index = 0;

  for (int i = 1; i < len; ++i) {
    if (ar[i] > ar[min_index]) {
      min_index = i;
    }
  }
  return ar[min_index];
}

```

### How the bug was located

When writing the test cases, found that the return type / value that was being compared was the minimum value not the index of the minimum value

### Description

Two issues with the code include the comparison being flipped
(only updating the ``min_index`` if the value is greater than the current).
Additionally, the returned value is not the index but the value. This could lead to issues 
in the implementation of ``make_sorted()`` since values could be out of range
of the array.

### Fix

The return now just returns the value of ``min_index``. This prevents potential out of index referencing within the function ``make_sorted()``. Also needed to flip the sign since the comparison made before checked if ``ar[i]`` was greater than current ``min_index``

```c++
int min_index_of_array(int* ar, int len) {
  /**
 * Find the INDEX of the minimum value in ar. If there are multiple values that are
 * the minimum, return the index of the first minimum.
 * @param ar: The array to search through
 * @param len: the number of elements in ar
 * @return: The INDEX of the minimum value in ar
 */

  int min_index = 0;

  for (int i = 1; i < len; ++i) {
    if (ar[i] < ar[min_index]) {
      min_index = i;
    }
  }
  return min_index;
}
```