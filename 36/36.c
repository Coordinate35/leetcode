// Notice: A valid soduku doesn't depend on its solvability

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void init(bool* a, int size) {
    int i;
    while (size > 0) {
        a[size] = false;
        size -= 1;
    }
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    bool is_showed[9];
    int i, j, k;
    int start[] = {0, 3, 6};
    for (i = 0; i < boardRowSize; i++) {
        init(is_showed, 9);
        for (j = 0; j < boardColSize; j++){
            if (('0' <= board[i][j]) && ('9' >= board[i][j])) {
                if (true == is_showed[board[i][j] - 48]) {
                    return false;
                }
                is_showed[board[i][j] - 48] = true;
            }
        }
    }
    for (i = 0; i < boardColSize; i++) {
        init(is_showed, 9);
        for (j = 0; j < boardRowSize; j++){
            if (('0' <= board[j][i]) && ('9' >= board[j][i])) {
                if (true == is_showed[board[j][i] - 48]) {
                    return false;
                }
                is_showed[board[j][i] - 48] = true;
            }
        }
    }

    for (i = 0; i < 9; i++) {
        init(is_showed, 9);
        for (j = start[i % 3]; j < start[i % 3] + 3; j++) {
            for (k = start[i / 3]; k < start[i / 3] + 3; k++) {
                if (('0' <= board[j][k]) && ('9' >= board[j][k])) {
                    if (true == is_showed[board[j][k] - 48]) {
                        return false;
                    }
                    is_showed[board[j][k] - 48] = true;
                }    
            }
        }
    }

    return true;
}

int main() {
    char *board[9] = {
        ".87654321",
        "2........",
        "3........",
        "4........",
        "5........",
        "6........",
        "7........",
        "8........",
        "9........"
    };
    bool result = isValidSudoku(board, 9, 9);
    printf("%d\n", result);
    return 0;
}