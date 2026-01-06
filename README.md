# 💼 Life-Work Simulator

A simple C++ console-based **personal life simulation game** where the player manages their character by working, resting, eating, and tracking personal stats like money, stamina, hunger, XP, and rank.

## 💡 Features
- Work to earn **money** and **XP**  
- Eat different foods to restore **hunger** and **stamina**  
- Rest to regain **stamina**  
- Track **player statistics**: nickname, rank, total work, money, stamina, hunger, XP  
- **Rank bonus system**: higher ranks give extra money and XP when working  
- Bonus rewards for **total number of times worked**  
- Simple **menu-driven gameplay**  
- Beginner-friendly and well-structured C++ code  

## ⚙️ How to Run
1. Clone or download this project:  
   `git clone https://github.com/yourusername/WorkSimulator.git`
2. Open a terminal in the project directory.  
3. Compile the program:  
   `g++ main.cpp -o WorkSimulator`
4. Run it:  
   `./WorkSimulator`

## 🧩 Code Overview
- **Work System** → Earns money and XP; affected by rank bonuses  
- **Rest System** → Recovers stamina but reduces hunger slightly  
- **Eating System** → Different foods restore hunger and some affect stamina; costs money  
- **Rank Logic** → Updates rank based on XP and gives work bonuses  
- **Total Work Bonus System** → Extra money for milestones like 5, 10, 15, 20 works  
- **Statistics Menu** → Displays nickname, rank, total work, money, stamina, hunger, and XP  
- **Main Menu** → Allows the player to choose actions (Work, Relax, Eat, Exit)  
- **Game Loop** → Runs continuously until the user exits  

## 🧑‍💻 Author
**wdemirkoll**  
[@wdemirkoll](https://github.com/wdemirkoll)  
Created: January 2026  

## 🧾 C++ Version
This project was created using **C++ 17**

## ⭐ If you like this project, consider giving it a star!
