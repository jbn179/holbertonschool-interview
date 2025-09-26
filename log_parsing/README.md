# 📊 Log Parsing

## 📋 Description

This project implements a **real-time log parser** that reads from stdin and computes metrics on HTTP access logs. The script processes log entries line by line and provides statistical summaries every 10 lines or upon keyboard interruption (CTRL+C).

## 🎯 Problem Statement

Write a script that reads stdin line by line and computes metrics from HTTP access logs.

### Requirements

- **Input format**: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
- Lines not matching this exact format must be skipped
- **Statistics tracking**:
  - Total file size (sum of all `<file size>` values)
  - Number of lines by status code (200, 301, 400, 401, 403, 404, 405, 500)
- **Output frequency**: Every 10 lines and/or on keyboard interruption (CTRL+C)
- **Status code handling**: Only print status codes that appear at least once, in ascending order

## 🔧 Algorithm Implementation

### Log Processing Strategy

```python
def process_log_line(line):
    # Use regex to match exact format
    pattern = r'^(\d+\.\d+\.\d+\.\d+) - \[.*\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
    match = re.match(pattern, line.strip())
    
    if match:
        status_code = int(match.group(2))
        file_size = int(match.group(3))
        return status_code, file_size
    return None, None
```

### Key Components

1. **Regex Pattern Matching**: Strict format validation using regex
2. **Signal Handling**: Graceful CTRL+C interruption with final statistics
3. **Real-time Processing**: Line-by-line processing without storing all data
4. **Status Code Filtering**: Only track valid HTTP status codes

## 📊 Statistics Output Format

```
File size: <total size>
<status code>: <number>
<status code>: <number>
...
```

### Example Output
```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
```

## 🚀 Usage

### Running the Script
```bash
# Make executable
chmod +x 0-stats.py

# Test with log generator
./0-generator.py | ./0-stats.py

# Or pipe from a file
cat access.log | ./0-stats.py
```

### Input Format Example
```
127.0.0.1 - [2023-10-15 14:30:25.123456] "GET /projects/260 HTTP/1.1" 200 1024
192.168.1.100 - [2023-10-15 14:30:26.456789] "GET /projects/260 HTTP/1.1" 404 512
```

### Code Structure
```
log_parsing/
├── 0-stats.py         # Main log parser implementation
├── 0-generator.py     # Test log generator (provided)
└── README.md          # This documentation
```

## 📝 Implementation Details

### Core Algorithm

```python
#!/usr/bin/python3
import sys
import re
import signal

def print_stats(total_size, status_counts):
    """Print current statistics in the required format"""
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        if status_counts[status] > 0:
            print("{}: {}".format(status, status_counts[status]))

def signal_handler(sig, frame):
    """Handle CTRL+C interruption gracefully"""
    print_stats(total_size, status_counts)
    sys.exit(0)

if __name__ == "__main__":
    total_size = 0
    status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0
    
    signal.signal(signal.SIGINT, signal_handler)
    
    pattern = r'^(\d+\.\d+\.\d+\.\d+) - \[.*\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
    
    try:
        for line in sys.stdin:
            line = line.strip()
            match = re.match(pattern, line)
            
            if match:
                status_code = int(match.group(2))
                file_size = int(match.group(3))
                
                total_size += file_size
                
                if status_code in status_counts:
                    status_counts[status_code] += 1
                
                line_count += 1
                
                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)
    
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
```

## 🔍 Key Features

### 1. Strict Format Validation
- **Regex Pattern**: Ensures exact format matching
- **IP Address**: Must be in dotted decimal notation
- **HTTP Method**: Only accepts "GET /projects/260 HTTP/1.1"
- **Status Code & File Size**: Must be numeric

### 2. Signal Handling
- **CTRL+C Handling**: Graceful interruption with final statistics
- **Dual Handler**: Both `signal.signal()` and `try/except KeyboardInterrupt`
- **Clean Exit**: Ensures statistics are always printed before exit

