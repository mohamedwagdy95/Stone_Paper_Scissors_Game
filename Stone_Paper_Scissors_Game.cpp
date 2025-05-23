#include <iostream>     // Include iostream for input/output operations.
#include <string>
#include <cstdlib>      // Include cstdlib for system functions like clearing the screen.
#include <ctime>        // Include ctime for random number seeding.

using namespace std;    // Use the standard namespace to avoid prefixing std:: before standard functions.

// Enum for the choices in the game
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

// Enum for identifying the winner of a round or the game
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// Structure to hold details about each round
struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
    string RoundWinnerName;
};

// Structure to hold results of the full game
struct stGameResults {
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string GameWinnerName = "";
};

// Returns a string representation of the game choice
string ChoiceName(enGameChoice Choice) {
    string arrChoiceName[3] = { "Stone", "Paper", "Scissors" };
    return arrChoiceName[Choice - 1];
}

// Returns a string representation of the winner
string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player 1", "Computer", "No Winner" };
    return arrWinnerName[Winner - 1];
}

// Utility function to generate tab spacing
string Tabs(short NumberOfTabs) {
    string t = "";
    for (int i = 0; i < NumberOfTabs; i++) {
        t += "\t";
    }
    return t;
}

// Determines the overall winner of the game
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

// Changes screen color based on winner
void SetWinnerScreenColor(enWinner Winner) {
    switch (Winner) {
    case enWinner::Player1:
        system("color 2F"); // Green background for Player 1 win
        break;
    case enWinner::Computer:
        system("color 4F"); // Red background for Computer win
        cout << "\a";       // Beep sound
        break;
    default:
        system("color 6F"); // Yellow background for Draw
        break;
    }
}

// Displays the final results of the game
void ShowFinalGameResults(stGameResults GameResults) {
    cout << Tabs(2) << "_________________________________[Game Results]_________________________________\n\n";
    cout << Tabs(2) << "Game Rounds                : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player 1 Win times         : " << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer Win Times         : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times                 : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner               : " << GameResults.GameWinnerName << endl;
    cout << Tabs(2) << "_________________________________________________________________________________\n";

    SetWinnerScreenColor(GameResults.GameWinner);
}

// Shows a game over screen banner
void ShowGameOverScreen() {
    cout << Tabs(2) << "_____________________________________________________________________\n\n";
    cout << Tabs(2) << "                            +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "_____________________________________________________________________\n\n";
}

// Constructs and returns the game result summary
stGameResults FillGameResults(short HowManyRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes) {
    stGameResults GameResults;

    GameResults.GameRounds = HowManyRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.GameWinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

// Prints the result of a single round
void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n____________________Round [" << RoundInfo.RoundNumber << "]____________________\n\n";
    cout << "Player 1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner: [" << RoundInfo.RoundWinnerName << "]\n";
    cout << "___________________________________________________\n";

    SetWinnerScreenColor(RoundInfo.RoundWinner);
}

// Determines who won a round based on rules
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice) {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    }

    return enWinner::Draw; // fallback
}

// Generates a random number between From and To
short RandomNumber(short From, short To) {
    return rand() % (To - From + 1) + From;
}

// Returns a random choice for the computer
enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1, 3);
}

// Reads and validates the player's choice
enGameChoice ReadPlayer1Choice() {
    short Player1Choice = 1;
    do {
        cout << "Please Select Stone [1] or Paper [2] or Scissors [3]?\n";
        cin >> Player1Choice;
    } while (Player1Choice < 1 || Player1Choice > 3);

    return (enGameChoice)Player1Choice;
}

// Core function that handles a full game of N rounds
stGameResults PlayGame(short HowManyRounds) {
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
        RoundInfo.RoundWinnerName = WinnerName(RoundInfo.RoundWinner);

        // Count wins
        if (RoundInfo.RoundWinner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.RoundWinner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }

    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

// Asks the user for how many rounds to play
short ReadHowManyRounds() {
    short GameRounds = 1;
    do {
        cout << "Please enter how many rounds (1 to 10)?\n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);

    return GameRounds;
}

// Resets the console screen and color
void ResetScreen() {
    system("cls");
    system("color 0F");
}

// Main loop that handles starting and repeating the game
void StartGame() {
    char PlayAgain = 'Y';

    do {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << endl << Tabs(3) << "Do you want to play again? Y/N ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// Main Function
int main() {
    srand((unsigned)time(NULL)); // Seed random number generator.
    StartGame();  // Start the game.
    return 0;     // Return 0 to indicate successful execution.
}