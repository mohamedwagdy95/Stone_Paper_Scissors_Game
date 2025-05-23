
# 🪨📄✂️ Stone-Paper-Scissors Game (C++ Console Application)

A fun and interactive command-line implementation of the classic **Stone-Paper-Scissors** game written in **C++**. The player competes against the computer for a number of rounds, and the final winner is displayed based on the results.

---

## 🎮 Features

- Player vs. Computer
- Randomized computer moves
- Best-of-X rounds (user chooses how many)
- Console color changes to reflect the winner
- Option to play again after the game ends
- Clean and modular code using functions, enums, and structs

---

## 🚀 How to Run

### 1. Compile the Code

You can use any C++ compiler. For example, with `g++`:

```bash
g++ -o sps_game main.cpp
```

### 2. Run the Executable

```bash
./sps_game     # On Linux or Mac
sps_game.exe   # On Windows
```

---

## 🧾 Game Rules

- **Stone beats Scissors**
- **Scissors beats Paper**
- **Paper beats Stone**
- If both players choose the same item, the round is a **draw**.

---

## 📦 Code Structure

- `main()` – Entry point, initializes random seed, starts the game loop.
- `StartGame()` – Controls the game loop and replay option.
- `PlayGame()` – Handles all rounds and returns final game results.
- `stRoundInfo` – Stores information for each round.
- `stGameResults` – Stores cumulative results.
- Utility functions for:
  - Getting player/computer choices
  - Determining round/game winner
  - Displaying results

---

## 📸 Sample Output

```
Please enter how many rounds (1 to 10)?
3

Round [1] begins:
Please Select Stone [1] or Paper [2] or Scissors [3]?
1
Player 1 Choice: Stone
Computer Choice: Scissors
Round Winner: [Player 1]

...

+++ Game Over +++

Game Rounds                : 3
Player 1 Win times         : 2
Computer Win Times         : 1
Draw Times                 : 0
Final Winner               : Player 1

Do you want to play again? Y/N
```

---

## 🛠️ Future Improvements (Ideas)

- Add 2-player mode
- Add GUI with graphics
- Save results to a file
- Add difficulty level for the computer

---

## 📄 License

This project is open source and available under the [MIT License](https://opensource.org/licenses/MIT).
