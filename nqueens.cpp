void addSolution(int n, vector < vector < int >> & ans, vector < int > & row) {
    vector < int > currentAnswer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (row[j] == i) {
                currentAnswer.push_back(1);
            } else {
                currentAnswer.push_back(0);
            }
        }
    }

    ans.push_back(currentAnswer);
}

void solve(int col, int n, vector < vector < int >> & ans, vector < int > & row, vector < int > & d1, vector < int > & d2) {
    if (col == n) {
        addSolution(n, ans, row);
        return;
    }

    for (int i = 0; i < n; i++) {
        if ((row[i] == -1) && (d1[col - i + n - 1] == -1) && (d2[col + i] == -1)) {
            row[i] = d1[col - i + n - 1] = d2[col + i] = col;
            solve(col + 1, n, ans, row, d1, d2);
            row[i] = d1[col - i + n - 1] = d2[col + i] = -1;
        }
    }

    return;
}

vector < vector < int >> solveNQueens(int n) {
    vector < vector < int >> ans;
    vector < int > row(30, -1), d1(30, -1), d2(30, -1);
    solve(0, n, ans, row, d1, d2);
    return ans;
}
