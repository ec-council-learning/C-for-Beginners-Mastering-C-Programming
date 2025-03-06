#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int player1Score = 0;
int player2Score = 0;

int checkwin();
void board();
void saveHighScore(string player1, string player2, int player);
void displayHighScores();
int getPlayerChoice();
int getRandomMove();

void setColor(int colorCode) {
    cout << "\033[0;" << colorCode << "m";
}

int main()
{
    int gameMode;
    cout << "Tic Tac Toe" << endl;
    cout << "Select game mode:" << endl;
    cout << "1. Player vs. Player" << endl;
    cout << "2. Player vs. Computer" << endl;
    cout << "3. Computer vs. Computer" << endl;
    cout << "Enter your choice: ";
    cin >> gameMode;

    if (gameMode < 1 || gameMode > 3) {
        cout << "Invalid game mode. Exiting..." << endl;
        return 0;
    }
    string player1, player2;

    if (gameMode == 1) {
        cout << "Enter Player 1 Name: ";
        cin >> player1;
        cout << "Enter Player 2 Name: ";
        cin >> player2;
    } else if (gameMode == 2) {
        cout << "Enter Player Name: ";
        cin >> player1;
    }

    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player=(player%2)?1:2;

        if ((gameMode == 1) || (gameMode == 2 && player == 1)) {
            cout << "Player " << player << ", enter a number: ";
            choice = getPlayerChoice();
        } else {
            cout << "Computer " << player << " is playing..." << endl;
            choice = getRandomMove();
        }

        mark=(player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
            square[choice] = mark;
        else
        {
            cout << "Invalid move. Try again." << endl;
            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();

        player++;
    } while(i==-1);
    board();
    if (i == 1) {
        cout << "==>\a";
        if (gameMode == 1) {
            cout << player1 << " wins!";
            if (player == 1) {
                player1Score++;
                setColor(31); // Set color to red for Player 1 (X)
            } else {
                player2Score++;
                setColor(34); // Set color to blue for Player 2 (O)
            }
            cout << "\nPlayer " << player << "'s Score: " << (player == 1 ? player1Score : player2Score) << endl;
        } else {
            cout << "Player " << --player << " wins!";
            player1Score++;
            setColor(31); // Set color to red for Player 1 (X)
            cout << "\nPlayer 1's Score: " << player1Score << endl;
        }
        saveHighScore(player1, player2, player);
        setColor(0); // Reset color to default
    }
   else if (i == 0)
{
cout<<"==>\aGame draw";
setColor(33); // Set color to yellow for draw
cout << "\nPlayer 1's Score: " << player1Score << endl;
cout << "Player 2's Score: " << player2Score << endl;
saveHighScore(player1, player2, 0);
setColor(0); // Reset color to default
}
else
{
cout<<"==>\aGame draw";
setColor(33); // Set color to yellow for draw
cout << "\nPlayer " << --player << "'s Score: " << (player == 1 ? player1Score : player2Score) << endl;
saveHighScore(player1, player2, 0);
setColor(0); // Reset color to default
}
cin.ignore();
cin.get();
return 0;
}

int checkwin()
{
if (square[1] == square[2] && square[2] == square[3])
return 1;
else if (square[4] == square[5] && square[5] == square[6])
return 1;
else if (square[7] == square[8] && square[8] == square[9])
return 1;
else if (square[1] == square[4] && square[4] == square[7])
return 1;
else if (square[2] == square[5] && square[5] == square[8])
return 1;
else if (square[3] == square[6] && square[6] == square[9])
return 1;
else if (square[1] == square[5] && square[5] == square[9])
return 1;
else if (square[3] == square[5] && square[5] == square[7])
return 1;
else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
!= '7' && square[8] != '8' && square[9] != '9')
return 0;
else
return -1;
}

void board()
{
system("clear");
cout << "\n\n\tTic Tac Toe\n\n";
cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
cout << "Score:" << endl;
setColor(31); // Set color to red for Player 1 (X)
cout << "Player 1: " << player1Score << "    ";
setColor(34); // Set color to blue for Player 2 (O)
cout << "Player 2: " << player2Score << endl << endl;
setColor(0); // Reset color to default

cout << "     |     |     " << endl;
cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
cout << "_____|_____|_____" << endl;

cout << "     |     |     " << endl;
cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
cout << "_____|_____|_____" << endl;

cout << "     |     |     " << endl;
cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
cout << "     |     |     " << endl << endl;
}


void saveHighScore(const string& player1, const string& player2, int winner)
{
    ofstream file;
    file.open("high_scores.txt", ios::app); // Open the file in append mode

    if (file.is_open())
    {
        file << "Player 1: " << player1 << "    ";
        file << "Player 2: " << player2 << "    ";

        if (winner == 1)
            file << "Winner: " << player1 << endl;
        else if (winner == 2)
            file << "Winner: " << player2 << endl;
        else
            file << "Game Draw" << endl;

        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void saveHighScore(const string& player1, const string& player2, int player)
{
    ofstream file;
    file.open("high_scores.txt", ios::app); // Open the file in append mode

    if (file.is_open())
    {
        file << "Player 1: " << player1 << "    ";
        file << "Player 2: " << player2 << "    ";

        if (player == 1)
            file << "Winner: " << player1 << endl;
        else if (player == 2)
            file << "Winner: " << player2 << endl;
        else
            file << "Game Draw" << endl;

        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void displayHighScores()
{
    ifstream file;
    file.open("high_scores.txt");

    if (file.is_open())
    {
        string line;

        cout << "\nHigh Scores:" << endl << endl;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "No high scores available." << endl;
    }
}

int main()
{
    int player = 1, i, choice;
    char mark;

    string player1, player2;

    cout << "Enter Player 1 name: ";
    cin >> player1;

    cout << "Enter Player 2 name: ";
    cin >> player2;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }

        i = checkwin();
        player++;

    } while (i == -1);

    board();

    if (i == 1)
    {
        cout << "Player " << --player << " wins!" << endl;
        if (player == 1)
            player1Score++;
        else
            player2Score++;
        saveHighScore(player1, player2, player);
    }
    else
    {
        cout << "Game Draw" << endl;
        saveHighScore(player1, player2, 0);
    }

    displayHighScores();

    cin.ignore();
    cin.get();

    return 0;
}
