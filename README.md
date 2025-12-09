# 📦 Mini-Inventory  
A simple C++ console-based inventory system that allows users to enter items, view them, calculate total inventory value, and search by item name.

This project is perfect for beginners learning arrays, structs, functions, and basic user interaction in C++.

---

## ✨ Features

- Add multiple items (name, price, quantity)
- Display all items in the inventory
- Automatically calculate the total value of all items
- Search for an item by name
- Clean, modular functions for readability

---

## 🧠 How It Works

The program uses a struct:

```cpp
struct Item
{
    std::string name;
    float price;
    int quantity;
};
