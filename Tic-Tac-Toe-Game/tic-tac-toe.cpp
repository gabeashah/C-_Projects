#include <iostream>

using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkWin(){
    if (square[1] == square[2] && square[2] == square[3]){
            
            return 1;
    }
    else if (square[4] == square[5] && square[5] == square[6]) {
            return 1;
    } else if (square[7] == square[8] && square[8] == square[9]) {
            return 1;
    } else if (square[1] == square[4] && square[4] == square[7]) {
            return 1;
    } else if (square[2] == square[5] && square[5] == square[8]) {
            return 1;
    } else if (square[3] == square[6] && square[6] == square[9]) {
            return 1;
    } else if (square[1] == square[5] && square[5] == square[9]) {
            return 1;
    } else if (square[3] == square[5] && square[5] == square[7]) {
            return 1;
    } else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') {
            return 0;
    } else {
        return -1;
    }
}

void board() {
    system("cis");
    cout << "\nTic Tac Toe Game\n";
    cout << "Player 1(x) & Player 2(o)" << endl;

    cout << "      |      |   " << endl;
    cout << " " << square[1] << "    |   " << square[2] << "  |   " << square[3] << endl;

    cout << "______|______|______" << endl;
    cout << "      |      |   " << endl;

    cout << " " << square[4] << "    |   " << square[5] << "  |   " << square[6] << endl;

    cout << "______|______|______" << endl;
    cout << "      |      |   " << endl;

    cout << " " << square[7] << "    |   " << square[8] << "  |   " << square[9] << endl;
    cout << "      |      |   " << endl;
}


int main() {

    int player = 1, i, choice;
    char mark;

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
            square[choice] = mark;
        else {
            cout << "Invalid move\n";
            player--;
            cin.ignore();
            cin.get();
        }

        i = checkWin();
        player++;

    } while (i == -1);

    board();
    if (i == 1)
        cout << "==>\aPlayer " << --player << " wins!\n";
    else
        cout << "==>\aGame draw\n";

    return 0;
}