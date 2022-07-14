

#include <queue>

void printBFSHelper(vector<vector<int>> &adjacency_matrix, int source, vector<bool> &visited,vector<int> &result)
{
    queue<int> queue;
    visited[source] = true;
    queue.push(source);

    
    while (!queue.empty())
    {
        int front = queue.front();
        queue.pop();
        result.push_back(front);

        for (int i = 0; i < adjacency_matrix.size(); i++)
        {
            if (adjacency_matrix[front][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}


vector<vector<int>> createAdjMat(int vertex, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adjacency_matrix(vertex);

    for (int i = 0; i < vertex; i++)
    {
        adjacency_matrix[i] = vector<int>(vertex);

        for (int j = 0; j < vertex; j++)
        {
            adjacency_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {

        adjacency_matrix[edges[i].first][edges[i].second] = 1;
        adjacency_matrix[edges[i].second][edges[i].first] = 1;
    }
    return adjacency_matrix;
}

vector<int> BFS(int vertex, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adjacency_matrix = createAdjMat(vertex, edges);
    
    vector<bool> visited(adjacency_matrix.size());

    for(int i =0; i<vertex; i++){
        visited[i] = false;
    }
    vector<int> result;
  
    for (int i = 0; i < adjacency_matrix.size(); i++)
    {
        if (!visited[i])
        {
            printBFSHelper(adjacency_matrix, i, visited,result);
        }
    }

    return result;

}
