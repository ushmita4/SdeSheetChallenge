

#include <stack>


int discoveryTime = 1;

void dfs(vector<vector<int>> &graph, int node, vector<int> &disc, vector<int> &low, vector<bool> &inStack, stack<int> &nodeStack, vector<vector<int>> &ans)
{
    disc[node] = discoveryTime;
    low[node] = discoveryTime;

    ++discoveryTime;

    nodeStack.push(node);
    inStack[node] = true;

    
    for (int v : graph[node])
    {
        
        if (disc[v] == -1)
        {
            dfs(graph, v, disc, low, inStack, nodeStack, ans);
            low[node] = min(low[node], low[v]);
        }
        else if (inStack[v])
        {
            low[node] = min(low[node], disc[v]);
        }
    }

 
    if (low[node] == disc[node])
    {
      
        vector<int> component;
        int u;
        while (nodeStack.top() != node)
        {
            u = nodeStack.top();
            nodeStack.pop();
            inStack[u] = false;

            component.push_back(u);
        }

        u = nodeStack.top();
        nodeStack.pop();
        inStack[u] = false;

        component.push_back(u);
      
        ans.push_back(component);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
   
    vector<vector<int>> graph(n);

    for (vector<int> &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
    }

   
    vector<int> disc(n, -1);
    vector<int> low(n, -1);

    stack<int> nodeStack;
    vector<bool> inStack(n, false);

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            
            dfs(graph, i, disc, low, inStack, nodeStack, ans);
        }
    }

   
    return ans;
}
