

void insertCurrentState(vector<vector<int>> &solution, vector<vector<int>> &ans, int n){
   
    vector<int> currentState;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            currentState.push_back(solution[i][j]);
        }
    }
    ans.push_back(currentState);
}

void solveMaze(vector<vector<int>> &maze, vector<vector<int>> &solution, vector<vector<int>> &ans, int x, int y, int n){

    if (x == n - 1 && y == n - 1){
        solution[x][y] = 1;
       
        insertCurrentState(solution, ans, n); 
        return;
    }

  
    if (x > n - 1 || x < 0 || y > n - 1 || y < 0){
        return;
    }

   
    if (maze[x][y] == 0 || solution[x][y] == 1){
        return;
    }

   
    solution[x][y] = 1;

    
    solveMaze(maze, solution, ans, x - 1, y, n); 
    
    solveMaze(maze, solution, ans, x + 1, y, n); 
  
    solveMaze(maze, solution, ans, x, y - 1, n); 

    solveMaze(maze, solution, ans, x, y + 1, n);

   
    solution[x][y] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> maze, int n){
   
    vector<vector<int>> solution(n, vector<int>(n, 0));

 
    vector<vector<int>> ans;

  
    solveMaze(maze, solution, ans, 0, 0, n);

 
    return ans;
}
