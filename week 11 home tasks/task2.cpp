#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

const int ROWS = 10;
const int COLS = 20;

char maze[ROWS][COLS];
int playerX = 1, playerY = 1;
int health = 100, lives = 3, score = 0;

struct Enemy {
    int x, y, type; 
    int health;
};

vector<Enemy> enemies = {
    {5, 5, 1, 30}, 
    {2, 15, 2, 50},
    {8, 10, 3, 40}
};

void initMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) maze[i][j] = '#';
            else maze[i][j] = ' ';
        }
    }
}

void draw() {
    system("cls");
    cout << "Score: " << score << " | Health: " << health << " | Lives: " << lives << endl;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bool isEnemy = false;
            for (auto& e : enemies) {
                if (e.x == i && e.y == j && e.health > 0) {
                    if (e.type == 1) cout << 'E';
                    else if (e.type == 2) cout << 'X';
                    else cout << 'S';
                    isEnemy = true;
                    break;
                }
            }
            if (!isEnemy) {
                if (i == playerX && j == playerY) cout << 'P';
                else cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

void playerFire() {
    score += 10;
    for (auto& e : enemies) {
        if (abs(e.x - playerX) < 2 && abs(e.y - playerY) < 2) {
            e.health -= 20;
            if (e.health <= 0) score += 50;
        }
    }
}

void enemyAction() {
    for (auto& e : enemies) {
        if (e.health > 0) {
            if (e.type == 1) e.y--; 
            if (e.type == 2) { health -= 5; } 
            if (e.type == 3) { if (playerX > e.x) e.x++; else e.x--; }
        }
    }
}

int main() {
    initMaze();
    while (lives > 0) {
        draw();
        char input = _getch();
        
        if (input == 'w' && maze[playerX - 1][playerY] != '#') playerX--;
        if (input == 's' && maze[playerX + 1][playerY] != '#') playerX++;
        if (input == 'a' && maze[playerX][playerY - 1] != '#') playerY--;
        if (input == 'd' && maze[playerX][playerY + 1] != '#') playerY++;
        if (input == 'f') playerFire();

        enemyAction();

        if (health <= 0) {
            lives--;
            health = 100;
            playerX = 1; playerY = 1;
        }
        
        if (score > 200) {
            cout << "Level Up!" << endl;
            break; 
        }
    }
    
    if (lives <= 0) cout << "Game Over!" << endl;
    return 0;
}