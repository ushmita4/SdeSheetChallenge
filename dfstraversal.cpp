void depthFirstSearchHelper(int vertex, vector<int> &visited, vector<int> &singleComponent, vector<vector<int>> &graph)
{
    visited[vertex] = 1;
    singleComponent.push_back(vertex);

    for (auto child : graph[vertex])
    {
     
        if (!visited[child])
        {
            depthFirstSearchHelper(child, visited, singleComponent, graph);
        }
    }
}
   
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        a = edges[i][0];
        b = edges[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> components;
    vector<int> visited(V, 0);

    for (int vertex = 0; vertex < V; vertex++)
    {
        if (!visited[vertex])
        {
            vector<int> singleComponent;
            depthFirstSearchHelper(vertex, visited, singleComponent, graph);
            components.push_back(singleComponent);
        }
    }
    return components;
}
