# Student Record Management System (SRMS)

A comprehensive console-based student record management system developed in C programming language with role-based access control and file-based data persistence.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [User Roles and Permissions](#user-roles-and-permissions)
- [Stack Simulation](#stack-simulation)
- [Compilation Instructions](#compilation-instructions)
- [Default Credentials](#default-credentials)
- [File Formats](#file-formats)

---

## Overview

The Student Record Management System (SRMS) is designed to manage student information efficiently with proper authentication and authorization mechanisms. The system implements three user roles (Admin, Staff, Guest) with different permission levels for accessing and modifying student records.

### Key Highlights

- Role-based access control system
- CRUD operations (Create, Read, Update, Delete)
- File-based persistent storage
- Secure authentication system
- Menu-driven user interface
- Stack data structure implementation

---

## Features

### Main System Features

1. **User Authentication**
   - Secure login system
   - Credential validation from file
   - Role-based session management

2. **Student Management**
   - Add new student records
   - View all students in formatted table
   - Search student by roll number
   - Update student information
   - Delete student records

3. **Role-Based Access Control**
   - Admin: Full access to all operations
   - Staff: View and search operations only
   - Guest: View-only access

4. **Data Persistence**
   - File-based storage using text files
   - Automatic credential file creation
   - Safe update mechanism using temporary files

### Stack Simulation Features

1. **Basic Stack Operations**
   - Push: Add element to stack
   - Pop: Remove element from stack
   - Peek: View top element
   - Display: Show all stack contents

2. **Implementation Details**
   - Array-based stack implementation
   - LIFO (Last In First Out) principle
   - Overflow and underflow detection
   - Dynamic size tracking

---

## Usage

### Running the SRMS

```bash
./srms
```

#### Login Process
1. Enter username
2. Enter password
3. System validates credentials
4. Access granted based on role

#### Admin Operations
- Add Student: Enter name, roll number, and marks
- View Students: Display all records in table format
- Search Student: Find by roll number
- Update Student: Modify name and marks
- Delete Student: Remove record by roll number
- Logout: Exit to login screen

#### Staff Operations
- View Students: Display all records
- Search Student: Find by roll number
- Logout: Exit to login screen

#### Guest Operations
- View Students: Display all records only

### Running Stack Simulation

```bash
./stack
```

#### Available Operations
1. Push: Add integer to stack
2. Pop: Remove top element
3. Peek: View top element without removing
4. Display: Show all stack elements
5. Exit: Close program

---

## Project Structure

```
SRMS-Project/
|
|-- cs.c                          # Main SRMS source code
|-- stack_simulation.c            # Stack implementation
|-- credentials.txt               # User login credentials
|-- students.txt                  # Student records database
|-- SRMS_Project_Report.md        # Detailed project report
|-- README.md                     # This file
```

---

## User Roles and Permissions

| Feature | Admin | Staff | Guest |
|---------|-------|-------|-------|
| Add Student | Yes | No | No |
| View Students | Yes | Yes | Yes |
| Search Student | Yes | Yes | No |
| Update Student | Yes | No | No |
| Delete Student | Yes | No | No |

---

## Stack Simulation

### Data Structure

```c
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
```

### Operations Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| Display | O(n) | O(1) |

### Key Concepts Demonstrated

- Stack overflow detection
- Stack underflow detection
- LIFO principle implementation
- Array-based data structure
- Top pointer management

---

## Compilation Instructions

### Using GCC (Linux/macOS/Windows with MinGW)

#### Compile SRMS
```bash
gcc cs.c -o srms.exe
```

#### Compile Stack Simulation
```bash
gcc stack_simulation.c -o stack.exe
```

### Using Visual Studio (Windows)

1. Open Visual Studio
2. Create new C project
3. Add cs.c or stack_simulation.c
4. Build and run

### Using Code::Blocks

1. Create new C project
2. Add source file
3. Build and execute

---

## Default Credentials

The system comes with pre-configured user accounts:

| Username | Password | Role | Access Level |
|----------|----------|------|--------------|
| admin | admin123 | admin | Full access |
| user | user123 | user | View and Search |
| guest | guest123 | guest | View only |

Note: If credentials.txt is missing, the system automatically creates it with default users.

---

## File Formats

### credentials.txt Format

```
username password role
admin admin123 admin
user user123 user
guest guest123 guest
```

### students.txt Format

```
name roll marks
John 101 85.50
Alice 102 92.00
Bob 103 78.25
```

---

## Code Structure

### Main Components

#### 1. Data Structures

**Student Structure:**
```c
struct Student {
    char name[50];
    int roll;
    float marks;
};
```

**Stack Structure:**
```c
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
```

#### 2. Core Functions

**SRMS Functions:**
- `loginSystem()` - User authentication
- `mainMenu()` - Role-based menu dispatcher
- `adminMenu()` - Admin operations menu
- `staffMenu()` - Staff operations menu
- `guestMenu()` - Guest operations menu
- `addStudent()` - Create new record
- `viewStudents()` - Display all records
- `searchStudent()` - Find by roll number
- `updateStudent()` - Modify existing record
- `deleteStudent()` - Remove record

**Stack Functions:**
- `initStack()` - Initialize stack
- `push()` - Add element
- `pop()` - Remove element
- `peek()` - View top element
- `display()` - Show all elements
- `isEmpty()` - Check if empty
- `isFull()` - Check if full

---

## Algorithm Complexity

### SRMS Operations

| Operation | Algorithm | Time Complexity | Space Complexity |
|-----------|-----------|----------------|------------------|
| Add Student | File Append | O(1) | O(1) |
| View Students | File Read | O(n) | O(1) |
| Search Student | Linear Search | O(n) | O(1) |
| Update Student | File Rewrite | O(n) | O(n) |
| Delete Student | File Rewrite | O(n) | O(n) |

Where n = number of student records

---

## Error Handling

The system includes comprehensive error handling:

- File not found errors
- Invalid login attempts
- Stack overflow/underflow
- Invalid menu choices
- Empty file scenarios
- Record not found cases

---

## Sample Usage

### Example 1: Adding a Student (Admin)

```
Enter your choice: 1

----- Add New Student -----
Enter student name: Alice
Enter roll number: 102
Enter marks: 92.5

Student added successfully!
```

### Example 2: Viewing Students

```
Enter your choice: 2

========================================
         STUDENT RECORDS
========================================
Name                 Roll No    Marks     
----------------------------------------
John                 101        85.50     
Alice                102        92.50     
----------------------------------------
Total Students: 2
```

### Example 3: Stack Operations

```
Enter choice: 1
Enter value to push: 10
Pushed 10 to stack

Enter choice: 1
Enter value to push: 20
Pushed 20 to stack

Enter choice: 4

========================================
Stack contents (top to bottom):
========================================
  |   20 |
  |   10 |
  +------+
Total elements: 2
```

---

## Testing

### Test Cases Covered

1. Valid admin login
2. Invalid login attempts
3. Add student operation
4. View all students
5. Search existing student
6. Search non-existing student
7. Update student record
8. Delete student record
9. Staff access restrictions
10. Guest access restrictions
11. Empty file handling
12. Stack overflow condition
13. Stack underflow condition

---

## Future Enhancements

### Planned Features

1. **Enhanced Security**
   - Password encryption
   - Session timeout
   - Login attempt limits

2. **Advanced Search**
   - Search by name
   - Search by marks range
   - Multi-criteria search

3. **Data Export**
   - Export to CSV
   - Export to PDF
   - Report generation

4. **Database Integration**
   - SQLite support
   - Better query performance
   - Transaction management

5. **GUI Implementation**
   - Graphical user interface
   - Better user experience
   - Visual data representation

6. **Additional Data Structures**
   - Linked list implementation
   - Queue simulation
   - Tree traversals

---

## Troubleshooting

### Common Issues

**Issue: Compilation Error**
```
Solution: Ensure GCC is installed and added to PATH
```

**Issue: File Not Found**
```
Solution: Run program in correct directory with required files
```

**Issue: Login Failed**
```
Solution: Check credentials.txt exists and contains valid entries
```

**Issue: Stack Overflow**
```
Solution: Pop some elements before pushing more
```

---

## Performance Notes

- File operations may slow down with large number of records
- Linear search used for finding records
- Temporary file technique ensures data integrity during updates
- Stack operations are constant time O(1)

---

## Development Environment

- **Language:** C (C99 Standard)
- **Compiler:** GCC 14.2.0
- **IDE:** Visual Studio Code
- **OS:** Windows 11
- **Terminal:** PowerShell
- **Version Control:** Git

---

## Code Standards

- Function-based modular programming
- Clear variable naming conventions
- Comprehensive error handling
- Formatted output for readability
- Comments for code documentation

---

## Authors

- Lakshya - Initial work and development
- Campus Corporate Connect - Project guidance

---

## Acknowledgments

- Faculty members for project guidance
- Online resources (GeeksforGeeks, TutorialsPoint)
- C Programming community for support
- GitHub for version control platform

---

## Project Report

For detailed project documentation, algorithm explanations, and comprehensive analysis, refer to:
- `SRMS_Project_Report.md`

---

## Contact

For questions, suggestions, or issues:
- GitHub: https://github.com/lakshya-02
- Repository: https://github.com/lakshya-02/SRMS-Project

---

## Version History

- **v1.0** (December 2025)
  - Initial release
  - Basic CRUD operations
  - Role-based access control
  - Stack simulation implementation
  - File-based storage

---

## Quick Start Guide

### For First Time Users

1. Clone repository
2. Compile cs.c
3. Run ./srms
4. Login with: admin/admin123
5. Try adding a student
6. View the records
7. Explore other features

### For Stack Simulation

1. Compile stack_simulation.c
2. Run ./stack
3. Try push operation
4. Try pop operation
5. Display stack contents
6. Experiment with overflow/underflow

---

**Last Updated:** December 8, 2025

**Repository:** https://github.com/lakshya-02/SRMS-Project
