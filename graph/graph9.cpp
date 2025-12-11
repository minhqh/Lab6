class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions
    
    void topologicalSort(){
        stack<int> s;
    vector<bool> visited(V, false);

    struct Sorter {
        static void dfs(int u, vector<bool>& visited, stack<int>& s, Adjacency* adj) {
            visited[u] = true;

            int numNeighbors = adj[u].getSize();
            for (int i = 0; i < numNeighbors; i++) {
                int v = adj[u].getElement(i);
                if (!visited[v]) {
                    dfs(v, visited, s, adj);
                }
            }

            s.push(u);
        }
    };

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            Sorter::dfs(i, visited, s, adj);
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    }
};