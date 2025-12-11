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
	
	Adjacency *BFS(int v)
{
    Adjacency *result = new Adjacency();

    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) visited[i] = false;

    list<int> queue;

    visited[v] = true;
    queue.push_back(v);

    while(!queue.empty())
    {
        int current = queue.front();
        queue.pop_front();

        result->push(current);

        int numNeighbors = adj[current].getSize();
        
        for(int i = 0; i < numNeighbors; i++)
        {
            int neighbor = adj[current].getElement(i);

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }

    delete[] visited;

    return result;
}
};