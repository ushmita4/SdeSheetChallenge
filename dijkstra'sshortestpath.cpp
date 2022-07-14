

vector<int> dijkstraHelper(vector<vector<pair<int, int>>> &adjacencyList, int vertices, int source) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(vertices, INT_MAX);

   
    pq.push({0, source});

   
    distance[source] = 0;
    vector<bool> visited(vertices, false);

    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); it++) {
            int v = it -> first;
            int dist = it -> second;

            if (visited[v] == false && distance[v] > distance[u] + dist) {
                distance[v] = distance[u] + dist;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    vector<vector<pair<int, int>>> adjacencyList(vertices);

   
    for (int i = 0; i < (int)vec.size(); i++) {
        
        adjacencyList[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adjacencyList[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    return dijkstraHelper(adjacencyList, vertices, 0);
}
