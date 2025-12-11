int numberOfFriendGroups(vector<vector<int>>& friends) {
    // STUDENT ANSWER
    int n = friends.size();
    if (n == 0) return 0;

    vector<bool> visited(n, false);
    int groups = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            groups++;
            
            stack<int> s;
            s.push(i);
            visited[i] = true;

            while (!s.empty()) {
                int u = s.top();
                s.pop();
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        s.push(v);
                    }
                }
            }
        }
    }
    
    return groups;
}