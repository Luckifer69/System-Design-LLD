# System Design - Low Level Design (LLD)

A curated repository practicing **Low Level Designs (LLD)** and Object-Oriented Design in **C++**, focusing on clean multi-tier architectures, SOLID principles, design patterns, concurrency control, and UML diagrams.

---

## 📚 Problems Index

| # | Problem | Design Patterns & Techniques | Core Concepts | Link |
|---|:---|:---|:---|:---:|
| 1 | **Parking Lot** | Singleton, Strategy, Factory/Polymorphism | Multi-floor spot allocation, ticket lifecycle, dynamic pricing | [Solution](Parking_Lot/) |
| 2 | **Flight Booking System** | Singleton, Two-Phase Locking, Concurrency Control | Thread-safe seat inventory, granular locking, payment rollback, zero double-booking | [Solution](Flight_Booking/) |

---

## 🏛️ Architecture Philosophy

Each problem in this repository is structured into modular tiers to adhere to production-grade software engineering standards:

1. **`enums/`**: Core enums and domain types.
2. **`models/`**: Domain entities and encapsulation (POCO/data structures and entity behavior).
3. **`strategies/`**: Pluggable business logic and algorithms using GoF Strategy pattern.
4. **`services/`**: Central business logic and singleton orchestrators.
5. **`gates/` / `controllers/`**: Entry points, controllers, and external interface handlers.
6. **`concurrency/` / `utils/`**: Concurrency utilities and cross-platform abstractions.
7. **`main.cpp`**: End-to-end simulation driver demonstrating test cases and concurrent scenarios.

---

## 🛠️ General Build Instructions

Each problem includes its own `Makefile` and `CMakeLists.txt`. You can also compile directly using `g++` (C++14 or higher).
