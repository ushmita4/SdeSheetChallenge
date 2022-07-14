#include <algorithm>


void make_set(int v, vector <int> &parent, vector <int> &rank) {
    parent[v] = v;
    rank[v] = 0;
}


int find_set(int v, vector <int> &parent) {
    if (v == parent[v]) {
        
        return v;
    } else {
        
        return parent[v] = find_set(parent[v], parent);
    }
}


void union_sets(int a, int b, vector <int> &parent, vector <int> &rank) {
   
    a = find_set(a, parent);
    b = find_set(b, parent);

    if (a != b) {
        if (rank[a] < rank[b]) {
        
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}


bool compare(vector <int> const &a, vector <int> const &b) {
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector <vector<int> > &graph) {
 
    vector <int> parent(n);
    vector <int> rank(n);

    for (int i = 1; i <= n; i++) {
        
        make_set(i, parent, rank);
    }

   
    int cost = 0;

    
    sort(graph.begin(), graph.end(), compare);


    for (auto edge: graph) {
        
        if (find_set(edge[0], parent) != find_set(edge[1], parent)) {
            
            cost = cost + edge[2];

          
            union_sets(edge[0], edge[1], parent, rank);
        }
    }
    return cost;
}
