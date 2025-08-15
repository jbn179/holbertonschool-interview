# 🔗 Insert in Sorted Linked List

## 📋 Description

This project implements a function to **insert a number into a sorted singly linked list** while maintaining the sorted order. This is a fundamental algorithm problem that demonstrates pointer manipulation, memory management, and linked list traversal in C.

## 🎯 Problem Statement

Write a function that inserts a number into a sorted (ascending order) singly linked list.

### Requirements
- **Prototype**: `listint_t *insert_node(listint_t **head, int number);`
- Insert the number in the correct position to maintain sorted order
- Return the address of the new node, or `NULL` if it failed
- Handle edge cases: empty list, insertion at beginning, middle, and end

## 🔧 Algorithm Implementation

### Approach: Optimized Linear Search with Single Pointer

```c
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *current;

    if (head == NULL)
        return (NULL);

    /* Create new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    /* If list is empty or number should be inserted at the beginning */
    if (*head == NULL || (*head)->n > number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Find the correct position to insert */
    current = *head;
    while (current->next != NULL && current->next->n < number)
        current = current->next;

    /* Insert the new node after current */
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
```

## 🧠 Algorithm Logic

### Step-by-Step Process

1. **Input Validation**: Check if `head` pointer is valid
2. **Memory Allocation**: Create new node with `malloc()`
3. **Edge Case Handling**: 
   - Empty list → Insert as first node
   - Insert at beginning → New node becomes head
4. **Position Finding**: Traverse list looking ahead to find insertion point
5. **Pointer Manipulation**: Insert new node after `current`

### Visual Example

**Initial List**: `0 -> 1 -> 2 -> 3 -> 4 -> 98 -> 402 -> 1024`

**Insert 27**:
```
Step 1: Traverse until current->next->n >= 27
        current = 4 (next = 98, which is >= 27)

Step 2: Insert new node after current
        4 -> 27 -> 98

Result: 0 -> 1 -> 2 -> 3 -> 4 -> 27 -> 98 -> 402 -> 1024
```

## 📊 Data Structure

### Node Structure
```c
typedef struct listint_s
{
    int n;                    // Data field
    struct listint_s *next;   // Pointer to next node
} listint_t;
```

### Key Properties
- **Singly linked**: Each node points to the next
- **Sorted order**: Ascending by integer value
- **Dynamic size**: Can grow/shrink during runtime

## 🔍 Edge Cases Handled

### 1. Empty List
```c
// Input: head = NULL, number = 5
// Result: [5] -> NULL
```

### 2. Insert at Beginning
```c
// Input: [1, 3, 5], number = 0
// Result: [0, 1, 3, 5]
```

### 3. Insert at End
```c
// Input: [1, 3, 5], number = 10
// Result: [1, 3, 5, 10]
```

### 4. Insert in Middle
```c
// Input: [1, 3, 5], number = 4
// Result: [1, 3, 4, 5]
```

### 5. Duplicate Values
```c
// Input: [1, 3, 5], number = 3
// Result: [1, 3, 3, 5] (allows duplicates)
```

## 🚀 Usage

### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o insert
```

### Running the Program
```bash
./insert
```

### Expected Output
```
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
```

### Code Structure
```
insert_in_sorted_linked_list/
├── lists.h              # Header with struct and prototypes
├── 0-insert_number.c    # Main implementation
├── linked_lists.c       # Helper functions (print, add, free)
├── 0-main.c            # Test cases
├── insert              # Compiled executable
└── README.md           # This documentation
```

## ⚡ Performance Analysis

### Time Complexity
- **Best Case**: O(1) - Insert at beginning
- **Average Case**: O(n/2) - Insert in middle
- **Worst Case**: O(n) - Insert at end
- **Overall**: **O(n)** where n = number of nodes

### Space Complexity
- **O(1)** - Only allocates one new node
- **Optimized**: Uses fewer local variables than traditional approach
- Constant extra space regardless of list size

### 🚀 Optimization Benefits
- **Reduced Memory Footprint**: Only 2 variables instead of 3
- **Cleaner Logic**: Look-ahead approach is more intuitive
- **Better Performance**: Fewer pointer assignments per iteration

## 🛠️ Memory Management

### Safe Allocation
```c
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
    return (NULL);  // Handle allocation failure
```

### Leak Prevention
- Function only allocates memory for new node
- Caller responsible for freeing entire list
- No temporary allocations that could leak

## 🧪 Test Cases

### Test Scenario 1: Normal Insertion
```c
// Initial: [0, 1, 2, 3, 4, 98, 402, 1024]
// Insert: 27
// Expected: [0, 1, 2, 3, 4, 27, 98, 402, 1024]
```

### Test Scenario 2: Insert at Beginning
```c
// Initial: [5, 10, 15]
// Insert: 1
// Expected: [1, 5, 10, 15]
```

### Test Scenario 3: Insert at End
```c
// Initial: [5, 10, 15]
// Insert: 20
// Expected: [5, 10, 15, 20]
```

## 🔧 Helper Functions

### `print_listint()`
- Prints all elements in the list
- Returns the number of nodes
- Used for testing and visualization

### `add_nodeint_end()`
- Adds a node at the end of the list
- Used for initial list construction
- Maintains list structure

### `free_listint()`
- Frees all nodes in the list
- Prevents memory leaks
- Called at program end

## 💡 Key Learning Points

### Pointer Manipulation
- Double pointer (`**head`) for modifying head
- Single traversal pointer with look-ahead technique
- Optimized linking with fewer variables

### Edge Case Handling
- Always check for NULL pointers
- Handle empty list scenarios
- Consider boundary conditions

### Memory Safety
- Check `malloc()` return value
- Proper initialization of new node
- No memory leaks in error paths

## 🎓 Algorithm Concepts

This project demonstrates:
- **Optimized Linked List Traversal**: Look-ahead linear search
- **Efficient Pointer Manipulation**: Minimal variable usage
- **Dynamic Memory Management**: Safe allocation/deallocation
- **Sorted Data Structures**: Maintaining order during insertion
- **Code Optimization**: Reducing complexity while maintaining clarity

## 🔄 Algorithm Comparison

### Traditional vs Optimized Approach

| **Aspect** | **Traditional (3 variables)** | **Optimized (2 variables)** |
|------------|-------------------------------|------------------------------|
| **Variables** | `new_node`, `current`, `prev` | `new_node`, `current` |
| **Logic** | Find position BETWEEN nodes | Find node to insert AFTER |
| **Memory** | Higher stack usage | Lower stack usage |
| **Readability** | More explicit | More elegant |
| **Performance** | Standard | Slightly better |

### Why This Optimization Works
- **Look-ahead technique**: Check `current->next` instead of tracking `prev`
- **Direct insertion**: Insert after `current` rather than between two nodes
- **Same complexity**: Still O(n) but with better constants

## 🚨 Common Pitfalls

1. **Forgetting to update head**: When inserting at beginning
2. **Lost nodes**: Incorrect pointer order during linking
3. **Memory leaks**: Not checking `malloc()` return
4. **Segmentation fault**: Dereferencing NULL pointers
5. **Look-ahead errors**: Not checking `current->next` exists before accessing

---

**Author**: Holberton School Interview Preparation  
**Language**: C  
**Concept**: Linked Lists, Pointer Manipulation  
**Complexity**: O(n) time, O(1) space
