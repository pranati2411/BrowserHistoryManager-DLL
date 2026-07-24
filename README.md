# Browser History Manager (LRU Cache)

A lightweight, command-line browser history manager written in C++. This project simulates a Least Recently Used (LRU) cache using a custom-built Doubly Linked List (DLL), demonstrating low-level memory management and optimized pointer manipulation.

## Technical Features

* **Custom Memory Management:** Implements a strict destructor protocol to ensure zero memory leaks during continuous node allocation, relocation, and deletion.
* **Move-to-Front Heuristic:** Utilizes isolated pointer surgery to instantly move re-visited nodes to the head of the list in `O(1)` time, without shifting other elements.
* **Constant-Time Eviction:** Manages application memory by isolating and deleting the least recently accessed history states (the tail) in `O(1)` time.
* **Defensive Programming:** Includes robust input validation to prevent infinite loops or crashes from invalid user inputs.
* **Duplicate Handling:** Enforces cache uniqueness by checking for existing entries before allocating new nodes, routing duplicates directly to the relocation function.

## Data Structure & Complexities

This system avoids standard library containers to explicitly demonstrate raw pointer mechanics.

* **Insertion at Head:** `O(1)`
* **Deletion at Tail:** `O(1)`
* **Relocation (Move to Head):** `O(1)` for pointer reassignment. 

## Compilation & Execution

Compiled via GCC with standard C++ libraries. No external dependencies required.

### Build
g++ main.cpp -o browser

### Run
./browser

## Usage Interface

Upon execution, the CLI presents the following interactive loop:
1. **Visit New Page:** Pushes a new URL to the top of the history stack.
2. **Re-Visit Page:** Searches for an existing URL and relocates it to the top.
3. **Clear Oldest History:** Evicts the least recently used URL (tail) to free memory.
4. **View History:** Traverses and prints the current state from newest to oldest.
5. **Exit:** Safely terminates the loop and triggers the DLL destructor to free the heap.