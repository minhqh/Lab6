class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        Adjacency *result = new Adjacency();
    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) visited[i] = false;

    list<int> stack;
    stack.push_back(v);

    while(!stack.empty())
    {
        int u = stack.back();
        stack.pop_back();

        if (!visited[u])
        {
            visited[u] = true;
            result->push(u);

            int size = adj[u].getSize();
            for(int i = size - 1; i >= 0; i--)
            {
                int neighbor = adj[u].getElement(i);
                if (!visited[neighbor])
                {
                    stack.push_back(neighbor);
                }
            }
        }
    }
    
    delete[] visited;
    return result;
	}
};