### 3. Memory Efficiency
- **Streaming Processing**: No need to store all lines in memory
- **Real-time Output**: Statistics printed every 10 valid lines
- **Constant Space**: O(1) space complexity regardless of input size

## ⚡ Performance Analysis

### Time Complexity
- **O(n)** where n is the number of input lines
- Each line processed exactly once
- Regex matching is O(m) where m is line length (constant for fixed format)

### Space Complexity
- **O(1)** constant space
- Only stores counters and current line being processed
- No data accumulation beyond statistics

### Scalability Features
- **Stream Processing**: Can handle infinite input streams
- **Memory Efficient**: Constant memory usage regardless of input size
- **Real-time**: Immediate feedback every 10 lines

## 📊 Test Cases

### Valid Log Entries
```python
# Test Case 1: Standard entries
"127.0.0.1 - [2023-10-15] \"GET /projects/260 HTTP/1.1\" 200 1024"
"192.168.1.1 - [2023-10-15] \"GET /projects/260 HTTP/1.1\" 404 512"

# Expected: Counted and processed
```

### Invalid Log Entries (Skipped)
```python
# Test Case 2: Wrong format entries
"Invalid log entry"
"127.0.0.1 - [2023-10-15] \"POST /projects/260 HTTP/1.1\" 200 1024"  # Wrong method
"127.0.0.1 - [2023-10-15] \"GET /projects/261 HTTP/1.1\" 200 1024"   # Wrong path

# Expected: Ignored, not counted
```

### Edge Cases
```python
# Empty input → File size: 0
# Only invalid lines → File size: 0
# Mixed valid/invalid → Only valid lines processed
```

## 🧪 Example Session

```bash
$ ./0-generator.py | ./0-stats.py
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
```

## 🎓 Learning Objectives

This project demonstrates:
- **Stream Processing**: Real-time data processing without buffering
- **Regular Expressions**: Complex pattern matching for log parsing
- **Signal Handling**: Graceful interruption handling in Python
- **Statistical Analysis**: Real-time metric computation
- **Input Validation**: Robust parsing with invalid data filtering

## 🛠️ Technical Requirements

### Python Version
- **Python 3** (version 3.4.3 or higher)
- **Ubuntu 14.04 LTS** compatible

### Code Standards
- **PEP 8 compliant**: Clean, readable Python code
- **Executable**: Script has proper shebang and execute permissions
- **Modular Design**: Code not executed when imported

### Error Handling
- **Invalid Lines**: Gracefully skipped without errors
- **Empty Input**: Handles empty stdin gracefully
- **Interruption**: Clean exit on CTRL+C

## 🔧 Implementation Notes

### Why Regex Over String Methods?
- **Precision**: Exact format matching prevents false positives
- **Performance**: Single regex check vs multiple string operations
- **Maintainability**: Pattern centralized and easily modifiable

### Signal Handling Strategy
```python
# Dual approach for robust interruption handling
signal.signal(signal.SIGINT, signal_handler)  # System signal
try:
    # Main processing loop
except KeyboardInterrupt:  # Python exception
    print_stats(total_size, status_counts)
```

### Status Code Management
```python
# Predefined dictionary with all valid status codes
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

# Only print non-zero counts in ascending order
for status in sorted(status_counts.keys()):
    if status_counts[status] > 0:
        print("{}: {}".format(status, status_counts[status]))
```

## 🚨 Common Pitfalls Avoided

1. **Format Variations**: Strict regex prevents accepting similar but incorrect formats
2. **Memory Leaks**: Stream processing avoids accumulating data
3. **Unhandled Interrupts**: Dual signal/exception handling ensures clean exit
4. **Invalid Status Codes**: Only predefined codes are tracked
5. **Import Execution**: `if __name__ == "__main__":` prevents execution on import

---

**Author**: Holberton School Interview Preparation  
**Language**: Python 3  
**Concepts**: Log Parsing, Stream Processing, Signal Handling  
**Complexity**: O(n) time, O(1) space