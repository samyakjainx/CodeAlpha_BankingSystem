# Mini Banking System in C

A simple Mini Banking System developed in C as part of my CodeAlpha C Programming Internship.

This project demonstrates the use of structures, functions, and file handling to perform basic banking operations through a menu-driven interface.

---

## Features

- Create New Account
- Deposit Money
- Withdraw Money
- Balance Enquiry
- Display All Accounts
- Duplicate Account Validation
- Insufficient Balance Check

---

## Technologies Used

- C Programming
- Structures
- Functions
- File Handling
- GCC Compiler / CodeBlocks / VS Code

---

## Project Structure

```

CodeAlpha_BankingSystem/

│── banking_system.c
│── README.md
│── LICENSE
└── screenshots/
    │── menu.png
    │── create.png
    │── deposit.png
    │── withdraw.png
    │── balance.png
    └── display.png

```

---

## How to Run

### Compile

```

gcc banking_system.c -o banking_system

```

### Execute

```

./banking_system

```

or on Windows

```

banking_system.exe

```

---

## Menu

```

====================================
       MINI BANKING SYSTEM
====================================

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Balance Enquiry
5. Display All Accounts
6. Exit

```

---

## Sample Output

### Create Account

```

Account Number : 1001
Name : Samyak Jain
Opening Balance : 5000.00

Account Created Successfully!

```

---

### Deposit Money

```

Account Number : 1001
Deposit Amount : 1500

Money Deposited Successfully!

```

---

### Withdraw Money

```

Account Number : 1001
Withdraw Amount : 1000

Transaction Successful!

```

---

### Balance Enquiry

```

Account Number : 1001

Name : Samyak Jain
Balance : 5500.00

```

---

### Display All Accounts

```

------------------------------------

Account : 1001
Name    : Samyak Jain
Balance : 5500.00

Account : 1002
Name    : Rahul Sharma
Balance : 3000.00

```

---

## Concepts Practiced

- Structures
- Functions
- File Handling
- Menu Driven Programming
- Record Searching
- Record Updating
- Binary File Operations

---

## File Handling

Account information is stored permanently using file handling, allowing records to remain available even after the program is closed.

The project uses the following file functions:

- fopen()
- fread()
- fwrite()
- fclose()
- remove()
- rename()

---

## Validation

The program includes basic validations to improve reliability:

- Duplicate Account Number Check
- Account Not Found Check
- Insufficient Balance Check

---

## Learning Outcome

This project helped me understand how file handling and structures can be combined to build a simple banking application. It also strengthened my understanding of modular programming and record management in C.

---

## Future Improvements

- Transfer Money Between Accounts
- Transaction History
- Interest Calculation
- PIN Authentication
- Account Statement Generation

---

## Author

Samyak Jain

CodeAlpha C Programming Internship 2026
