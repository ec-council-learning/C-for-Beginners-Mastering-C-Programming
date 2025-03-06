#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    ifstream file("high_score.txt");
    string line;
    int player1_score = 0;
    int player2_score = 0;

    while (getline(file, line)) {
        if (line.find("Player 1 Score") != string::npos) {
            player1_score += atoi(line.substr(line.find(":") + 2).c_str());
        } else if (line.find("Player 2 Score") != string::npos) {
            player2_score += atoi(line.substr(line.find(":") + 2).c_str());
        }
    }

    int total_score = player1_score + player2_score;
    cout << "Total score for Player 1: " << player1_score << endl;
    cout << "Total score for Player 2: " << player2_score << endl;
    cout << "Total score: " << total_score << endl;

    return 0;
}

