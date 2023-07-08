#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[][SIZE]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int isBoardFull(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int checkWin(char board[][SIZE], char symbol) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;

    return 0;
}

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char currentPlayer = 'X';

    initializeBoard(board);

    printf("Welcome to the Tic-Tac-Toe Game!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");

    while (1) {
        printf("\n");
        printf("Current Board:\n");
        printBoard(board);

        printf("Player %c's turn\n", currentPlayer);

        printf("Enter the row (0-2): ");
        scanf("%d", &row);

        printf("Enter the column (0-2): ");
        scanf("%d", &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if (board[row][col] != ' ') {
            printf("That position is already occupied. Please try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printf("\n");
            printf("Current Board:\n");
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull(board)) {
            printf("\n");
            printf("Current Board:\n");
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
