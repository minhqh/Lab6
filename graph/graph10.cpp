// Some helping functions

int Dijkstra(int** graph, int src, int dst) {
	int n = 6;

    vector<int> dist(n, INT_MAX);

    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minVal = INT_MAX;
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= minVal) {
                minVal = dist[v];
                u = v;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        if (u == dst) return dist[dst];

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist[dst];
	
}
