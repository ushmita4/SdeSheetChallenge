/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

#include <unordered_map>

graphNode *cloneGraphHelper(graphNode *node, unordered_map<graphNode *, graphNode *> &copies)
{
    
    if (node == NULL)
    {
        return NULL;
    }

    
    if (copies.find(node) == copies.end())
    {
        copies[node] = new graphNode(node->data, {});

        
        for (graphNode *neighbour : node->neighbours)
        {
            copies[node]->neighbours.push_back(cloneGraphHelper(neighbour, copies));
        }
    }

    return copies[node];
}

graphNode *cloneGraph(graphNode *node)
{

    unordered_map<graphNode *, graphNode *> copies;

   
    return cloneGraphHelper(node, copies);
}
