# Making Change

Solve the coin change problem: determine the fewest number of coins needed to make a given amount.

Examples

Python

```python
#!/usr/bin/python3
makeChange = __import__('0-making_change').makeChange

# Example 1: 37 cents with coins 1, 2 and 25
print(makeChange([1, 2, 25], 37))  # Output: 7
# Explanation: 25 + 2 + 2 + 2 + 2 + 2 + 2 = 37 (7 coins)

# Example 2: 1453 with coins 1256, 54, 48, 16, 102
print(makeChange([1256, 54, 48, 16, 102], 1453))  # Output: -1
# Explanation: impossible to reach 1453 with these coins
```

Installation & execution

```bash
# Clone the repository
git clone https://github.com/[username]/holbertonschool-interview.git

# Go to the exercise folder
cd holbertonschool-interview/making_change

# (If present) make the example runner executable
chmod +x 0-main.py

# Run the example runner
./0-main.py
# or
python3 0-main.py
```

Files

- `0-making_change.py`  — contains the `makeChange()` function implementation
- `0-main.py`          — example/test runner (optional)
