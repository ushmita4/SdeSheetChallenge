/*
    Time Complexity = O(M * log (N))
    Space Complexity = O(N + M)

    Where N is the number of nodes and M is the number of edges.
*/

#include <limits.h>
#include <queue>

vector<pair<pair<int, int>,int>> primsMST(vector<pair<int, int>> *adjList, int n)
{
	// Min priority queue.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// Taking source vertex as 0.
	int src = 0;

	// Create vector for key and intilize as infinite.
	int *weight = new int[n];

	// To store parent arr.
	int *parent = new int[n];

	// To keep track of vertices which allready has been included in mst.
	bool *inMST = new bool[n];
	for (int i = 0; i < n; i++)
	{
		weight[i] = INT_MAX;
		parent[i] = -1;
		inMST[i] = false;
	}
	// Insert source as in priority queue and initialize with 0.
	inMST[src] = true;

	// 0 weight for current source.
	pq.push(make_pair(0, src));

	// Weight from source to source.
	weight[src] = 0;

	while (!pq.empty())
	{
		// The first vertex int pair is the minimum weight vertex ,extract it from priority queue and node name is stored at the second of pair( it has to be done this way to keep the vertices sorted order with respect weight) weight must be first item in pair.
		int u = pq.top().second;
		pq.pop();

		// Include u to in our MST.
		inMST[u] = true;

		// Explore all adjacent of u and if not visited the relax them.
		for (auto x : adjList[u])
		{
			int v = x.first;
			int wt = x.second;

			// If v is not in mst and weight of (u,v) is smaller then the current weight of v.
			if (!inMST[v] && weight[v] > wt)
			{
				// Update weight of v.
				weight[v] = wt;

				// Insert it into the priority queue.
				pq.push(make_pair(weight[v], v));

				parent[v] = u;
			}
		}
	}

	delete[] adjList;

	vector<pair<pair<int, int>, int>> result;

	for (int i = 1; i < n; i++)
	{
		result.push_back({{min(parent[i]+1, i+1),max(parent[i]+1, i+1)}, weight[i]});
	}

	return result;
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
	
	vector<pair<int, int>> *adjList = new vector<pair<int, int>>[n];

	for (int i = 0; i < m; i++)
	{
		adjList[g[i].first.first-1].push_back(make_pair(g[i].first.second-1, g[i].second));
		adjList[g[i].first.second-1].push_back(make_pair(g[i].first.first-1, g[i].second));
	}

	return primsMST(adjList, n);
}
