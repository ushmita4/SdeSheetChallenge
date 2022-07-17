#include <queue>


int isValid(vector<vector<bool>>& visited, int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false;
}


int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int time = 0;

   
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
 
    queue<pair<int, int>> q;

    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int i, j;

    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(q.size() > 0)
    {
       
        int levelSize = q.size();

        while(levelSize--)
        {
            pair<int,int> currCell = q.front();
            q.pop();

            i = currCell.first;
            j = currCell.second;
            
            
            for(int k = 0; k < 4; k++)
            {
                int nextI = i + dx[k];
                int nextJ = j + dy[k];

                if(isValid(visited, nextI, nextJ, n, m) && grid[nextI][nextJ] == 1)
                {
                    q.push({nextI, nextJ});
                    visited[nextI][nextJ] = true;
                }
            }
        }

       
        time++;
    }

    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == false)
            {
                return -1;
            }
        }
    }

 
    return max(0, time - 1);
}
