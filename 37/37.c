// Pure dfs

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

bool solve(char** board) {
    int i, j, k;
    bool result = false;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if ('.' == board[i][j]) {
                for (k = 0; k < 9; k++) {
                    board[i][j] = k + 48 + 1;
                    if (true == isValidSudoku(board, 9, 9)) {
                        result = solve(board);
                        if (true == result) {
                            return true;
                        }
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    bool result;
    result = solve(board);
}