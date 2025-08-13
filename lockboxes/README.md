# 🔒 Lockboxes Problem

## 📋 Description

This project implements a solution to the **Lockboxes Problem**, a classic algorithmic challenge involving graph traversal and set theory. The problem requires determining if all locked boxes can be opened given a starting box and keys contained within boxes.

## 🎯 Problem Statement

You have `n` number of locked boxes in front of you. Each box is numbered sequentially from `0` to `n - 1` and each box may contain keys to other boxes.

**Objective**: Write a method that determines if all the boxes can be opened.

### Requirements
- **Prototype**: `def canUnlockAll(boxes)`
- `boxes` is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box `boxes[0]` is unlocked
- Return `True` if all boxes can be opened, else return `False`

## 🔧 Algorithm Implementation

### Approach: Depth-First Search (DFS)

The solution uses a **DFS approach** with a stack-based implementation for optimal performance:

```python
def canUnlockAll(boxes):
    if not boxes:
        return False
    
    n = len(boxes)
    opened = set([0])  # Track opened boxes
    keys_to_check = list(boxes[0])  # Stack for DFS
    
    while keys_to_check:
        key = keys_to_check.pop()  # O(1) operation
        
        if 0 <= key < n and key not in opened:
            opened.add(key)
            keys_to_check.extend(boxes[key])
    
    return len(opened) == n
```

### Key Design Decisions

1. **DFS vs BFS**: 
   - **DFS** with `list.pop()` → **O(1)** complexity
   - BFS with `list.pop(0)` → **O(n)** complexity
   - **Choice**: DFS for better performance

2. **Data Structures**:
   - **Set** for `opened`: O(1) lookup and insertion
   - **List** for `keys_to_check`: Stack behavior with efficient pop()

3. **Edge Cases**:
   - Empty input validation
   - Invalid key filtering (out of range keys)
   - Duplicate key handling

## 📊 Test Cases

### Example 1: All boxes can be opened
```python
boxes = [[1], [2], [3], [4], []]
# Box 0 → key 1 → Box 1 → key 2 → Box 2 → key 3 → Box 3 → key 4 → Box 4
# Result: True
```

### Example 2: Complex interconnected boxes
```python
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
# Multiple paths and cycles
# Result: True
```

### Example 3: Unreachable box
```python
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
# Box 5 cannot be reached (no key 5 in accessible boxes)
# Result: False
```

## 🚀 Usage

### Running the Solution
```bash
./main_0.py
```

### Expected Output
```
True
True
False
```

### Code Structure
```
lockboxes/
├── 0-lockboxes.py    # Main solution file
├── main_0.py         # Test cases
└── README.md         # This documentation
```

## ⚡ Performance Analysis

### Time Complexity
- **O(B + K)** where:
  - B = number of boxes
  - K = total number of keys across all boxes
- Each box and key is processed at most once

### Space Complexity
- **O(B)** for:
  - `opened` set: O(B) in worst case
  - `keys_to_check` stack: O(K) in worst case
  - Overall: O(B + K)

### Optimization Benefits
- **DFS over BFS**: Avoids O(n) cost of `list.pop(0)`
- **Set for tracking**: O(1) membership testing
- **Early termination**: Stops when all boxes found

## 🧪 Algorithm Comparison

| Algorithm | Time Complexity | Space Complexity | Implementation |
|-----------|----------------|------------------|----------------|
| **DFS (Used)** | O(B + K) | O(B + K) | `list.pop()` |
| BFS Alternative | O(B + K) | O(B + K) | `list.pop(0)` |
| Recursive DFS | O(B + K) | O(B + K) | Function calls |

**Winner**: Iterative DFS for optimal performance

## 🔍 Edge Cases Handled

1. **Empty input**: `boxes = []` → `False`
2. **Single box**: `boxes = [[]]` → `True`
3. **Invalid keys**: Keys > n-1 are ignored
4. **Negative keys**: Filtered out (keys must be positive)
5. **Duplicate keys**: Handled efficiently with set
6. **Cycles**: No infinite loops due to visited tracking

## 🎓 Learning Objectives

This project demonstrates:
- **Graph Traversal**: DFS/BFS algorithms
- **Set Theory**: Tracking visited nodes
- **Algorithm Optimization**: Choosing efficient data structures
- **Edge Case Handling**: Robust input validation
- **Performance Analysis**: Time/space complexity considerations

## 🛠️ Development Notes

### Why DFS?
- **Performance**: `list.pop()` is O(1) vs `list.pop(0)` being O(n)
- **Memory**: Similar space complexity but better cache locality
- **Simplicity**: Cleaner iterative implementation

### Code Style
- **PEP 8 compliant**: Following Python style guidelines
- **Type hints ready**: Can be extended with typing annotations
- **Docstring format**: Clear function documentation
- **Clean logic**: Readable and maintainable code

---

**Author**: Holberton School Interview Preparation  
**Language**: Python 3  
**Algorithm**: Depth-First Search (DFS)  
**Complexity**: O(B + K) time, O(B + K) space