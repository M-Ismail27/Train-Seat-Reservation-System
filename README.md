# 🚆 Train Seat Reservation System in C++

## 📌 Introduction

This is a beginner-level C++ project that simulates a **Train Seat Reservation System**. The project provides a simple console-based interface to allow users to navigate between train coaches, view seat availability, and book seats.

It’s designed to help new C++ learners understand and practice important programming concepts like **2D/3D arrays, conditionals, loops, functions, and pointer passing**.

---

## 🔑 Key Features

- 📦 **Three Train Coaches**: Each coach contains 8 rows and 4 seats per row (total 32 seats).
- 🪑 **Seat Status Display**: Shows real-time seat status — `V` for Vacant, `B` for Booked, and `NA` for Not Available.
- 🔄 **Coach Navigation**: Move between coaches to find available seats.
- ✅ **Seat Booking**: Book seats by entering seat numbers. Already booked or unavailable seats are prevented.
- 🔁 **Looped Interface**: Users can continue booking seats until all are filled or they choose to exit.

---

## 💻 Technologies Used

- **Language**: C++
- **Compiler**: Any standard C++ compiler (e.g., g++, Visual Studio, Code::Blocks)
- **Platform**: Console/Terminal (cross-platform)

---

## 📂 Project Structure

- `main()` initializes the seat status, handles the main loop, and controls booking flow.
- `printSeats()` displays the seating layout of the selected coach.
- `coachesMenu()` allows navigation between coaches and lets users proceed to book.
- `seatBook()` handles logic to convert seat number to matrix index and mark the seat as booked.

---

## ⚙️ Concepts Practiced

- Multidimensional arrays (`string seat_status[3][8][4]`)
- Pointer usage for shared variables
- Input validation and menu-driven program design
- Separation of logic into reusable functions

---

## 📌 Future Improvements (Optional Ideas)

- Save booking data to a file for persistence.
- Add user login or passenger info.
- Prevent invalid seat numbers (e.g., >32).
- Add ticket cancellation or reset system.

---

## 🧑‍💻 How to Run

1. Copy the code to any C++ compiler.
2. Compile and run the program.
3. Follow the on-screen instructions to view coaches and book seats.

---

## 📜 License

This project is for educational purposes and is open to modification or extension by others.

---

## 👋 Author

**Muhammad Ismail**  
Beginner in C++ programming and problem-solving.
