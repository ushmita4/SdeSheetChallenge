#include <unordered_map>

#define n 9

bool isValid(int matrix[n][n]) {
    unordered_map<int, int> row[n], column[n], subMatrix[3][3];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == 0) {
                continue;
            }

            row[r][matrix[r][c]] += 1;
            column[c][matrix[r][c]] += 1;
            subMatrix[r / 3][c / 3][matrix[r][c]] += 1;

            if (subMatrix[r / 3][c / 3][matrix[r][c]] > 1 || column[c][matrix[r][c]] > 1 ||
                row[r][matrix[r][c]] > 1) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int matrix[n][n], int i, int j) {

    if (i == n - 1 && j == n) {
        return true;
    }

    if (j == n) {
        i++;
        j = 0;
    }

    if (matrix[i][j] != 0) {
        return solve(matrix, i, j + 1);
    }

    for (int digit = 1; digit <= n; digit++) {
        matrix[i][j] = digit;

        if (isValid(matrix)) {
            if (solve(matrix, i, j + 1)) {
                return true;
            }
        }

        matrix[i][j] = 0;
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {

    return solve(matrix, 0, 0);
}
