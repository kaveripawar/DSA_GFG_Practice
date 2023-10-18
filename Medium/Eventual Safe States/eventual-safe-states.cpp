//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> result;
        vector<int> color(V, 0); // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < V; i++) {
            if (dfs(i, adj, color)) {
                result.push_back(i);
            }
        }
        
        return result;
    }

    bool dfs(int node, vector<int> adj[], vector<int>& color) {
        if (color[node] == 2) {
            return true; // This node has been proven safe before.
        }
        if (color[node] == 1) {
            return false; // This node is currently being visited, indicating a cycle.
        }
        
        color[node] = 1; // Mark the node as currently being visited.
        
        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, color)) {
                return false; // If a neighbor is not safe, this node is not safe.
            }
        }
        
        color[node] = 2; // Mark the node as visited and safe.
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends