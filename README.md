<<<<<<< HEAD
# 🌐 C++ LRU Cache History Manager

A command-line application that simulates an optimized navigation history using a custom-built **Doubly Linked List (DLL)**. This project implements the core mechanics of a Least Recently Used (LRU) Cache, allowing for highly efficient, constant-time state management.

## 🚀 Technical Features
* **Custom Memory Management:** Implements a strict destructor protocol to ensure zero memory leaks during continuous node allocation and deletion.
* **O(1) State Transitions:** Utilizes isolated pointer manipulation to instantly move re-visited nodes to the head of the list (Move-to-Front heuristic).
* **Constant-Time Eviction:** Manages application memory by deleting the least recently accessed history states (Tail) in O(1) time.

## 🛠️ Data Structure & Complexities
* **Insertion at Head:** O(1)
* **Deletion at Tail:** O(1)
* **Move to Head:** O(n) search + O(1) pointer reassignment.

## 💻 Compilation & Execution
Compiled via GCC with standard C++ libraries. No external dependencies required.
```bash
g++ main.cpp -o browser
./browser