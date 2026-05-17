#include <iostream>
using namespace std;

char board[20][40];
int pRow = 18;
int pCol = 20;

void setup() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 39) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }
    board[pRow][pCol] = 'P';
    board[5][10] = 'e';
    board[8][30] = 'e';
}

void printBoard() {
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void movePlayerLeft() {
    if (board[pRow][pCol - 1] == ' ') {
        board[pRow][pCol] = ' ';
        pCol--;
        board[pRow][pCol] = 'P';
    }
}

void movePlayerRight() {
    if (board[pRow][pCol + 1] == ' ') {
        board[pRow][pCol] = ' ';
        pCol++;
        board[pRow][pCol] = 'P';
    }
}

void fire() {
    if (board[pRow - 1][pCol] == ' ') {
        board[pRow - 1][pCol] = '.';
    }
}

void moveFire() {
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 39; j++) {
            if (board[i][j] == '.') {
                board[i][j] = ' ';
                if (i - 1 > 0) {
                    if (board[i - 1][j] == 'e') {
                        board[i - 1][j] = ' ';
                    } else {
                        board[i - 1][j] = '.';
                    }
                }
            }
        }
    }
}

int main() {
    setup();
    char input;
    while (true) {
        printBoard();
        cout << "a: Left, d: Right, s: Fire, x: Exit -> ";
        cin >> input;
        if (input == 'a') movePlayerLeft();
        if (input == 'd') movePlayerRight();
        if (input == 's') fire();
        if (input == 'x') break;
        moveFire();
    }
    return 0;
}