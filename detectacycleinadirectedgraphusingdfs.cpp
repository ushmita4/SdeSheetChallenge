/*
    Time Complexity: O(N+M)
    Space Complexity: O(N)
    
    Where N is the number of nodes and M is the number of edges in the given graph.
*/

#include <list>

#include <queue>

class Graph {
    int noOfNodes;

    list < int > * adj;

    public:
        
        Graph(int noOfNodes);

    
    void addEdge(int v, int w);

    // Returns true if there exists a cycle in the given graph.
    bool checkCyclic();
};

Graph::Graph(int noOfNodes) {
    this -> noOfNodes = noOfNodes;
    adj = new list < int > [noOfNodes];
}

void Graph::addEdge(int a, int b) {
    adj[a].push_back(b);
}

bool Graph::checkCyclic() {

    vector < int > inDegree(noOfNodes, 0);

    
    for (int u = 0; u < noOfNodes; u++) {
        for (auto v: adj[u]) {
            inDegree[v]++;
        }
    }

    
    queue < int > zeroInDegreeQ;

    for (int i = 0; i < noOfNodes; i++) {
        if (inDegree[i] == 0) {
            zeroInDegreeQ.push(i);
        }
    }

  
    int cnt = 0;

    vector < int > topoOrdering;


    while (zeroInDegreeQ.empty() == false) {
       
        int u = zeroInDegreeQ.front();
        zeroInDegreeQ.pop();
        topoOrdering.push_back(u);

        

        list < int > ::iterator itr;

        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
           
            if (--inDegree[ * itr] == 0) {
                zeroInDegreeQ.push( * itr);
            }
        }

        cnt++;
    }

  
    if (cnt != noOfNodes) {
        return true;
    } else {
        return false;
    }
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    Graph directedG(n);

    int m = edges.size();

    for (int i = 0; i < m; i++) {
        directedG.addEdge(edges[i].first - 1, edges[i].second - 1);
    }

    return directedG.checkCyclic();
}
