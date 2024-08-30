#include <stdbool.h>

bool dfs(char** board, int boardSize, int* boardColSize, int row, int col, const char* word, int index) {
    if (word[index] == '\0') {
        return true;  // All characters have been matched
    }

    // Check boundaries and if the current cell matches the current character in word
    if (row < 0 || col < 0 || row >= boardSize || col >= *boardColSize || board[row][col] != word[index]) {
        return false;
    }

    // Temporarily mark the cell as visited
    char temp = board[row][col];
    board[row][col] = '#';  // Mark as visited

    // Explore the four possible directions (up, down, left, right)
    bool found = dfs(board, boardSize, boardColSize, row - 1, col, word, index + 1) ||
                 dfs(board, boardSize, boardColSize, row + 1, col, word, index + 1) ||
                 dfs(board, boardSize, boardColSize, row, col - 1, word, index + 1) ||
                 dfs(board, boardSize, boardColSize, row, col + 1, word, index + 1);

    // Restore the cell's original value
    board[row][col] = temp;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, const char* word) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (dfs(board, boardSize, boardColSize, i, j, word, 0)) {
                return true;
            }
        }
    }
    return false;
}
