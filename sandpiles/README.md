readme# 🏖️ Sandpiles Algorithm

[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Betty Style](https://img.shields.io/badge/code%20style-Betty-brightgreen.svg)](https://github.com/holbertonschool/Betty)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

## 📋 Description

This project implements the **sandpiles algorithm**, a fascinating mathematical model that simulates the redistribution of sand grains on a grid. When a pile becomes too high (> 3 grains), it "topples" and distributes its grains to neighboring cells.

### 🎯 Objective
Calculate the sum of two 3×3 sandpile grids and stabilize the result according to the physical redistribution rules.

## 🔬 Sandpiles Theory

### Basic Rules:
1. **Stable grid**: All cells contain ≤ 3 grains
2. **Redistribution**: If a cell has > 3 grains:
   - Remove 4 grains from this cell
   - Add 1 grain to each of the 4 adjacent neighbors
   - Neighbors outside the grid are ignored
3. **Convergence**: The algorithm always converges to a unique stable state

### Redistribution Example:
```
Before:         After:
4 6 4    →      2 5 2
6 6 6    →      5 6 5
4 6 4    →      2 5 2
```

## 🚀 Installation and Compilation

### Prerequisites
- GCC Compiler
- Unix/Linux System
- Make (optional)

### Compilation
```bash
# Standard compilation
gcc -Wall -Wextra -Werror -pedantic *.c -o sandpiles

# Or with specific files
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o sandpiles
```

### Betty Style Check (optional)
```bash
betty-style *.c *.h
betty-doc *.c *.h
```

## 📁 Project Structure

```
sandpiles/
├── README.md           # This file
├── sandpiles.h         # Header file
├── 0-sandpiles.c       # Main implementation
├── 0-main.c            # Main test
├── 1-main.c            # Alternative test
└── examples/           # Additional examples
```

## 💻 Usage

### Basic Example
```c
#include "sandpiles.h"

int main(void)
{
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    sandpiles_sum(grid1, grid2);
    return (0);
}
```

### Execution
```bash
./sandpiles
```

### Expected Output
```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

## 🔧 API Reference

### Main Function
```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```
- **Description**: Computes the sum of two sandpiles and stabilizes the result
- **Parameters**:
  - `grid1`: First grid (will contain the result)
  - `grid2`: Second grid (remains unchanged)
- **Output**: Prints each stabilization step

### Utility Functions (static)
```c
static void print_grid(int grid[3][3]);     // Prints a grid
static int is_stable(int grid[3][3]);       // Checks stability
static void topple(int grid[3][3]);         // Performs redistribution
```

## 🧪 Tests

### Test 1: Complex Case
```bash
./0-sandpiles
# Grids with multiple redistributions
```

### Test 2: Simple Case (already stable grid)
```bash
./1-sandpiles
# Immediately stable result grid
```

### Custom Tests
Modify values in `main()` to test different cases:
```c
int grid1[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int grid2[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
```

## 🎨 Detailed Algorithm

### Algorithm Steps:
1. **Addition**: `grid1[i][j] += grid2[i][j]` for all elements
2. **Verification**: Test if the grid is stable
3. **Display**: If unstable, display current state
4. **Redistribution**: Apply toppling rules
5. **Repetition**: Return to step 2 until stability

### Complexity:
- **Time**: O(n × m) per iteration, with guaranteed convergence
- **Space**: O(1) (fixed-size temporary grid)

## 🔬 Mathematical Properties

### Important Theorems:
- ✅ **Guaranteed Convergence**: The algorithm always terminates
- ✅ **Determinism**: Same input → same output
- ✅ **Commutativity**: `sum(A, B) = sum(B, A)`
- ✅ **Associativity**: `sum(sum(A, B), C) = sum(A, sum(B, C))`

### Applications:
- Avalanche modeling
- Self-organized systems
- Distribution networks
- Load balancing

## 🐛 Debugging

### Common Issues:
1. **Infinite loop**: Check `is_stable()` implementation
2. **Wrong result**: Ensure using temporary grid in `topple()`
3. **Compilation error**: Check GCC flags and Betty style

### Debug Mode:
Add `printf()` to trace execution:
```c
printf("DEBUG: Cell [%d][%d] = %d\n", i, j, grid[i][j]);
```


## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

