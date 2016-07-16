#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool dfs(char** board, int boardRowSize, int boardColSize, int i, int j, char* word, int current_index) {
    int word_length = strlen(word);
    char replace = '\0';
    char buffer = board[i][j];
    bool trial_result;
    board[i][j] = replace;
    if (current_index == word_length - 1) {
        return true;
    }
    if ((i - 1 >= 0) && (board[i - 1][j] == word[current_index + 1])) {
        trial_result = dfs(board, boardRowSize, boardColSize, i - 1, j, word, current_index + 1);
        if (true == trial_result) {
            return true;
        }
    }
    if ((j + 1 < boardColSize) && (board[i][j + 1] == word[current_index + 1])) {
        trial_result = dfs(board, boardRowSize, boardColSize, i, j + 1, word, current_index + 1);
        if (true == trial_result) {
            return true;
        }
    }
    if ((i + 1 < boardRowSize) && (board[i + 1][j] == word[current_index + 1])) {
        trial_result = dfs(board, boardRowSize, boardColSize, i + 1, j, word, current_index + 1);
        if (true == trial_result) {
            return true;
        }
    }
    if ((j - 1 >= 0) && (board[i][j - 1] == word[current_index + 1])) {
        trial_result = dfs(board, boardRowSize, boardColSize, i, j - 1, word, current_index + 1);
        if (true == trial_result) {
            return true;
        }
    }
    board[i][j] = buffer;
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int current_index = 0;
    int i, j;
    bool result;
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (word[current_index] == board[i][j]) {
                result = dfs(board, boardRowSize, boardColSize, i, j, word, current_index);
                if (true == result) {
                    return true;
                }
            }
        }
    }
    return false;   
}

int main() {
    char **board;
    char word[] = "ABCCED";
    int boardRowSize = 3;
    int boardColSize = 4;
    int i;
    bool result;
    board = (char**)malloc(boardRowSize * sizeof(char*));
    for (i = 0; i < boardRowSize; i++) {
        board[i] = (char*)malloc((boardColSize + 1) * sizeof(char));
        scanf("%s", board[i]);
        board[i][boardColSize] = '\0';
    }
    result = exist(board, boardRowSize, boardColSize, word);
    return 0;
}