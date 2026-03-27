# CPP Module 00

Introduction to C++ and object-oriented programming fundamentals through three
exercises covering namespaces, classes, member functions, and static members.

## Technologies

- C++98
- Makefile
- Standard library (iostream, string, iomanip, ctime)

## Build Instructions

Each exercise has its own directory and Makefile.

```bash
cd ex00 && make    # Megaphone
cd ex01 && make    # Phonebook
cd ex02 && make    # Account
```

Available Makefile targets: `make`, `make clean`, `make fclean`, `make re`.

## Exercises

### ex00 - Megaphone

Converts command-line arguments to uppercase and prints them.

```bash
./megaphone "shhh... I think the students are asleep..."
# Output: SHHH... I THINK THE STUDENTS ARE ASLEEP...
./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01 - My Awesome PhoneBook

Interactive phonebook program that stores up to 8 contacts in memory.
Accepts three commands: `ADD`, `SEARCH`, and `EXIT`. Contacts are displayed
in a formatted table with fields truncated to 10 characters.

```bash
./phonebook
# Enter command: ADD
# Enter command: SEARCH
# Enter command: EXIT
```

### ex02 - The Job Of Your Dreams

Recreation of the `Account` class implementation based on a provided header
file and expected log output. Demonstrates static member variables, timestamp
logging, and deposit/withdrawal operations on bank accounts.

```bash
./tester
```

## Key Concepts

- Class design with private attributes and public accessors
- Static member variables and functions
- Formatted output with `std::setw` and `std::right`
- Input handling with `std::getline` and `std::stringstream`
- Circular buffer pattern for fixed-size storage (phonebook)
