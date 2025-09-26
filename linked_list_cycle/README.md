# 🔄 Linked List Cycle Detection

## 📋 Description

This project implements the **Floyd's Cycle Detection Algorithm** (also known as the "Tortoise and Hare" algorithm) to detect cycles in a singly linked list. This is a classic algorithm problem that demonstrates advanced pointer manipulation and cycle detection techniques in C programming.

## 🎯 Problem Statement

Write a function that checks if a singly linked list has a cycle in it.

### Requirements
- **Prototype**: `int check_cycle(listint_t *list);`
- Return `0` if there is no cycle, `1` if there is a cycle
- Only allowed functions: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`
- No global variables allowed
- Must be efficient in both time and space complexity

## 🔧 Algorithm Implementation

### Floyd's Cycle Detection Algorithm

```c
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    if (list == NULL)
        return (0);

    slow = list;
    fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         /* Move one step */
        fast = fast->next->next;   /* Move two steps */

        if (slow == fast)          /* Cycle detected */
            return (1);
    }

    return (0);  /* No cycle found */
}
```

## 🧠 Algorithm Logic

### The Tortoise and Hare Technique

1. **Two Pointers**: Use `slow` (tortoise) and `fast` (hare) pointers
2. **Different Speeds**: Slow moves 1 step, fast moves 2 steps per iteration
3. **Cycle Detection**: If there's a cycle, fast will eventually meet slow
4. **Termination**: If fast reaches NULL, there's no cycle

### Mathematical Proof

If there's a cycle:
- **Slow pointer** travels distance `d` in `d` steps
- **Fast pointer** travels distance `2d` in `d` steps  
- **Inside cycle**: Fast gains 1 step on slow per iteration
- **Guaranteed meeting**: Fast will catch up to slow within cycle length

### Visual Example

**List with cycle**:
```
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         |
          +-------- 6
```

**Execution trace**:
```
Step 0: slow=1, fast=1
Step 1: slow=2, fast=3
Step 2: slow=3, fast=5
Step 3: slow=4, fast=2 (wrapped around)
Step 4: slow=5, fast=4
Step 5: slow=6, fast=6 -> CYCLE DETECTED!
```

## 📊 Data Structure

### Node Structure
```c
typedef struct listint_s
{
    int n;                    /* Data field */
    struct listint_s *next;   /* Pointer to next node */
} listint_t;
```

### Cycle Types
- **No Cycle**: List terminates with NULL
- **Self Loop**: Node points to itself
- **Distant Cycle**: Cycle forms later in the list
- **Immediate Cycle**: Head participates in cycle

## 🔍 Edge Cases Handled

### 1. Empty List
```c
// Input: list = NULL
// Result: 0 (no cycle)
```

### 2. Single Node - No Cycle
```c
// Input: [1] -> NULL
// Result: 0 (no cycle)
```

### 3. Single Node - Self Loop
```c
// Input: [1] -> [1] (points to itself)
// Result: 1 (cycle detected)
```

### 4. Two Node Cycle
```c
// Input: [1] <-> [2] (mutual pointing)
// Result: 1 (cycle detected)
```

### 5. Long List with Distant Cycle
```c
// Input: 1->2->3->4->5->6->3 (cycle at position 3)
// Result: 1 (cycle detected)
```

## 🚀 Usage

### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

### Running the Program
```bash
./cycle
```

### Expected Output
```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

### Code Structure
```
linked_list_cycle/
├── lists.h              # Header with struct and prototypes
├── 0-check_cycle.c      # Main cycle detection implementation
├── 0-linked_lists.c     # Helper functions (print, add, free)
├── 0-main.c            # Test cases with cycle creation
├── cycle               # Compiled executable
└── README.md           # This documentation
```

## ⚡ Performance Analysis

### Time Complexity
- **Best Case**: O(1) - Empty or single node list
- **Average Case**: O(n) - No cycle, traverse entire list
- **Worst Case**: O(n) - Cycle detected after full traversal
- **Overall**: **O(n)** where n = number of nodes

### Space Complexity
- **O(1)** - Only uses two pointer variables
- **Constant space** regardless of list size
- **No additional data structures** required

### 🚀 Why Floyd's Algorithm is Optimal

| **Approach** | **Time** | **Space** | **Notes** |
|--------------|----------|-----------|-----------|
| **Hash Set** | O(n) | O(n) | Store visited nodes |
| **Mark Nodes** | O(n) | O(1) | Modifies original data |
| **Floyd's Algorithm** | **O(n)** | **O(1)** | **No modification needed** |

## 🛠️ Algorithm Variants

### Alternative Approaches (Not Used)

#### 1. Hash Table Approach
```c
/* Uses extra O(n) space */
int check_cycle_hash(listint_t *list)
{
    /* Store addresses in hash table */
    /* Check if current address already exists */
}
```

#### 2. Node Marking Approach
```c
/* Modifies original nodes */
int check_cycle_mark(listint_t *list)
{
    /* Mark visited nodes */
    /* Check if node already marked */
}
```

