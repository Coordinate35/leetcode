// DFS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void dfs(char board[][9], bool loger[][9][9], int y, int x, bool* is_complete, int number_to_fill) {
    int i, j;
    int chosen;
    int block_start_y;
    int block_start_x;
    for (i = 0; i < 9; i++) {
        if (true == loger[y][x][i]) {
            chosen = i;
            break;
        }
    }
    if (9 == i) {
        return;
    }
    board[y][x] = chosen + 48 + 1;
    loger[y][x][chosen] = false;
    number_to_fill -= 1;
    for (i = 0; i < 9; i++) {
        if ('.' == board[y][i]) {
            loger[y][i][chosen] = false;
        }
        if ('.' == board[i][x]) {
            loger[i][x][chosen] = false;
        }
    }
    block_start_y = y / 3 * 3;
    block_start_x = x / 3 * 3;
    for (i = 0; i < 9; i++) {
        if ('.' == board[block_start_y + i / 3][block_start_x + i % 3]) {
            loger[block_start_y + i / 3][block_start_x + i % 3][chosen] = false;
        }
    }
    if (0 == number_to_fill) {
        *is_complete = true;
    }
    for (i = x; i < 9; i++) {
        if (false == *is_complete) {
            for (j = 0; j < 9; j++) {
                if ('.' == board[i][j]) {
                    dfs(board, loger, i, j, is_complete, number_to_fill);
                    break;
                }
            }
        } else {
            break;
        }
    }
    if (false == *is_complete) {
        for (i = 0; i < 9; i++) {
            if ('.' == board[block_start_y + i / 3][block_start_x + i % 3]) {
                loger[block_start_y + i / 3][block_start_x + i % 3][chosen] = true;
            }
        }
        for (i = 0; i < 9; i++) {
            if ('.' == board[y][i]) {
                loger[y][i][chosen] = true;
            }
            if ('.' == board[i][x]) {
                loger[i][x][chosen] = true;
            }
        }
        board[y][x] = '.';
        loger[y][x][chosen] = true;
    }
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    bool loger[9][9][9];
    bool is_complete = false;
    char changeable_board[9][9];
    int i, j, k;
    int block_start_i, block_start_j;
    int number_to_fill = 0;
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            changeable_board[i][j] = board[i][j];
        }
    }
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if ('.' == board[i][j]) {
                for (k = 0; k < 9; k++) {
                    loger[i][j][k] = true;
                }
                for (k = 0; k < 9; k++) {
                    if ('.' != board[i][k]) {
                        loger[i][j][board[i][k] - 48 - 1] = false;
                    }
                }
                for (k = 0; k < 9; k++) {
                    if ('.' != board[k][j]) {
                        loger[i][j][board[k][j] - 48 - 1] = false;
                    }
                }
                block_start_i = i / 3 * 3;
                block_start_j = j / 3 * 3;
                for (k = 0; k < 9; k++) {
                    if ('.' != board[block_start_i + k / 3][block_start_j + k % 3]) {
                        loger[i][j][board[block_start_i + k / 3][block_start_j + k % 3] - 48 - 1] = false;
                    }
                }
            } else {
                for (k = 0; k < 9; k++) {
                    loger[i][j][k] = false;
                }
            }
        }
    }
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if ('.' == board[i][j]) {
                number_to_fill += 1;
            }
        }
    }
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if ('.' == board[i][j]) {
                dfs(changeable_board, loger, i, j, &is_complete, number_to_fill);
            }
        }
    }
}

int main() {
    int i, j;
    char *board[] = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759.."
    };
    solveSudoku(board, 9, 9);
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}