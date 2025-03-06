#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int player1Score = 0;
int player2Score = 0;
string player1_name, player2_name;


int checkwin();
void board();
void saveHighScore(int player);
void displayHighScores();
int getPlayerChoice();
int getRandomMove();

void clearSquare()
{
       square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
int player1Score = 0;
int player2Score = 0;
string player1_name, player2_name;
int player = 1,i,choice;
}
void setColor(int colorCode) {
    cout << "\033[0;" << colorCode << "m";
}
int main()
{
bool playAgain = true;	
while(playAgain) {
	int gameMode;	     
	
	char again;
    cout << "\n\nTic Tac Toe" << endl;
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
    
    if(gameMode == 1) {
       			cout << "\nEnter Player 1 Name: ";
       			cin >> player1_name;
       			cout << "\nEnter Player 2 Name: ";
       			cin >> player2_name;
			}
	int player = 1,i,choice;

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
    }while(i==-1);
    board();
   if (i == 1) {
    cout << "\n==>\aPlayer " << --player << " wins!" << endl << endl;
    string winner = "";
    if (player == 1) {
        player1Score++;
        setColor(31); // Set color to red for Player 1 (X)
        winner = player1_name;
    } else {
        player2Score++;
        setColor(34); // Set color to blue for Player 2 (O)
        winner = player2_name;
    }
    
    if(!player1_name.empty() && !player2_name.empty()) {
    	cout << winner << "'s Score: " << (player == 1 ? player1Score : player2Score) << endl;
	} else {
		cout << "Player " << player << "'s Score: " << (player == 1 ? player1Score : player2Score) << endl;
	}
    
    saveHighScore(player);
    setColor(0); // Reset color to default
}
    else{
	
        cout<<"==>\aGame draw"<<endl;
	}
	
	 displayHighScores();
    
//	cin.ignore();
//    cin.get();
    
	cout << "\nDo you want to play again? (y/n): ";
	        cin >> again;
	
	        if (again == 'n' || again == 'N') {
	            playAgain = false;
	            cout << "\nThank you for playing! Goodbye." << endl;
	            exit(0);
	        } else {
	            clearSquare();
	        	system("cls");
	        }
	    }
	
	return 0;
}

/*****
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
******/

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
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}


/*********
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********/


void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    
    
    if(!player1_name.empty() && !player2_name.empty()) {
    	cout << "Player 1: \033[1;31m"<< player1_name <<"(X)\033[0m  - Player 2: \033[1;34m" << player2_name << " (O)\033[0m" << endl << endl;
	} else {
		cout << "\033[1;31mPlayer 1 (X)\033[0m  -  \033[1;34mPlayer 2 (O)\033[0m" << endl << endl;
	}

    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  ";
    if (square[1] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[1] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    
    cout << square[1];
    setColor(0); // Reset color to default
    cout << "  |  ";
    if (square[2] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[2] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[2];
    setColor(0); // Reset color to default
    cout << "  |  ";
    if (square[3] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[3] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[3];
    setColor(0); // Reset color to default
    cout << endl;

    cout << "__|_|__" << endl;
    cout << "     |     |     " << endl;

    cout << "  ";
    if (square[4] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[4] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[4];
    setColor(0); // Reset color to default
    cout << "  |  ";
    if (square[5] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[5] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[5];
    setColor(0); // Reset color to default
    cout << "  |  ";
    if (square[6] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[6] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[6];
    setColor(0); // Reset color to default
    cout << endl;

    cout << "__|_|__" << endl;
    cout << "     |     |     " << endl;

    cout << "  ";
    if (square[7] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[7] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[7];
    setColor(0); // Reset color to default
    cout << "  |  ";
    if (square[8] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[8] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[8];
    setColor(0); // Reset color to default
    cout << "  |  ";
    if (square[9] == 'X')
        setColor(31); // Set color to red for 'X'
    else if (square[9] == 'O'){
    	setColor(34); // Set color to red for 'X'
	}
    cout << square[9];
    setColor(0); // Reset color to default
    cout << endl;

    cout << "     |     |     " << endl << endl;
}


void saveHighScore(int player) {
    ofstream file("high_scores.txt", ios::app);
    if (file.is_open()) {
    	if(!player1_name.empty() && !player2_name.empty()) {
    	 file << player1_name <<" Score: " << player1Score << endl;
          file << player2_name <<" Score: " << player2Score << endl;
		} else {
		 file << "Player 1 Score: " << player1Score << endl;
         file << "Player 2 Score: " << player2Score << endl;
		}
        
        file.close();
    }
}

void displayHighScores()
{
 ifstream file("high_scores.txt");
    string line;
    int player1_score = 0;
    int player2_score = 0;
    
    
    while (getline(file, line)) {
    	if(!player1_name.empty() && !player2_name.empty()) {
    		if (line.find(player1_name + " Score") != string::npos) {
            player1_score += atoi(line.substr(line.find(":") + 2).c_str());
	        } else if (line.find(player2_name +" Score") != string::npos) {
	            player2_score += atoi(line.substr(line.find(":") + 2).c_str());
	        }
		} else {
			if (line.find("Player 1 Score") != string::npos) {
            player1_score += atoi(line.substr(line.find(":") + 2).c_str());
	        } else if (line.find("Player 2 Score") != string::npos) {
	            player2_score += atoi(line.substr(line.find(":") + 2).c_str());
	        }
		}
        
    }
    
    if(!player1_name.empty() && !player2_name.empty()) {
    	cout << "Total score for " << player1_name << ": " << player1_score << endl;
    	cout << "Total score for " << player2_name << ": " << player2_score << endl;
 
	} else {
		cout << "Total score for Player 1: " << player1_score << endl;
    cout << "Total score for Player 2: " << player2_score << endl;
	}
    
    if (player1_score > player2_score){
    	cout << player1_name <<" is leading";
	}
	else{
		cout << player2_name <<" is leading";
	}
}
int getPlayerChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

int getRandomMove()
{
    int move;
    srand(time(0));
    do {
        move = rand() % 9 + 1;
    } while (square[move] != '0' + move);
    return move;
}
