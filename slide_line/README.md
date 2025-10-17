# Slide Line - 2048 Game Mechanics

This project implements the sliding and merging mechanics of the 2048 game on a single horizontal line.

## Description

The `slide_line` function reproduces the core 2048 game logic:
- Slide elements left or right
- Merge identical adjacent numbers
- Handle zeros correctly
- Respect 2048 merging rules (no multiple merges per move)

## Files

- `slide_line.h` - Header file with function prototype and direction macros
- `0-slide_line.c` - Implementation of the slide_line function
- `0-main.c` - Test program with command line interface

## Function Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

**Parameters:**
- `line`: Pointer to array of integers to slide and merge
- `size`: Number of elements in the array
- `direction`: Either `SLIDE_LEFT` or `SLIDE_RIGHT`

**Return:** 1 on success, 0 on failure

## Algorithm

The implementation uses a clear 3-step approach for each direction:

### Left Slide:
1. **Slide**: Move all non-zero elements to the left
2. **Merge**: Combine adjacent identical values
3. **Slide Again**: Remove zeros created by merging
4. **Fill**: Fill remaining positions with zeros

### Right Slide:
1. **Slide**: Move all non-zero elements to the right
2. **Merge**: Combine adjacent identical values (right to left)
3. **Slide Again**: Remove zeros created by merging
4. **Fill**: Fill remaining positions with zeros

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -o slide_line 0-main.c 0-slide_line.c
```

## Usage

```bash
./slide_line <L/R> <numbers...>
```

**Examples:**

```bash
# Slide left with merging
./slide_line L 2 2 0 0
# Output: Line: 4, 0, 0, 0

# Complex left slide
./slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
# Output: Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

# Slide right with merging
./slide_line R 2 2 2 2
# Output: Line: 0, 0, 4, 4

# Right slide with odd number
./slide_line R 2 2 2 2 2
# Output: Line: 0, 0, 2, 4, 4

# Single element (no change)
./slide_line R 98
# Output: Line: 98
```

## Key Features

- ✅ **No dynamic allocation** - Operates in-place on the input array
- ✅ **Respects 2048 rules** - Each value can only merge once per move
- ✅ **Handles edge cases** - Single elements, all zeros, overflow protection
- ✅ **Clear architecture** - Readable 3-step algorithm for maintainability

## Technical Notes

- Uses `size_t` for array indices to handle large arrays safely
- Handles unsigned integer overflow correctly in loop conditions
- Maintains original array structure (modifies in-place)
- Follows Betty coding style for Holberton School

## Author

Implementation by Enzo with optimizations for clarity and correctness.