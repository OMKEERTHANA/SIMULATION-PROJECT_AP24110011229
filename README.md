# Library Management System

A C-based library management system that provides efficient handling of book inventory and circulation operations. The system enables libraries to manage book records, track issued books, and maintain a record of late returns with automated fine calculations.

## Overview

This project implements a complete library management solution with core functionality for inventory tracking and book circulation. The system maintains a centralized database of library books and provides intuitive operations for librarians to manage daily operations effectively.

## Features

- **Book Management**: Add, display, search, and delete book records
- **Inventory Tracking**: Maintain real-time status of book availability
- **Book Circulation**: Issue and return books with date-based tracking
- **Late Fee Calculation**: Automated fine computation for overdue books
- **Search Functionality**: Query books by unique ID
- **User-Friendly Interface**: Menu-driven command-line interface

## System Architecture

### Data Structure

The system uses a `Book` structure to store book information:

```c
struct Book {
    int id;                    // Unique book identifier
    char title[50];            // Book title
    char author[50];           // Author name
    int issued;                // Issue status (0 = available, 1 = issued)
    int issueDay;              // Day book was issued
    int issueMonth;            // Month book was issued
    int issueYear;             // Year book was issued
};
```

### Core Functions

| Function | Purpose |
|----------|---------|
| `addBook()` | Register a new book in the library system |
| `displayBooks()` | List all books with current status |
| `searchBook()` | Find a specific book by ID |
| `issueBook()` | Mark a book as issued with date tracking |
| `returnBook()` | Process book return and calculate late fees |
| `deleteBook()` | Remove a book record from the system |

## Operation Details

### Adding a Book
Users provide book ID, title, and author information. Books are initialized with an "Available" status.

### Issuing a Book
When a book is issued, the system records the issue date (day, month, year) for later fine calculation. Only available books can be issued.

### Returning a Book
Upon return, users input the return date. The system calculates days overdue beyond a 14-day loan period and applies a fine of 5 units per day late.

### Fine Structure
- Loan period: 14 days
- Late fee: 5 units per day
- Automatic calculation upon book return

## Technical Specifications

- **Language**: C
- **Platform**: Cross-platform (Windows, Linux, macOS)
- **Memory**: In-memory database (up to 100 books)
- **Interface**: Command-line menu system
- **External Dependencies**: Standard C libraries (stdio, stdlib, string, time)

## Compilation and Execution

### Compile
```bash
gcc main.c -o library_management
```

### Run
```bash
./library_management
```

### Menu Options
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Delete Book
7. Exit

## Limitations and Scope

- Fixed capacity of 100 books
- In-memory storage (data lost on program termination)
- Date calculation uses simplified 30-day month approximation
- Single-user command-line interface
- No persistent storage implementation


## Future Enhancements

- Persistent database integration (SQL)
- User authentication and roles
- Advanced reporting capabilities
- Automated email notifications for overdue books
- Graphical user interface
- Support for multiple copies of same title
