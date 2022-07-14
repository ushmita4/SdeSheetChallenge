

#include <queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    } 
    
    vector<int> indegree(v);
    for(auto edge : edges) {
        indegree[edge[1]]++;
    }
    
    queue<int> que;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            que.push(i);
        }
    }
    vector<int> result; 
    while(!que.empty()) {
        int src = que.front();
        que.pop();
        result.push_back(src);
        for(int node : adj[src]) {
            indegree[node]--;
            if(indegree[node] == 0) {
                que.push(node);
            }
        }
    }
    return result;
}