### Why Floyd's Algorithm is Preferred
- **Space Efficient**: O(1) space complexity
- **Non-Destructive**: Doesn't modify original list
- **Simple Implementation**: Easy to understand and implement
- **Mathematical Guarantee**: Provably correct

## 🧪 Test Cases

### Test Scenario 1: Linear List (No Cycle)
```c
// Create: 1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
// Expected: 0 (no cycle)
// Behavior: fast reaches NULL, terminates
```

### Test Scenario 2: Created Cycle
```c
// Original: 1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
// Modify: Make node at position 4 point back to head
// Result: 1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -> (back to 1024)
// Expected: 1 (cycle detected)
```

### Detailed Test Execution
```
Initial state: No cycle
- slow and fast start at head (1024)
- fast reaches NULL -> return 0

Modified state: Cycle created
- slow=1024, fast=1024 (start)
- slow=402, fast=98 (after 1 iteration)  
- slow=98, fast=3 (after 2 iterations)
- ... (continues until they meet)
- Meeting point detected -> return 1
```

## 🔧 Helper Functions

### `print_listint()`
```c
size_t print_listint(const listint_t *h)
{
    /* Prints all elements (careful with cycles!) */
    /* Returns count of nodes printed */
}
```

### `add_nodeint()`
```c
listint_t *add_nodeint(listint_t **head, const int n)
{
    /* Adds new node at beginning of list */
    /* Returns pointer to new node */
}
```

### `free_listint()`
```c
void free_listint(listint_t *head)
{
    /* Frees all nodes in non-cyclic list */
    /* WARNING: Don't use on cyclic lists! */
}
```

## 💡 Key Learning Points

### Pointer Arithmetic
- **Dual pointer technique**: Different speeds for cycle detection
- **Null checking**: Essential for preventing segmentation faults  
- **Pointer advancement**: Understanding next and next->next

### Mathematical Concepts
- **Modular arithmetic**: Why fast pointer catches slow in cycle
- **Pigeonhole principle**: Limited positions in cycle guarantee meeting
- **Loop invariants**: Maintaining relative positions between pointers

### Memory Safety
- **Boundary checking**: Always verify `fast->next` exists
- **NULL handling**: Handle empty lists gracefully
- **No memory allocation**: Pure pointer manipulation

## 🎓 Algorithm Concepts

This project demonstrates:
- **Floyd's Cycle Detection**: Classic two-pointer technique
- **Space-Time Tradeoffs**: O(1) space vs O(n) space alternatives  
- **Pointer Manipulation**: Advanced linked list traversal
- **Mathematical Reasoning**: Proof-based algorithm design
- **Edge Case Handling**: Robust input validation

## 🔄 Algorithm Applications

### Real-World Uses
1. **Infinite Loop Detection**: In program analysis
2. **Dependency Cycle Detection**: In build systems
3. **Graph Cycle Detection**: In network analysis
4. **Memory Leak Detection**: In garbage collectors
5. **Duplicate Detection**: In various algorithms

### Interview Relevance
- **Common Question**: Frequently asked in technical interviews
- **Optimization Focus**: Tests understanding of space complexity
- **Edge Case Testing**: Validates thorough thinking
- **Code Quality**: Tests clean implementation skills

## 🚨 Common Pitfalls

1. **Null Pointer Dereference**: Not checking `fast->next` before `fast->next->next`
2. **Infinite Loops**: In print functions with cyclic lists
3. **Memory Management**: Trying to free cyclic lists normally
4. **Edge Cases**: Forgetting empty list or single node scenarios
5. **Speed Confusion**: Using wrong pointer advancement ratios

### Correct vs Incorrect

**❌ Incorrect**:
```c
while (fast != NULL)
{
    slow = slow->next;
    fast = fast->next->next;  /* Might dereference NULL! */
}
```

**✅ Correct**:
```c
while (fast != NULL && fast->next != NULL)
{
    slow = slow->next;
    fast = fast->next->next;  /* Safe advancement */
}
```

## 🛠️ Extension Possibilities

1. **Find Cycle Start**: Detect where the cycle begins
2. **Cycle Length**: Calculate the length of the cycle
3. **Remove Cycle**: Break the cycle and make list linear
4. **Multiple Cycles**: Detect multiple cycles in complex structures
5. **Generic Types**: Template version for different data types

### Advanced: Finding Cycle Start
```c
listint_t *find_cycle_start(listint_t *list)
{
    /* After detecting cycle with Floyd's algorithm */
    /* Reset one pointer to head */
    /* Move both pointers one step at a time */
    /* Meeting point is the cycle start */
}
```

---

**Author**: Holberton School Interview Preparation  
**Language**: C  
**Concept**: Cycle Detection, Pointer Manipulation  
**Complexity**: O(n) time, O(1) space  
**Algorithm**: Floyd's Cycle Detection (Tortoise and Hare)