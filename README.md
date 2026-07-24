# Browser History Manager (LRU Cache)

A lightweight, command-line browser history manager written in C++. This project simulates a Least Recently Used (LRU) cache using a custom-built Doubly Linked List (DLL), demonstrating low-level memory management and optimized pointer manipulation.

## Technical Features

* **Custom Memory Management:** Implements a strict destructor protocol to ensure zero memory leaks during continuous node allocation, relocation, and deletion.
* **Move-to-Front Heuristic:** Utilizes isolated pointer surgery to instantly move re-visited nodes to the head of the list in `O(1)` time, without shifting other elements.
* **Constant-Time Eviction:** Manages application memory by isolating and deleting the least recently accessed history states (the tail) in `O(1)` time.
* **Defensive Programming:** Includes robust input validation to prevent infinite loops or crashes from invalid user inputs.
* **Duplicate Handling:** Enforces cache uniqueness by checking for existing entries before allocating new nodes, routing duplicates directly to the relocation function.

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