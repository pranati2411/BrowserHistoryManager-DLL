# 🌐 Browser History Manager

A C++ command-line application that simulates a web browser's history feature using a **Doubly Linked List (DLL)**.

## 🚀 Features
* **Visit New Page:** Adds a URL to the front of the history.
* **Re-Visit Page:** Searches for an existing URL. If found, it moves that URL to the top (most recent) spot.
* **Clear Oldest History:** Deletes the last entry (Tail) to manage memory or limit history size.
* **View History:** Displays the full navigation history from Newest to Oldest.

## 🛠️ Data Structure
This project utilizes a **Doubly Linked List** to ensure efficient operations:
* **Insertion at Head:** O(1)
* **Deletion at Tail:** O(1)
* **Move to Head:** O(n) for search, O(1) for pointer manipulation.

## 💻 How to Run
1. Clone the repository or download the source code.
2. Compile the project using g++:
   ```bash
   g++ main.cpp -o browser