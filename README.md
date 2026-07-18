# Student Database Management System

## Overview

The **Student Database Management System** is a console-based application developed in the **C programming language** to manage student records efficiently. It allows users to perform CRUD (Create, Read, Update, Delete) operations on student data. The application uses file handling to store records permanently, ensuring data is retained even after the program is closed.

## Features

- Add new student records
- View all student records
- Search student by Roll Number
- Update existing student details
- Delete student records
- Store records permanently using file handling
- Simple menu-driven interface
- Easy to use and lightweight

## Technologies Used

- Programming Language: C
- Compiler: GCC
- Operating System: Linux / Ubuntu
- Concepts Used:
  - Structures
  - File Handling
  - Functions
  - Arrays
  - String Handling
  - Modular Programming

## Project Structure

```
Student-Database-Management-System/
│
├── student.c          # Main source code
├── student.dat        # Database file (created automatically)
├── README.md          # Project documentation
```

## Compilation

Compile the program using GCC:

```bash
gcc student.c -o student
```

## Running the Program

```bash
./student
```

## Menu

```
==============================
 Student Database Management
==============================

1. Add Student
2. View All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

## Student Record

Each student record contains:

- Roll Number
- Name
- Age
- Gender
- Department
- Semester
- Marks/CGPA
- Contact Number

*(Modify these fields according to your project implementation.)*

## File Storage

All records are stored in:

```
student.dat
```

The file is automatically created if it does not exist.

## Concepts Demonstrated

- Structures
- File Handling (`fopen`, `fread`, `fwrite`, `fseek`, `rewind`, `remove`, `rename`)
- Functions
- CRUD Operations
- Data Persistence
- Searching and Updating Records

## Future Enhancements

- User Login Authentication
- Password Protection
- Attendance Management
- Result Management
- Database Integration (MySQL/SQLite)
- GUI Version
- Report Generation
- Export Data to CSV/Excel

## Sample Output

```
========== Student Database ==========
1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter your choice: 1

Enter Roll Number : 101
Enter Name        : Meet Agravat
Enter Department  : Electronics
Enter Semester    : 8
Enter CGPA        : 8.10

Record Added Successfully.
```

## Requirements

- GCC Compiler
- Linux/Ubuntu (Recommended)
- Terminal

## Learning Outcomes

This project helps in understanding:

- File Management in C
- Structured Programming
- CRUD Operations
- Data Storage and Retrieval
- Modular Programming
- Console-Based Application Development


## License

This project is created for educational and learning purposes. You are free to use, modify, and distribute it for academic and non-commercial use.
