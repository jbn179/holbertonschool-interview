# Sorted Array to AVL Tree

This project implements a function that builds an AVL (Adelson-Velsky and Landis) tree from a sorted array.

## Description

An AVL tree is a self-balancing binary search tree where the heights of the two child subtrees of any node differ by at most one. This implementation creates a balanced AVL tree from a sorted array without requiring any rotations.

## Algorithm

The algorithm uses a divide-and-conquer approach:
1. Select the middle element of the array as the root using `mid = start + (end - start) / 2` (overflow-safe calculation)
2. Recursively build the left subtree from elements before the middle
3. Recursively build the right subtree from elements after the middle

This ensures the tree is naturally balanced since we're working with a sorted array.

### Key Features
- **Overflow-safe middle calculation**: Uses `start + (end - start) / 2` instead of `(start + end) / 2` to prevent integer overflow on large arrays
- **Modular design**: Separated into three clean functions for readability and maintainability
- **Parent tracking**: Each node maintains a pointer to its parent for tree traversal

## Implementation Details

The implementation consists of **3 functions** (respecting the constraint):

### `create_node(avl_t *parent, int value)`
Creates and initializes a new AVL tree node with the given value and parent pointer.

### `build_avl(int *array, int start, int end, avl_t *parent)`
Recursive helper function that:
- Calculates the middle index using overflow-safe formula: `mid = start + (end - start) / 2`
- Creates a node with the middle element
- Recursively builds left subtree with elements `[start...mid-1]`
- Recursively builds right subtree with elements `[mid+1...end]`

### `sorted_array_to_avl(int *array, size_t size)`
Main entry point that validates input and initiates the recursive tree building.

## Files

- `binary_trees.h` - Header file containing structure definitions and function prototypes
- `0-sorted_array_to_avl.c` - Main implementation (3 functions, overflow-safe)
- `0-main.c` - Test file (not pushed to repo)
- `binary_tree_print.c` - Tree visualization function (not pushed to repo)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

## Usage

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

**Parameters:**
- `array` - Pointer to the first element of the sorted array
- `size` - Number of elements in the array

**Return:**
- Pointer to the root node of the created AVL tree
- `NULL` on failure

## Example

```c
int array[] = {1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98};
size_t n = sizeof(array) / sizeof(array[0]);

avl_t *tree = sorted_array_to_avl(array, n);
binary_tree_print(tree);
```

**Output:**
```
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
```

## Requirements

- Ubuntu 14.04 LTS
- gcc 4.8.4 with flags: `-Wall -Werror -Wextra -pedantic`
- Code must follow Betty style
- Maximum 3 functions per file
- No global variables
- Standard library allowed
- No rotations needed (naturally balanced from sorted input)

## Complexity

- **Time Complexity**: O(n) - visits each element once
- **Space Complexity**: O(log n) - recursion depth for a balanced tree

## Why This Implementation is Robust

1. **Overflow Protection**: The middle calculation `start + (end - start) / 2` prevents integer overflow that could occur with `(start + end) / 2` on very large indices
2. **Memory Safety**: Checks for NULL on every malloc call
3. **Edge Cases**: Handles empty arrays and NULL pointers gracefully
4. **Parent Tracking**: Maintains bidirectional tree navigation capability

## Author

Holberton School Interview Preparation Project
