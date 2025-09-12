# 🔍 Linked List Palindrome Checker
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Betty Style](https://img.shields.io/badge/code%20style-Betty-brightgreen.svg)](https://github.com/holbertonschool/Betty)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
> An efficient algorithm to check if a singly linked list is a palindrome in **O(n) time** and **O(1) space**! 🚀
## 📋 Table of Contents
- [Overview](#overview)
- [Algorithm Explanation](#algorithm-explanation)
- [Files Structure](#files-structure)
- [Compilation & Usage](#compilation--usage)
- [Examples](#examples)
- [Complexity Analysis](#complexity-analysis)
- [Author](#author)
## 🎯 Overview
This project implements an optimal solution to determine if a singly linked list reads the same forwards and backwards (palindrome). The algorithm uses the **"tortoise and hare"** technique combined with **in-place list reversal**.
### ✨ Key Features
- **Time Complexity**: O(n) - single pass through the list
- **Space Complexity**: O(1) - no additional data structures
- **Non-destructive**: Original list structure is restored
- **Handles all edge cases**: Empty lists, single nodes, even/odd length lists
## 🧠 Algorithm Explanation
### The 5-Step Approach
```
1️⃣ Handle Edge Cases
   └── Empty list or single node → palindrome
2️⃣ Find Middle (Tortoise & Hare)
   └── slow pointer moves 1 step, fast pointer moves 2 steps
3️⃣ Split & Reverse
   └── Split list at middle, reverse second half
4️⃣ Compare Halves
   └── Compare first half with reversed second half
5️⃣ Restore Original
   └── Reverse second half back and reconnect
```
### Visual Example
```
Original:  1 → 2 → 3 → 2 → 1 → NULL
Step 1: ✓ More than one element
Step 2: Find middle (tortoise & hare)
        slow=3, prev_slow=2
Step 3: Split and reverse
        First:  1 → 2 → NULL
        Second: 1 → 2 → 3 → NULL (reversed)
Step 4: Compare
        1 vs 1 ✓
        2 vs 2 ✓
        → PALINDROME! 🎉
Step 5: Restore
        1 → 2 → 3 → 2 → 1 → NULL
```
## 📁 Files Structure
```
linked_list_palindrome/
├── 0-is_palindrome.c    # Main algorithm implementation
├── linked_lists.c       # Utility functions (print, add, free)
├── lists.h             # Header file with struct definition
├── 0-main.c            # Basic test file
├── test_complet.c      # Comprehensive test suite
└── README.md           # This file
```
### 🔧 Core Functions
| Function | Description |
|----------|-------------|
| `is_palindrome()` | Main function - checks if list is palindrome |
| `reverse()` | Helper function - reverses a linked list |
| `print_listint()` | Utility - prints all list elements |
| `add_nodeint_end()` | Utility - adds node at end of list |
| `free_listint()` | Utility - frees entire list |
## 🛠️ Compilation & Usage
### Prerequisites
- GCC compiler
- Betty linter (optional, for code style checking)
### Compile & Run
```bash
# Basic compilation
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
# Run the test
./palindrome
# For comprehensive testing
gcc -Wall -Werror -Wextra -pedantic test_complet.c linked_lists.c 0-is_palindrome.c -o test_complet
./test_complet
# Check Betty style (optional)
betty 0-is_palindrome.c
```
### Function Prototype
```c
int is_palindrome(listint_t **head);
```
**Parameters:**
- `head`: Double pointer to the first node of the list
**Return Value:**
- `1` if the list is a palindrome
- `0` if the list is not a palindrome
## 📝 Examples
### Example 1: Palindrome List
```c
// Input:  1 → 17 → 972 → 50 → 98 → 98 → 50 → 972 → 17 → 1
// Output: "Linked list is a palindrome"
```
### Example 2: Non-Palindrome List
```c
// Input:  1 → 2 → 3 → 4 → 5
// Output: "Linked list is not a palindrome"
```
### Example 3: Edge Cases
```c
// Empty list     → palindrome (1)
// Single node    → palindrome (1)
// Two identical  → palindrome (1)
// Two different  → not palindrome (0)
```
## ⚡ Complexity Analysis
| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single traversal to find middle + single traversal to compare |
| **Space** | O(1) | Only uses a constant number of pointers |
| **Scalability** | Excellent | Linear scaling with input size |
### Why This Approach is Optimal
✅ **Better than naive approaches:**
- No recursion (avoids O(n) call stack)
- No additional data structures (no arrays/stacks)
- Single pass algorithm (more efficient than multiple traversals)
## 🧪 Test Results
All test cases pass successfully:
```
✅ Empty list
✅ Single element
✅ Two identical elements  
✅ Two different elements
✅ Palindrome (odd length)
✅ Palindrome (even length) 
✅ Non-palindrome
✅ Long palindrome
✅ Original list restoration
```
## 🎓 Learning Objectives
This project demonstrates:
- **Linked list manipulation** techniques
- **Two-pointer algorithms** (tortoise and hare)
- **In-place data structure** modification
- **Memory-efficient** programming
- **Algorithm optimization** strategies
## 📄 License
This project is part of the Holberton School curriculum.
---
*Happy coding! 🚀*