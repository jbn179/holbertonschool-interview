# 🌳 Binary Tree - Heap Insert

## 📋 Description

This project implements functions to **create binary tree nodes** and **insert values into a Max Heap** data structure. It demonstrates fundamental concepts of binary trees, heap properties, and tree traversal algorithms in C programming.

## 🎯 Problem Statement

Implement two main functions:

1. **Binary Tree Node Creation**: Create individual nodes for binary trees
2. **Max Heap Insertion**: Insert values into a Max Heap while maintaining heap properties

### Requirements

#### Task 0: Binary Tree Node
- **Prototype**: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- Create a binary tree node with given parent and value
- Return pointer to the new node, or `NULL` on failure

#### Task 1: Heap Insert
- **Prototype**: `heap_t *heap_insert(heap_t **root, int value);`
- Insert a value in a Max Heap
- Return pointer to the created node, or `NULL` on failure
- Must maintain Max Heap properties after insertion

## 🔧 Algorithm Implementation

### Binary Tree Node Creation

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);
    
    /* Set the value of the new node and its parent */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return (new_node);
}
```

### Max Heap Insertion Algorithm

The heap insertion follows a **three-step process**:

1. **Position Finding**: Determine where to insert the new node
2. **Tree Insertion**: Place the node at the correct level-order position
3. **Heapify Up**: Restore Max Heap property by bubbling up

```c
heap_t *heap_insert(heap_t **root, int value)
{
    int size;
    heap_t *new_node = NULL;

    if (!root)
        return (NULL);
    
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);
    
    /* Handle empty heap */
    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }
    
    /* Find insertion position and insert */
    size = node_count(*root) + 1;
    *root = ins_max_heap(*root, new_node, 0, size - 1);
    
    /* Restore heap property */
    return (bottom_up_heapify(new_node));
}
```

## 🧠 Algorithm Logic

### Step-by-Step Heap Insertion

1. **Count Nodes**: Determine total number of nodes in heap
2. **Calculate Position**: Use binary representation to find insertion path
3. **Navigate Tree**: Follow path to insertion point using level-order traversal
4. **Insert Node**: Place new node at correct position
5. **Heapify Up**: Swap with parent until Max Heap property is restored

### Visual Example

**Insert 50 into existing heap**:

```
Initial Heap:
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Step 1: Count = 7, New position = 8 (binary: 1000)
Step 2: Follow path: Root -> Left -> Left -> Left
Step 3: Insert 50 as left child of 46
Step 4: Heapify up (50 > 46? No, stop)

Final Heap:
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
```

## 📊 Data Structure

### Binary Tree Node Structure
```c
typedef struct binary_tree_s
{
    int n;                        // Value stored in the node
    struct binary_tree_s *parent; // Pointer to parent node
    struct binary_tree_s *left;   // Pointer to left child
    struct binary_tree_s *right;  // Pointer to right child
} binary_tree_t;

typedef struct binary_tree_s heap_t;  // Heap is a binary tree
```

### Max Heap Properties
- **Complete Binary Tree**: All levels filled except possibly the last
- **Max Heap Property**: Parent ≥ all children
- **Level-Order Insertion**: New nodes added left-to-right on last level

## 🔍 Helper Functions

### 1. Node Count Function
```c
int node_count(const heap_t *tree)
{
    if (!tree)
        return (0);
    return (1 + node_count(tree->left) + node_count(tree->right));
}
```
- **Purpose**: Count total nodes in the tree
- **Time Complexity**: O(n)
- **Space Complexity**: O(log n) - recursion depth

### 2. Heap Insertion Helper
```c
heap_t *ins_max_heap(heap_t *node, heap_t *new_node, 
                      int index, int new_node_index)
```
- **Purpose**: Navigate to insertion position using binary indexing
- **Algorithm**: Uses complete binary tree index arithmetic
- **Key Insight**: For node at index i, children are at 2i+1 and 2i+2

### 3. Bottom-Up Heapify
```c
heap_t *bottom_up_heapify(heap_t *node)
{
    heap_t *temp = node;
    int temp_n;

    while (temp->parent && temp->n > temp->parent->n)
    {
        /* Swap values with parent */
        temp_n = temp->n;
        temp->n = temp->parent->n;
        temp->parent->n = temp_n;
        temp = temp->parent;
    }
    return (temp);
}
```
- **Purpose**: Restore Max Heap property after insertion
- **Method**: Bubble up by swapping values with parent
- **Termination**: Stops when parent ≥ current or reaches root

## 🚀 Usage

### Compilation
```bash
# Task 0: Binary Tree Node
gcc -Wall -Werror -Wextra -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node

# Task 1: Heap Insert
gcc -Wall -Werror -Wextra -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
```

### Running the Programs
```bash
# Test binary tree node creation
./0-node

# Test heap insertion
./1-heap_insert
```

### Expected Output

**Binary Tree Node (Task 0)**:
```
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
```

**Heap Insert (Task 1)**:
```
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

