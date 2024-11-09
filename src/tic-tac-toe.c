#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Global variables
char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board with numbers
void initializeBoard() {
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num + '0'; // Convert integer to char ('1' to '9')
            num++;
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won the game
int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1; // Row or Column win
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1; // Diagonal win
    }
    return 0; // No winner
}

// Function to check if the game is a draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Empty cell found, not a draw
            }
        }
    }
    return 1; // It's a draw
}

// Function to take the player's turn
void takeTurn() {
    int choice;
    printf("Player %c, enter a number between 1 and 9: ", currentPlayer);
    scanf("%d", &choice);

    // Validate input and place mark
    if (choice < 1 || choice > 9) {
        printf("Invalid input! Please choose a number between 1 and 9.\n");
        takeTurn();
    }
    else {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if cell is already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already taken! Try again.\n");
            takeTurn();
        }
        else {
            board[row][col] = currentPlayer;
        }
    }
}

// Main game function
int main() {
    initializeBoard();

    while (1) {
        printBoard();
        takeTurn();

        if (checkWinner()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch player (X <-> O)
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
