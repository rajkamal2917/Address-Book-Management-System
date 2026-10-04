# 📒 Address Book Management System

A console-based **Address Book Management System developed in C** for storing and managing contact information. The application provides features to add, search, edit, delete, display, and sort contacts, with input validation and CSV-based file storage.

## 🚀 Features

- Add new contacts
- Display all contacts
- Search contacts by name, phone number, or email (partial matching supported)
- Edit contact details
- Delete contacts with a confirmation step
- Sort contacts by name, phone number, or email (Bubble Sort)
- Phone number and email validation
- Duplicate phone number and email detection
- Persistent storage in a CSV file
- Contacts are loaded at startup and saved on exit

## 🛠️ Technologies and Concepts

- C programming
- Structures and arrays
- Functions and pointers
- String handling
- File handling (CSV read/write)
- Searching and sorting
- Input validation
- Modular programming with multiple `.c` and `.h` files

## 📂 Project Structure

```text
Address-Book-Management-System/
│
├── main.c          # Entry point and menu
├── contact.c       # Contact operations (add, search, edit, delete, sort, validation)
├── contact.h
├── file.c          # Load and save contacts to CSV
├── file.h
├── populate.c      # Sample data loading
├── populate.h
├── contact.csv     # Saved contact data
├── .gitignore
└── README.md
```

## ⚙️ Application Workflow

```text
        Start Program
             │
             ▼
      Load Contacts
       from CSV File
             │
             ▼
        Main Menu
             │
     ┌───────┼────────┐
     ▼       ▼        ▼
    Add    Search    Edit
     │       │        │
     └───────┼────────┘
             │
        Delete / Sort
             │
             ▼
       Save Contacts
        to CSV File
             │
             ▼
            Exit
```

## 🔍 Search, Edit and Delete

- **Search:** by name, phone number, or email, with partial matching.
- **Edit:** modify an existing contact's details.
- **Delete:** remove a contact after a confirmation prompt to prevent accidental deletion.

## 🔤 Sorting

Contacts can be sorted by name, phone number, or email address using **Bubble Sort**.

## 🔐 Input Validation

| Field | Checks |
|---|---|
| Name | Must follow the required format |
| Phone | Valid format, no duplicates |
| Email | Valid format, no duplicates |

## 💾 File Handling

Contacts are stored in `contact.csv`, one contact per line with fields separated by commas.

```text
On start:  CSV File → Load Contacts → Address Book
On exit:   Address Book → Save Contacts → CSV File
```

This keeps contact data available after the program is closed.

## ▶️ How to Run

Requires a C compiler such as GCC.

```bash
gcc *.c -o addressbook
./addressbook          # Linux / macOS
addressbook.exe        # Windows
```

## 🖥️ Sample Menu

```text
========== ADDRESS BOOK ==========

1. Add Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. Display Contacts
6. Sort Contacts
7. Exit

Enter your choice:
```

## ⚠️ Limitations

- Contacts are saved when the program exits, so changes are lost if it terminates unexpectedly.
- Fields containing commas are not supported by the CSV format used.
- Bubble Sort is O(n²), which is fine for small contact lists but slow for very large ones.

## 🔮 Future Enhancements

- Dynamic memory allocation for contacts
- Advanced search and filtering
- Import/export functionality
- Faster sorting (Quick Sort / Merge Sort)
- Database integration
- GUI-based application

## 🧠 Key Learning Outcomes

- Building a modular C application across multiple files
- Implementing CRUD operations
- Persisting data with file handling
- Validating user input
- Debugging and testing a menu-driven program

## 👨‍💻 Author

**RajKamal**
Electronics and Communication Engineering
