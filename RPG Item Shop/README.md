# RPG Item Shop (C++)

A small console-based RPG item shop built to practice object-oriented
programming and basic data persistence in C++.

This project focuses on **class design and extensibility**, rather than
graphics or complex gameplay systems.

## Overview

The item shop allows a player to browse available items, purchase them
using gold, and store purchased items in a persistent inventory file.
Items are represented using an inheritance hierarchy so different item
types can share common behavior while exposing unique properties.

The program is driven through a simple text-based menu.

## Key Concepts Demonstrated

- Inheritance and polymorphism (`Item`, `Weapon`, `Consumable`, `Equipment`)
- Base-class interfaces with specialized derived behavior
- Menu-driven console interaction
- File I/O for saving and loading inventory data
- Basic resource management (gold and purchases)

## Design Notes

- All items derive from a shared `Item` base class to avoid duplicated logic.
- Item-specific behavior and data are handled in derived classes rather
  than conditionals.
- Inventory persistence uses a plain text file to keep the system easy
  to inspect and debug.
- The item list is hard-coded to keep the focus on system structure
  instead of data pipelines.

This project was intentionally scoped to emphasize clarity and learning
over completeness.

## Building & Running

Requires a C++20-compatible compiler.

```bash
g++ -std=c++20 src/main.cpp -o RPGItemShop
./RPGItemShop
