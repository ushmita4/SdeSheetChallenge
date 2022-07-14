

int findparent (int i, vector<int>& parent)
{
    if (i == parent[i])
    {
        return i;
    }
    return parent[i] = findparent (parent[i], parent);
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> parent(n + 1, 0);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        rank[i] = 1;
        parent[i] = i;
    }

    for (vector<int>& ar : edges)
    {
        int u = ar[0];
        int v = ar[1];

        int p1 = findparent (u, parent);
        int p2 = findparent (v, parent);

        if (p1 != p2)
        {
            if (rank[p1] < rank[p2])
            {
                parent[p1] = p2;
            }
            else if (rank[p1] > rank[p1])
            {
                parent[p2] = p1;
            }
            else
            {
                parent[p1] = p2;
                rank[p2]++;
            }
        }
        else
        {
            return "Yes";
        }
    }
    
    return "No";
}
