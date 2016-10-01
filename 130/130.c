#include <stdio.h>
#include <stdlib.h>

// Recursive method is not ok because it will cause stackoverflow

void push(int *row_index, int *col_index, int *queue_start, int *queue_end, int row, int col) {
    int i;
    for (i = *queue_start; i <= *queue_end; i++) {
        if ((row_index[i] == row) && (col_index[i] == col)) {
            return;
        }
    }
    *queue_end += 1;
    row_index[*queue_end] = row;
    col_index[*queue_end] = col;
}

void pop(int *row_index, int *col_index, int *queue_start, int *queue_end) {
    *queue_start += 1;
}

void bfs_change(char** board, int i, int j, int boardRowSize, int boardColSize, int *row_index, int *col_index, int *queue_start, int *queue_end) {
    push(row_index, col_index, queue_start, queue_end, i, j);
    while (*queue_start <= *queue_end) {
        if (0 <= row_index[*queue_start] - 1) {
            if ('O' == board[row_index[*queue_start] - 1][col_index[*queue_start]]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start] - 1, col_index[*queue_start]);
            }
        }
        if (boardRowSize - 1 >= row_index[*queue_start] + 1) {
            if ('O' == board[row_index[*queue_start] + 1][col_index[*queue_start]]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start] + 1, col_index[*queue_start]);
            }
        }
        if (0 <= col_index[*queue_start] - 1) {
            if ('O' == board[row_index[*queue_start]][col_index[*queue_start] - 1]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start], col_index[*queue_start] - 1);
            }
        }
        if (boardColSize - 1 >= col_index[*queue_start] + 1) {
            if ('O' == board[row_index[*queue_start]][col_index[*queue_start] + 1]) {
                push(row_index, col_index, queue_start, queue_end, row_index[*queue_start], col_index[*queue_start] + 1);
            }
        }
        board[row_index[*queue_start]][col_index[*queue_start]] = 'E';
        pop(row_index, col_index, queue_start, queue_end);
    }
}

void solve(char** board, int boardRowSize, int boardColSize) {
    int i = 0;
    int j = 0;
    int point_number = boardRowSize * boardColSize;
    int *row_index;
    int *col_index;
    int queue_start = 0;
    int queue_end = -1;
    row_index = (int*)malloc(point_number * sizeof(int));
    col_index = (int*)malloc(point_number * sizeof(int));
    for (i = 0; i < boardRowSize; i++) {
        if ('O' == board[i][0]) {
            bfs_change(board, i, 0, boardRowSize, boardColSize, row_index, col_index, &queue_start, &queue_end);
        }
        if ('O' == board[i][boardColSize - 1]) {
            bfs_change(board, i, boardColSize - 1, boardRowSize, boardColSize, row_index, col_index, &queue_start, &queue_end);
        }
    }
    for (j = 0; j < boardColSize; j++) {
        if ('O' == board[0][j]) {
            bfs_change(board, 0, j, boardRowSize, boardColSize, row_index, col_index, &queue_start, &queue_end);
        }
        if ('O' == board[boardRowSize - 1][j]) {
            bfs_change(board, boardRowSize - 1, j, boardRowSize, boardColSize, row_index, col_index, &queue_start, &queue_end);
        }
    }
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if ('O' == board[i][j]) {
                board[i][j] = 'X';
            }
            if ('E' == board[i][j]) {
                board[i][j] = 'O';
            }
        }
    }
}   

int main() {
    char** board;
    int boardRowSize = 3;
    int boardColSize = 3;
    int i, j;
    board = (char**)malloc(boardRowSize * sizeof(char*));
    for (i = 0; i < boardRowSize; i++) {
        board[i] = (char*)malloc(boardColSize * sizeof(char));
        gets(board[i]);
    }
    solve(board, boardRowSize, boardColSize);
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}