# ... (continues with more insertions)
```

### Code Structure
```
heap_insert/
├── binary_trees.h        # Header with structs and prototypes
├── 0-binary_tree_node.c  # Binary tree node creation
├── 1-heap_insert.c       # Max heap insertion implementation
├── binary_tree_print.c   # Tree visualization function
├── 0-main.c             # Test for binary tree node
├── 1-main.c             # Test for heap insertion
├── 0-node               # Compiled binary tree test
├── 1-heap_insert        # Compiled heap test
└── README.md            # This documentation
```

## ⚡ Performance Analysis

### Time Complexity

| **Operation** | **Best Case** | **Average Case** | **Worst Case** |
|---------------|---------------|------------------|----------------|
| **Node Creation** | O(1) | O(1) | O(1) |
| **Node Count** | O(n) | O(n) | O(n) |
| **Find Position** | O(log n) | O(log n) | O(log n) |
| **Heapify Up** | O(1) | O(log n) | O(log n) |
| **Overall Insert** | **O(n)** | **O(n)** | **O(n)** |

### Space Complexity
- **O(log n)** for recursion stack in position finding
- **O(1)** additional space for variables
- **Total**: **O(log n)**

### 🚀 Optimization Opportunities
1. **Iterative Node Count**: Could use parent pointers for O(log n) counting
2. **Path Caching**: Store insertion path for repeated insertions
3. **Array Representation**: Use array for O(1) insertion (trade-off: fixed size)

## 🔧 Binary Index Mathematics

### Complete Binary Tree Indexing
```
For a complete binary tree with 0-based indexing:
- Root: index 0
- For node at index i:
  - Left child: 2i + 1
  - Right child: 2i + 2
  - Parent: (i - 1) / 2

Binary representation determines path:
- Size 8 (binary: 1000) → path: follow leftmost bits
- Size 5 (binary: 101) → path: Root → Right → Left
```

### Path Finding Algorithm
```
Position 7 in tree of size 8:
Binary: 1000 (ignore leading 1)
Path: 000 → Left, Left, Left from root
```

## 🧪 Test Cases

### Edge Cases Handled

1. **Empty Heap**: First insertion creates root
2. **Single Node**: Second insertion becomes left child
3. **Complete Levels**: Insertion starts new level
4. **Heapify Scenarios**: Values requiring different bubble-up distances

### Test Scenario 1: Progressive Insertion
```
Insert sequence: [98, 402, 12, 46, 128, 256, 512, 50]

Step-by-step heap evolution:
98 → [402, 98] → [402, 98, 12] → [402, 98, 12, 46] → ...
```

### Test Scenario 2: Heapify Analysis
```
Insert 600 into [512, 128, 402, 46, 98, 12, 256]:
1. Insert at position 8 (next available)
2. Compare 600 with parent 128
3. Swap: 600 bubbles up to position 1
4. Compare 600 with parent 512
5. Swap: 600 becomes new root
```

## 💡 Key Learning Points

### Binary Tree Concepts
- **Complete vs Full Trees**: Understanding heap structure requirements
- **Level-Order Traversal**: Insertion follows breadth-first pattern
- **Tree Navigation**: Using mathematical relationships between indices

### Heap Properties
- **Max Heap vs Min Heap**: Parent-child value relationships
- **Heap vs BST**: Different ordering properties and use cases
- **Dynamic Maintenance**: Preserving properties during modifications

### Memory Management
- **Safe Allocation**: Always check `malloc()` return values
- **Parent-Child Linking**: Proper bidirectional pointer setup
- **Error Handling**: Graceful failure on allocation errors

## 🎓 Algorithm Concepts

This project demonstrates:
- **Complete Binary Tree Construction**: Level-order insertion patterns
- **Heap Property Maintenance**: Bottom-up heapification
- **Tree Traversal Algorithms**: Position finding using mathematical indices
- **Recursive Tree Operations**: Node counting and structure manipulation
- **Memory Management**: Dynamic node allocation and linking

## 🔄 Algorithm Comparison

### Heap Insert vs Other Tree Operations

| **Operation** | **BST Insert** | **AVL Insert** | **Heap Insert** |
|---------------|----------------|----------------|-----------------|
| **Time** | O(log n) avg, O(n) worst | O(log n) | O(n) current* |
| **Property** | Ordering | Balance + Ordering | Complete + Max |
| **Use Case** | Search/Sort | Balanced search | Priority Queue |

*Note: Can be optimized to O(log n) with iterative node counting

### Design Trade-offs
- **Array vs Pointer**: Array representation enables O(1) access but limits flexibility
- **Recursive vs Iterative**: Current recursive approach is cleaner but uses stack space
- **Value vs Pointer Swapping**: Swapping values is simpler than restructuring pointers

## 🚨 Common Pitfalls

1. **Index Calculation**: Off-by-one errors in binary index math
2. **Heapify Direction**: Confusing bottom-up (insertion) vs top-down (deletion)
3. **NULL Handling**: Not checking for empty heap cases
4. **Memory Leaks**: Forgetting to handle allocation failures
5. **Parent Pointers**: Incorrectly setting parent-child relationships

## 🛠️ Extension Possibilities

1. **Heap Delete**: Remove root while maintaining heap property
2. **Heap Sort**: Use heap for O(n log n) sorting algorithm
3. **Priority Queue**: Implement priority queue interface
4. **Min Heap**: Adapt algorithm for minimum heap
5. **Iterative Optimization**: Replace recursive counting with iterative approach

---

**Author**: Holberton School Interview Preparation  
**Language**: C  
**Concepts**: Binary Trees, Heaps, Tree Traversal  
**Complexity**: O(n) time, O(log n) space
