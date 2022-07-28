

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

  
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {   
           
            if (i == n - 1 && j == m - 1) {
                continue;
            }
           
            else if (i == n - 1) {
                grid[i][j] = grid[i][j] + grid[i][j + 1];
            }
          
            else if (j == m - 1) {
                grid[i][j] = grid[i][j] + grid[i + 1][j];
            }
           
            else {
                grid[i][j] = grid[i][j] + min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
    }
  
    return grid[0][0];
}

